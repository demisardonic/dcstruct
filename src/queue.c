#include <stdlib.h>

#include "list.h"
#include "queue.h"

struct queue {
  list_t *list;
};

void queue_create(queue_t **out, void (*free_fun)(void *)){
	queue_t *queue = (queue_t *)calloc(1, sizeof(queue_t));
	list_t *list;
	list_create(&list, free_fun);
	queue->list = list;
	*out = queue;
}

void queue_destroy(queue_t *queue){
	if(queue){
		list_destroy(queue->list);
		free(queue);
	}
}

//info
int queue_size(queue_t *queue){
	return (queue) ? list_size(queue->list) : 0;
}

//adding
void queue_offer(queue_t *queue, void *element){
	if(queue && element)
		list_append(queue->list, element);
}

//removing
void *queue_poll(queue_t *queue){
  void *data = NULL;
  if(queue){
    data = list_head(queue->list);
    list_remove_head(queue->list);
  }
  return data;
}

void queue_clear(queue_t *queue){
	if(queue)
		list_clear(queue->list);
}

//getting
void *queue_peek(queue_t *queue){
	return (queue) ? list_head(queue->list) : NULL;
}
