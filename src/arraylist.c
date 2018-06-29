#include <stdlib.h>

#include "arraylist.h"

struct arraylist {
  void **data;
  int size;
  int max;
};

static void double_size(arraylist_t *list);

void arraylist_create(arraylist_t **out){
	arraylist_t *list = (arraylist_t *) calloc(1, sizeof(arraylist_t));
	list->data = (void **) calloc(10, sizeof(void *));
	list->size = 0;
	list->max = 10;
	*out = list;
}

void arraylist_destroy(arraylist_t *list){
	arraylist_clear(list);
	free(list->data);
	free(list);
}

//info
int arraylist_size(arraylist_t *list){
	return (list) ? list->size : 0;
}

//adding
void arraylist_append(arraylist_t *list, void *element){
	arraylist_add(list, element, list->size);
}

void arraylist_add(arraylist_t *list, void *element, int index){
	if(list && element){
		if(list->size >= list->max)
			double_size(list);
		int temp = list->size;
		
		while(temp > index){
			list->data[temp] = list->data[temp-1];
			temp--;
		}
		list->data[temp] = element;
		list->size++;
	}
}

//removing
void *arraylist_remove(arraylist_t *list, int index){
	void *data = list->data[index];
	while(index < list->size - 1){
		list->data[index] = list->data[index + 1];
		index++;
	}
	list->size--;
	list->data[index] = NULL;
	return data;
}

void arraylist_clear(arraylist_t *list){
	int i;
	for(i = 0; i < list->size; i++){
		list->data[i] = NULL;
	}
	list->size = 0;
}

//getting
void *arraylist_get(arraylist_t *list, int index){
	return list->data[index];
}


void arraylist_foreach(arraylist_t *list, void (*fun)(const void *)){
	int i;
	for(i = 0; i < list->size; i++){
		fun(list->data[i]);
	}
}

static void double_size(arraylist_t *list){
	list->max *= 2;
	void **new_data = (void **) realloc(list->data, sizeof(void *) * list->max);
	list->data = new_data;
}