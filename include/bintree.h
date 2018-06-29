#ifndef _DEMI_BINTREE_H
#define _DEMI_BINTREE_H

typedef struct bintree bintree_t;
typedef struct bintree_node bintree_node_t;

void bintree_create(bintree_t **tree, int (*cmp)(const void *, const void *));
void bintree_destroy(bintree_t *);
int bintree_size(bintree_t *);
void bintree_add(bintree_t *, void *);

#endif
