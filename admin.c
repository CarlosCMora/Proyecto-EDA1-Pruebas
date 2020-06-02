#include "list.h"
#include"load_file.h"
#include "node.h"
#include "admin.h"

void erase_book(list *l,int num){
    int i;
    node *aux = l->head;
    for(i=0;i<num;i++){
        aux= aux->next;
    }
    delete_node(aux,l);
    printf("\nOui\n");
}


int menu_admin(){
    int op;
    printf("Elige una accionn\n\t1)Agregar un libro.\n\t2)Dar de baja un libro\n\t3)Agregar existencias a un libro.\n\t4)Salir\n");
    scanf("%d",&op);
    return op;
}


