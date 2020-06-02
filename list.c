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
	int i=0;
	while(i<l->num){
		l->head = l->head->next;
		delete_node(t,l);
		t = l->head;
	}
	free(l);
	l = NULL;
}

void empty(list *l){
	node *t = l->head;
	while(t!=NULL){
		l->head = l->head->next;
		delete_node(t,l);
		t = l->head;
	}
	l->head = NULL;
}

bool is_empty(list *l){
	if(l->head == NULL) return true;
	return false;
}

int print_lista(list *l){
	if(l->num==0){
		printf("La lista esta vacia.\n");
		return 0;
	}
	int i;
	node *nodo=l->head;
	for(i=0; i<l->num; i++){
		if(nodo->data.Formato == 0){
            printf("Titulo %s| Autor %s| Editorial %s| ISBN %s| Formato Tapa blanda| Existencia %d| Precio %f\n", nodo->data.title, nodo->data.autor, nodo->data.editorial, nodo->data.ISBN,nodo->data.existencia,nodo->data.precio);
        }
        else{
            printf("Titulo %s| Autor %s| Editorial %s| ISBN %s| Formato Tapa dura| Existencia %d| Precio %f\n", nodo->data.title, nodo->data.autor, nodo->data.editorial, nodo->data.ISBN,nodo->data.existencia,nodo->data.precio);
        }
		nodo = nodo->next;
		printf("%d\n", i);
	}
	return 0;
}