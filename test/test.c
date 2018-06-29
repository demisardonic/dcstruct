#include <stdio.h>

#include "arraylist.h"
#include "bintree.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

int int_compare(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}
void print(const void *a){
	printf("%d\n", *(int *)a);
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
  
  int a = 0;
  int b = 1;
  int c = 2;
  int d = 3;
  int e = 4;
  bintree_t *tree;
  bintree_create(&tree, int_compare);
  bintree_add(tree, &e);
  bintree_add(tree, &d);
  bintree_add(tree, &c);
  bintree_add(tree, &b);
  bintree_add(tree, &a);
    
  bintree_iter_t *iter;
  bintree_iter_create(tree, &iter);
  
  while(bintree_iter_has_next(iter)){
	  printf("%d\n", *(int *)bintree_iter_next(iter));
  }
  
  bintree_iter_destroy(iter);
  
  bintree_destroy(tree);
}
