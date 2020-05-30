#include "list.h"
#include "node.h"

list *create_list(){
	list *l = (list*)malloc(sizeof(list));
	l->head = NULL;
	l->tail = NULL;
	l->num=0;
	return l;
}

void delete_list(list *l){
	node *t = l->head;
	while(t!=NULL){
		l->head = l->head->next;
		delete_node(t);
		t = l->head;
	}
	free(l);
	l = NULL;
}

void empty(list *l){
	node *t = l->head;
	while(t!=NULL){
		l->head = l->head->next;
		delete_node(t);
		t = l->head;
	}
	l->head = NULL;
}

bool is_empty(list *l){
	if(l->head == NULL) return true;
	return false;
}

void print_list(list *l){
	lis
	if(l->num==0){
		printf("La lista esta vacia.\n");
	}
	for()
}