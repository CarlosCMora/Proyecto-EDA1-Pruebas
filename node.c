#include "node.h"

node *create_node(Data d,int x){
	node *n = (node*)malloc(sizeof(node));
	n->next = NULL;
	n->data = d;
	n->numero =x;
	return n;
}

void delete_node(node *n){
	free(n);
	n = NULL;
}