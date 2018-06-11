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

/**struct S_Person
{
       char name[20];
       int age;
};
typedef struct S_Person Person;*/

//int enterPerson(Person* p);
//void printPerson(Person* p);

int main(int argc, char *argv[])
{






    list_initPeopleList();/**INICIALIZAMOS LAS VARIABLES GLOBALES*/
/**CREAMOS UNA ESTRUCTURA DEL TIPO PERSONA*/
    Person* p = list_newPerson();
    /** primero pedimos los datos*/
    while(list_enterPerson(p)==0)
    {/**LO AGREGAMOS A LA LISTA*/
        /*TAMBIEN REDIMENSIONAMOS EL ARRAY*/
        list_addPerson(p);
        /**NUEVA ESTRUCTURA A SER CARGADA*/
        /*VERIFICAMOS QUE HALLA LUGAR*/
        p = list_newPerson();
    }
    free(p);

    list_remove(2);//PRUEBA BORRANDO DE POSICION 2
                    //ELIMINA LA POSICION Nº2 DE LA LISTA

    // luego los imprimirmos
    int i;
    /**list_getsize REEMPLAZA A INDEX*/
    for(i=0; i<list_getSize();i++)
        list_printPerson(list_get(i));/**LIST_GET DEVUELVE EL PUNTERO DEL ITEM QUE ESTA EN EL ARRAY*/
    //______________________

    /**LIBERAMOS TODO*/
    for(i=0; i<list_getSize();i++)
        free(list_get(i));

    list_free();//LIBERA PEOPLE
    //________________

   return 0;
}

