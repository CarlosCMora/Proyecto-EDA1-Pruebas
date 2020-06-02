#ifndef LOAD_FILE_H
#define LOAD_FILE_H

#include"list.h"


void printArray(Data A[], int size);
int longitud(char *cadena);
int convertir_entero(char *cadena);
list *load_file(list *l, FILE *texto);

#endif