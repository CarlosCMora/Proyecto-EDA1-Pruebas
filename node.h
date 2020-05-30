#ifndef NODE_H
#define NODE_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <math.h>


typedef struct _Data Data;
struct _Data{
	char title[50];
    char autor[50];
    char editorial[50];
    char ISBN[13];
    int Formato;
    int existencia;
    float precio;
};
typedef struct _node node;

struct _node{
	Data data;
	int numero;
	node *next;
    node *last;
};

node *create_node(Data d,int x);
void delete_node(node *n);

#endif


// t´ıtulo. (b) Autor. (c) Editorial. (d) ISBN (e) Formato (Tapa blanda, Tapa dura) (f) Cantidad en existencia (g) Precio 