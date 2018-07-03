#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int int_compare(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

void print(const void *a){
  printf("%s\n", (char *) a);
}

char *make(const char *data){
  char *string = (char *) calloc(strlen(data) + 1, sizeof(*data));
  strcpy(string, data);
  return string;
}

void main(){
  list_t *list;
  list_create(&list, &free);
  
  list_append(list, make("ayy"));
  
  list_destroy(list);
}
