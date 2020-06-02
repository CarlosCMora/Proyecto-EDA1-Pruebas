#include"list.h"
#include"node.h"
#include"load_file.h"
#include "admin.h"
#include"funciones.h"


int main(int arrgc, char *argv[]){
    if(arrgc<2){
        printf("Faltan valores.\n");
        return -1;
    }
    else if(arrgc>2){
        printf("Hay mÃ¡s valores de los necesarios.\n");
        return -1;
    }
    FILE *text;
    text=NULL;
    text = fopen(argv[1], "r");
    if(text == NULL ) {
        printf("No fue posible abrir el archivo.\n");
        return -1;
    }
    int i,j,k;
    int mainmenu=0,sub_menu=0; 
    list *lista;
    lista = create_list();   
    lista = load_file(lista, text);
    int *busqueda, auxbusqueda;
    char cbusqueda[50];
    while(mainmenu!=3){
        mainmenu = main_menu();
        switch(mainmenu){
            case 1:
                //Admin
                while(sub_menu!=4){
                    sub_menu = menu_admin();
                    switch(sub_menu){
                        case 1:
                            //Agregar un libro
                            break;
                        case 2:
                            //Dar de baja un libro
                            busqueda=search(lista);
                            print_index(lista,busqueda);
                            printf("Escriba los indices por borrar\n");
                            scanf("%s",cbusqueda);
                            for(i=0; i<longitud(cbusqueda); i++){
                                busqueda[i+1] = busqueda[cbusqueda[i]];
                            }
                            busqueda = (int*)realloc(busqueda,sizeof(int)*(i+1));
                            busqueda[0]=i+1;
                            for(i = 1; i<= busqueda[0]; i++){
                                auxbusqueda = busqueda[i];
                                erase_book(lista,auxbusqueda);
                                print_lista(lista);
                            }
                            printf("Book has been eliminated succesfully\n");
                        case 3:
                            //Agregar existencias
                            break;
                        case 4:
                            //Salir
                            printf("Hasta pronto\n");
                            break;
                    }
                }
                sub_menu = 0;
                break;
            case 2:
                //Cliente
                break;
            case 3:
                //Salir
                printf("Gracias por visitar libreria X\n");
                break;
        }
    }
    
    
    delete_list(lista); 
    fclose(text);
    return 0; 
}