#ifndef _DEMI_BINTREE_H
#define _DEMI_BINTREE_H

typedef struct bintree bintree_t;
typedef struct bintree_node bintree_node_t;

void bintree_create(bintree_t **, void (*)(void *), int (*)(const void *, const void *));

void bintree_destroy(bintree_t *);

int bintree_size(bintree_t *);

void bintree_add(bintree_t *, void *);

void bintree_foreach(bintree_t *, void (*)(const void *));

typedef struct bintree_iter bintree_iter_t;

void bintree_iter_create(bintree_t *, bintree_iter_t **);
void bintree_iter_destroy(bintree_iter_t *);
int bintree_iter_has_next(bintree_iter_t *);
void *bintree_iter_next(bintree_iter_t *);


#endif
