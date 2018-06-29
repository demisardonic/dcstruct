#ifndef _DEMI_QUEUE_H
#define _DEMI_QUEUE_H

#include "list.h"

typedef struct queue queue_t;

void queue_create(queue_t **);
void queue_destroy(queue_t *);

//info
int queue_size(queue_t *);

//adding
void queue_offer(queue_t *, void *);

//removing
void *queue_poll(queue_t *);
void queue_clear(queue_t *);

//getting
void *queue_peek(queue_t *);

#endif
