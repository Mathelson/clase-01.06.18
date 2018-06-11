/*MODIFICAMOS EL ARRAY QUE CRECIA EN FORMA DINAMICA Y GUARDABA STRUCT DEL TIPO PERSON
MUDARLOS A UN ARCHIVO TIPO BIBLIOTECA
**/

/**AGREGAMOS EL PODER BORRAR UN ITEM */
/*PODIAMOS AGREGAR PUNTEROS PERO NO PODIAMOS ELIMINARLOS*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "People.h"



int main(int argc, char *argv[])
{

    PeopleList* pl = list_initPeopleList();

    Person* p = list_newPerson();

    while(list_enterPerson(p)==0)
    {/**LO AGREGAMOS A LA LISTA*/
        /*TAMBIEN REDIMENSIONAMOS EL ARRAY*/
        list_addPerson(pl,p);//people list como primer argumento

        p = list_newPerson();
    }
    free(p);

    list_remove(pl,2);//PRUEBA BORRANDO DE POSICION 2
                    //ELIMINA LA POSICION Nº2 DE LA LISTA

    // luego los imprimirmos
    int i;
    /**list_getsize REEMPLAZA A INDEX*/
    for(i=0; i<list_getSize(pl);i++)
        list_printPerson(list_get(pl,i));/**LIST_GET DEVUELVE EL PUNTERO DEL ITEM QUE ESTA EN EL ARRAY*/
    //______________________

    /**LIBERAMOS TODO*/
    for(i=0; i<list_getSize(pl);i++)
        free(list_get(pl,i));

    list_free(pl);//LIBERA PEOPLE
    //________________

   return 0;
}

