#include <stdlib.h>

#include "list.h"
#include "stack.h"

struct stack {
  list_t *list;
};

void stack_create(stack_t **out){
	stack_t *stack = (stack_t *)calloc(1, sizeof(stack_t));
	list_t *list;
	list_create(&list);
	stack->list = list;
	*out = stack;
}

void stack_destroy(stack_t *stack){
	if(stack){
		list_destroy(stack->list);
		free(stack);
	}
}

//info
int stack_size(stack_t *stack){
	return (stack) ? list_size(stack->list) : 0;
}

//adding
void stack_push(stack_t *stack, void *element){
	if(stack && element)
		list_prepend(stack->list, element);
}

//removing
void *stack_pop(stack_t *stack){
	return (stack) ? list_remove_head(stack->list) : NULL;
}

void stack_clear(stack_t *stack){
	if(stack)
		list_clear(stack->list);
}

//getting
void *stack_peek(stack_t *stack){
	return (stack) ? list_head(stack->list) : NULL;
}