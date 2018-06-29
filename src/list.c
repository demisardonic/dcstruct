#include <stdlib.h>

#include "list.h"

struct list {
  list_node_t *head;
  list_node_t *tail;
  int size;
};

struct list_node{
  void *value;
  list_node_t *next;
};

static list_node_t *get_node(list_t *list, int index);

void list_create(list_t **out){
  list_t *list = (list_t *)calloc(1, sizeof(list_t));
  *out = list;
}

void list_destroy(list_t *list){
	if(list){
		list_clear(list);
		free(list);
	}
}

int list_size(list_t *list){
	return (list) ? list->size : 0;
}

void list_append(list_t *list, void *element){
	if(list)
		list_add(list, element, list->size);
}

void list_prepend(list_t *list, void *element){
	list_add(list, element, 0);
}

void list_add(list_t *list, void *element, int index){
	if(list && element && index >= 0 && index <= list->size){
		list_node_t *node = (list_node_t *) calloc(1, sizeof(list_node_t));
		node->value = element;
		if(index == 0){
			node->next = list->head;
			list->head = node;
			if(list->size == 0)
				list->tail = node;
		}else{
			list_node_t *prev = get_node(list, index - 1);
			node->next = prev->next;
			prev->next = node;
			if(index == list->size)
				list->tail = node;
		}
		list->size++;
	}
}

void *list_remove_head(list_t *list){
	if(list){
		void *data = NULL;
		if(list->head){
			data = list->head->value;
			list_node_t *next = list->head->next;
			free(list->head);
			list->head = next;
			list->size--;
		}
		return data;
	}
	return NULL;
}

void *list_remove_tail(list_t *list){
	return (list) ? list_remove_element(list, list->size - 1) : NULL;
}

void *list_remove_element(list_t *list, int index){
	if(index < 0 || index >= list->size || list->head == NULL) 
		return NULL;
	if(index == 0)
		return list_remove_head(list);
	list_node_t *prev = get_node(list, index - 1);
	list_node_t *next = prev->next->next;
	if(index == list->size - 1)
		list->tail = prev;
	void* data = prev->next->value;
	free(prev->next);
	prev->next = next;
	list->size--;
	return data;
}

void list_clear(list_t *list){
	while(list_remove_head(list));
}

void *list_head(list_t *list){
	return (list && list->head) ? list->head->value : NULL;
}

void *list_tail(list_t *list){
	return (list && list->tail) ? list->tail->value : NULL;
}

void *list_element(list_t *list, int index){
	return get_node(list, index)->value;
}

static list_node_t *get_node(list_t *list, int index){
	list_node_t *node = NULL;
	if(list && index >= 0 && index < list->size){
		node = list->head;
		while(index > 0 && node){
			node = node->next;
			index--;
		}
	}
	return node;
}