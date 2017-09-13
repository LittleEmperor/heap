/* ************************************************************************
 *       Filename:  heap.c
 *    Description:  
 *        Version:  1.0
 *        Created:  09/13/2017 10:54:48 AM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#include <stdlib.h>

struct heap {
	unsigned *data;
	unsigned size;
	unsigned count;
};

static void __fixup(struct heap *h, unsigned idx)
{
	while(idx > 0){
		unsigned idx_p = (idx-1)/2;
		if(h->data[idx] > h->data[idx_p]){
			unsigned tmp = h->data[idx];
			h->data[idx] = h->data[idx_p];
			h->data[idx_p] = tmp;
		}
		idx = idx_p;
	}
}

static void __fixdown(struct heap *h, unsigned idx)
{
	while(2*idx+1 < h->count){
		unsigned tar = 2*idx+1;
		// if he has right child AND left < right
		if(tar + 1 < h->count && h->data[tar] < h->data[tar + 1]){ 
			tar += 1;
		}
		if(h->data[idx] >= h->data[tar]){
			break;
		}
		unsigned tmp = h->data[tar];
		h->data[tar] = h->data[idx];
		h->data[idx] = tmp;
		idx = tar;
	}
}

#if 0
static void heap_print(void *heap_ctx)
{
	struct heap *h = heap_ctx;
	unsigned i;
	for(i=0; i<h->count; i++){
		printf("%u ", h->data[i]);
	}
	printf("\n");
}
#endif

unsigned heap_getsize(void *heap_ctx)
{
	struct heap *h = heap_ctx;
	return h->size;
}

unsigned heap_getcount(void *heap_ctx)
{
	struct heap *h = heap_ctx;
	return h->count;
}

unsigned heap_pushnew(void *heap_ctx, unsigned new_elem)
{
	struct heap *h = heap_ctx;
	if(h->count >= h->size){
		return 0;
	}
	h->data[h->count] = new_elem;
	__fixup(h, h->count);
	h->count += 1;

	return 1;
}

unsigned heap_getmax(void *heap_ctx)
{
	struct heap *h = heap_ctx;
	if(0 == h->count){
		return 0;
	}
	return h->data[0];
}

unsigned heap_popmax(void *heap_ctx)
{
	struct heap *h = heap_ctx;
	if(0 == h->count){
		return 0;
	}
	unsigned max = h->data[0];
	h->data[0] = h->data[h->count-1];
	h->count -= 1;
	__fixdown(h, 0);

	return max;
}

void *heap_init(unsigned heap_size)
{
	struct heap *heap = (struct heap *)malloc( sizeof(struct heap) );
	if ( NULL == heap ) {
		return NULL;
	}
	heap->data = (unsigned *)malloc( sizeof(heap->data[0]) * heap_size);
	if (NULL == heap->data) {
		return NULL;
	}
	heap->size = heap_size;
	heap->count = 0;

	return heap;
}

void heap_fini(void *heap)
{
	struct heap *h = heap;
	if(NULL == h){
		return ;
	}
	free(h->data);
	free(h);
}

#if 0
int main(int argc, char *argv[])
{
	void *heap = heap_init(100);
	unsigned i;
	for(i=0; i<10; i++){
		heap_pushnew(heap, i);
		//heap_print(heap);
	}
	for(i=0; i<10; i++){
		printf("max: %u\n", heap_popmax(heap));
		heap_print(heap);
	}
	heap_fini(heap);

	return 0;
}
#endif

