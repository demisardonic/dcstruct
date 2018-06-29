#include <stdlib.h>
#include "bintree.h"

struct bintree {
  bintree_node_t *head;
  int size;
  
  int (*cmp)(const void *, const void *);
};

struct bintree_node{
  void *value;
  bintree_node_t *left;
  bintree_node_t *right;
};

void bintree_create(bintree_t **out, int (*cmp)(const void *, const void *)){
	bintree_t *tree = (bintree_t *) calloc(1, sizeof(bintree_t));
	tree->cmp = cmp;
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
	tree->size++;
}