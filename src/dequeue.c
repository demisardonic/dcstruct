#include <stdlib.h>

#include "list.h"
#include "dequeue.h"

struct dequeue {
  list_t *list;
};

void dequeue_create(dequeue_t **out){
	dequeue_t *dequeue = (dequeue_t *)calloc(1, sizeof(dequeue_t));
	list_t *list;
	list_create(&list);
	dequeue->list = list;
	*out = dequeue;
}

void dequeue_destroy(dequeue_t *dequeue){
	if(dequeue){
		list_destroy(dequeue->list);
		free(dequeue);
	}
}

//info
int dequeue_size(dequeue_t *dequeue){
	return (dequeue) ? list_size(dequeue->list) : 0;
}

//adding
void dequeue_offer_first(dequeue_t *dequeue, void *element){
	if(dequeue && element)
		list_prepend(dequeue->list, element);
}

void dequeue_offer_last(dequeue_t *dequeue, void *element){
	if(dequeue && element)
		list_append(dequeue->list, element);
}

//removing
void *dequeue_poll_first(dequeue_t *dequeue){
	return (dequeue) ? list_remove_head(dequeue->list) : NULL;
}

void *dequeue_poll_last(dequeue_t *dequeue){
	return (dequeue) ? list_remove_tail(dequeue->list) : NULL;
}

void dequeue_clear(dequeue_t *dequeue){
	if(dequeue)
		list_clear(dequeue->list);
}

//getting
void *dequeue_peek_first(dequeue_t *dequeue){
	return (dequeue) ? list_head(dequeue->list) : NULL;
}

void *dequeue_peek_last(dequeue_t *dequeue){
	return (dequeue) ? list_tail(dequeue->list) : NULL;
}