#ifndef LIST_H
#define LIST_H

#include "node.h"


typedef struct _list{
	node *head;
	node *tail;
	int num;
} list;


list *create_list();
void delete_list(list *l);
void empty(list *l);
bool is_empty(list *l);
int print_lista(list *l);
node *create_node(Data d);
void delete_node(node *n,list *l);
#endif