#include <stdio.h>
#include <stdlib.h>

#include "bintree.h"
#include "stack.h"

struct bintree {
  bintree_node_t *head;
  int size;
  void (*free)(void *);
  int (*cmp)(const void *, const void *);
};

struct bintree_node{
  void *value;
  bintree_node_t *parent;
  bintree_node_t *left;
  bintree_node_t *right;
};

void bintree_create(bintree_t **out, void (*free_fun)(void *), int (*cmp)(const void *, const void *)){
  bintree_t *tree = (bintree_t *) calloc(1, sizeof(bintree_t));
  tree->cmp = cmp;
  tree->free = free_fun;
  *out = tree;
}

void bintree_destroy(bintree_t *tree){
	free(tree);
}

int bintree_size(bintree_t *tree){
	return tree->size;
}

void bintree_add(bintree_t *tree, void *element){
	bintree_node_t *new_node = (bintree_node_t *) calloc(1, sizeof(bintree_node_t));
	new_node->value = element;
	if(tree->size == 0){
		tree->head = new_node;
		tree->size++;
		return;
	}
	bintree_node_t *node = tree->head;
	bintree_node_t *parent = NULL;
	int c = 0;
	while(node){
		c = tree->cmp(element, node->value);
		if(c < 0){
			parent = node;
			node = node->left;
		}else{
			parent = node;
			node = node->right;
		}
	}
	if(c < 0)
		parent->left = new_node;
	else
		parent->right = new_node;
	new_node->parent = parent;
	tree->size++;

}

void bintree_foreach(bintree_t *tree, void (*fun)(const void *)){
	bintree_node_t *cur = tree->head;
	stack_t *stack;
	stack_create(&stack, NULL);
	while(stack_size(stack) > 0 || cur){
		if(cur){
			stack_push(stack, cur);
			cur = cur->left;
		}else{
			cur = (bintree_node_t *) stack_pop(stack);
			fun(cur->value);
			cur = cur->right;
		}
	}
}

struct bintree_iter{
	bintree_t *tree;
	bintree_node_t *cur;
};

void bintree_iter_create(bintree_t *tree, bintree_iter_t **out){
	bintree_iter_t *iter = (bintree_iter_t *) calloc(1, sizeof(bintree_iter_t));
	iter->tree = tree;
	iter->cur = tree->head;
	while(iter->cur->left){
		iter->cur = iter->cur->left;
	}
	*out = iter;
}

void bintree_iter_destroy(bintree_iter_t *iter){
	free(iter);
}

int bintree_iter_has_next(bintree_iter_t *iter){
	return iter->cur ? 1 : 0;
}

void * bintree_iter_next(bintree_iter_t *iter){
	bintree_node_t *node = iter->cur;
	if(!bintree_iter_has_next(iter))
		return NULL;
	if(iter->cur->right){
		iter->cur = iter->cur->right;
		while(iter->cur->left)
			iter->cur = iter->cur->left;
		return node->value;
	}
	while(1){
		if(!iter->cur->parent){
			iter->cur = NULL;
			return node->value;
		}
		if(iter->cur->parent->left == iter->cur){
			iter->cur = iter->cur->parent;
			return node->value;
		}
		iter->cur = iter->cur->parent;
	}
}
