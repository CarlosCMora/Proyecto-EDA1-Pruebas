#include "node.h"
#include"list.h"

node *create_node(Data d){
	node *n = (node*)malloc(sizeof(node));
	n->next = NULL;
	n->data = d;
	
	return n;
}

void delete_node(node *n,list *l){
	node *aux;
	if(n==l->head){
		l->head = l->head->next;
	}
	else if(n==l->tail){
		l->tail = l->tail->last;
	}
	aux = n->last;
	n->last->next = n->next;
	n->next->last = aux;
	
	free(n);
	n = NULL;
	l->num-=1;
}