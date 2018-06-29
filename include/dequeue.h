#ifndef _DEMI_DEQUEUE_H
#define _DEMI_DEQUEUE_H

#include "list.h"

typedef struct dequeue dequeue_t;

void dequeue_create(dequeue_t **);
void dequeue_destroy(dequeue_t *);

//info
int dequeue_size(dequeue_t *);

//adding
void dequeue_offer_first(dequeue_t *, void *);
void dequeue_offer_last(dequeue_t *, void *);

//removing
void *dequeue_poll_first(dequeue_t *);
void *dequeue_poll_last(dequeue_t *);
void dequeue_clear(dequeue_t *);

//getting
void *dequeue_peek_first(dequeue_t *);
void *dequeue_peek_last(dequeue_t *);

#endif
