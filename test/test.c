#include <stdio.h>

#include "arraylist.h"
#include "bintree.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

int int_compare(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

void main(){
  list_t *list;
  list_create(&list);
  
  list_append(list, "test");
  list_append(list, "test2");
  list_append(list, "test3");
  list_append(list, "test4");
  list_remove_element(list, 3);
  list_remove_tail(list);
  
  printf("%s\n", list_tail(list));
  
  list_remove_element(list, 2);
  
  list_clear(list);
  
  list_destroy(list);
  
  stack_t *stack;
  stack_create(&stack);
  stack_push(stack, "hello");
  stack_push(stack, "hello2");
  stack_peek(stack);
  stack_pop(stack);
  stack_destroy(stack);
  
  queue_t *queue;
  queue_create(&queue);
  queue_offer(queue, "hello");
  queue_offer(queue, "hello2");
  queue_peek(queue);
  queue_poll(queue);
  queue_destroy(queue);
  
  arraylist_t *arraylist;
  arraylist_create(&arraylist);
  arraylist_destroy(arraylist);
  
  bintree_t *tree;
  bintree_create(&tree, int_compare);
  bintree_destroy(tree);
}
