#ifndef _DEMI_ARRAYLIST_H
#define _DEMI_ARRAYLLIST_H

typedef struct arraylist arraylist_t;
typedef struct arraylist_node arraylist_node_t;

void arraylist_create(arraylist_t **);
void arraylist_destroy(arraylist_t *);

//info
int arraylist_size(arraylist_t *);

//adding
void arraylist_append(arraylist_t *, void *);
void arraylist_add(arraylist_t *, void *, int);

//removing
void *arraylist_remove(arraylist_t *, int);
void arraylist_clear(arraylist_t *);

//getting
void *arraylist_get(arraylist_t *, int);

void arraylist_foreach(arraylist_t *, void (*)(const void *));

#endif
