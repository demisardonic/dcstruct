#ifndef _DEMI_STACK_H
#define _DEMI_STACK_H

#include "list.h"

typedef struct stack stack_t;

void stack_create(stack_t **, void (*)(void *));
void stack_destroy(stack_t *);

//info
int stack_size(stack_t *);

//adding
void stack_push(stack_t *, void *);

//removing
void *stack_pop(stack_t *);
void stack_clear(stack_t *);

//getting
void *stack_peek(stack_t *);

#endif
