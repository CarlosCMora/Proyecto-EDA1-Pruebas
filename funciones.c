#include "list.h"
#include"load_file.h"
#include "node.h"
#include "funciones.h"
int main_menu(){
    int op;
    printf("Elige la opcion para ingresar\n\t1)Administrador\n\t2)Cliente\n\t3)Salir\n");
    scanf("%d",&op);
    return op;
}


int *search(list *l){
    char search[50];
    printf("Escriba el titulo, nombre, ISBN o editorial del libro\n");
    scanf("%s",search);
    int *num=(int*)malloc(sizeof(int));
    int i,j=0;
    node *n=l->head;
    num[0] = j;
    for(i=0;i<l->num; i++){
        if(strcmp(search, n->data.title) == 0 || strcmp(search, n->data.autor) == 0 || strcmp(search, n->data.editorial)== 0 || strcmp(search, n->data.ISBN) == 0){
            num = (int*)realloc(num,(sizeof(int)*j+2));
            num[j+1] = i;
            j++;
            num[0] = j;
        }
        n = n->next;
    }
    return num;
}

void print_index(list *l, int *index){
    int i,j;
    node *nodo=l->head;
    for(i = 1; i<= index[0]; i++){
        nodo=l->head;
        for(j = 0; j<l->num;j++){
            if(j == (index[i])){
                if(nodo->data.Formato == 0){
                    printf("Titulo %s| Autor %s| Editorial %s| ISBN %s| Formato Tapa blanda| Existencia %d| Precio %f\n", nodo->data.title, nodo->data.autor, nodo->data.editorial, nodo->data.ISBN,nodo->data.existencia,nodo->data.precio);
                }
                else{
                    printf("Titulo %s| Autor %s| Editorial %s| ISBN %s| Formato Tapa dura| Existencia %d| Precio %f\n", nodo->data.title, nodo->data.autor, nodo->data.editorial, nodo->data.ISBN,nodo->data.existencia,nodo->data.precio);
                }
            }
            nodo = nodo->next;
        }
    }
}