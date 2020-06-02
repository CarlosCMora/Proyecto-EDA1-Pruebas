#include "list.h"
#include"load_file.h"
#include "node.h"

void printArray(Data A[], int size){ 
    int i; 
    for (i=0; i < size; i++){ 
        if(A[i].Formato == 0){
            printf("Titulo %s| Autor %s| Editorial %s| ISBN %s| Formato Tapa blanda| Existencia %d| Precio %f\n", A[i].title, A[i].autor, A[i].editorial, A[i].ISBN,A[i].existencia,A[i].precio);
        }
        else{
            printf("Titulo %s| Autor %s| Editorial %s| ISBN %s| Formato Tapa dura| Existencia %d| Precio %f\n", A[i].title, A[i].autor, A[i].editorial, A[i].ISBN,A[i].existencia,A[i].precio);
        }
    }
    
} 

int longitud(char *cadena){
    int valor = 0;
    int i;

    for(i=0; cadena[ i ]!='\0'; i++)
        valor++;

    return valor;
}

int convertir_entero(char *cadena){
    int cant=20;
    int *potencias;
    potencias = (int*)malloc(sizeof(int)*cant);
    int i;
    for(i=0;i<cant;i++){
        potencias[i] = pow(10,i);
    }
    int valor = 0;
    int lon = longitud(cadena);

    for(i=lon-1; i>=0; i--)
      valor += (cadena[ i ]-'0') * potencias[ lon-i-1 ];

    return valor;
}


list *load_file(list *l, FILE *texto){
    int i=0,j=0;
    int n;
    Data arr;
    char str1[50], str2[50], str7[50],str3[50];
    char str4[50], str5[50], str6[50];
    n = fgetc(texto)-'0';
    l->head = create_node(arr);
    node *nodo = l->head, *nodo_0 = l->head;
    while(!(feof(texto))){
        fscanf(texto, "%s %s %s %s %s %s %s", str1, str2, str3,str4,str5,str6,str7);
        strcpy(nodo->data.title, str1);
        strcpy(nodo->data.autor, str2);
        strcpy(nodo->data.editorial, str3);
        strcpy(nodo->data.ISBN, str4);
        nodo->data.Formato = atoll(str5);
        nodo->data.existencia = convertir_entero(str6);
        nodo->data.precio = atof(str7);
        i++;
        l->num = i-1;
        nodo->next = create_node(arr);
        nodo->next->last = nodo;
        nodo_0->last = nodo->next;
        nodo->next->next = nodo_0;
        nodo = nodo->next;
        
    }
    printf("%d",l->num);    
    printf("\tArreglo: \n"); 
    print_lista(l); 
    return l;
}