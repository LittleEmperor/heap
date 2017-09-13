/* ************************************************************************
 *       Filename:  heap.h
 *    Description:  
 *        Version:  1.0
 *        Created:  09/13/2017 10:55:17 AM
 *       Revision:  none
 *       Compiler:  gcc
 *         Author:  YOUR NAME (), 
 *        Company:  
 * ************************************************************************/

#ifndef __HEAP_H__
#define __HEAP_H__

void *heap_init(unsigned heap_size);
void heap_fini(void *heap);

unsigned heap_pushnew(void *heap_ctx, unsigned new_elem);
unsigned heap_popmax(void *heap_ctx);

unsigned heap_getmax(void *heap_ctx);
unsigned heap_getsize(void *heap_ctx);
unsigned heap_getcount(void *heap_ctx);

#endif
