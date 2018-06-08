/******************************************************************
* Programa: Ejemplo Clase 22
*
* Objetivo:
    Cambiar el ejercicio anterior para no crear un array de personas sino de punteros a estructuras "Person"
*
* Aspectos a destacar:
*
*   Array de punteros a estructuras creadas en forma din�mica
*
* Version: 0.1 del 06 enero de 2016
* Autor: Ernesto Gigliotti
*
********************************************************************/

/*MODIFICAMOS EL ARRAY QUE CRECIA EN FORMA DINAMICA Y GUARDABA STRUCT DEL TIPO PERSON
MUDARLOS A UN ARCHIVO TIPO BIBLIOTECA
**/

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

    Person* p = list_newPerson(); // creamos una estructura Person de forma din�mica
    // primero pedimos los datos
    while(list_enterPerson(p)==0) // guardamos los datos imgresados en la struct "p"
    {/**LO AGREGAMOS A LA LISTA*/
        //TAMBIEN REDIMENSIONAMOS EL ARRAY
        list_addPerson(p); // copiamos el puntero a la estrcutura cargada "p" a una posicion del array de punteros.
        /**NUEVA ESTRUCTURA A SER CARGADA*/
        p = list_newPerson(); // creamos la siguiente estructura Person de forma din�mica
    }
    free(p); // liberamos esta struct porque no se guardo en el array (cuando ingrese salir)

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




    //----------------------------------------------------------------------------------------------------
   /** int listSize=2;
    //Person* people = (Person*)malloc(sizeof(Person)*listSize); // En el ejemplo anterior, cada item del array era una estructura
    Person** people = (Person**)malloc(sizeof(Person*)*listSize); // Ahora cada item del array es un puntero a una estructura

    //Person p;
    int index=0;
    Person* p = (Person*)malloc(sizeof(Person)); // creamos una estructura Person de forma din�mica
    // primero pedimos los datos
    while(enterPerson(p)==0) // guardamos los datos imgresados en la struct "p"
    {
       people[index]=p; // copiamos el puntero a la estrcutura cargada "p" a una posicion del array de punteros.
       index++;

       // si no hay mas lugar, pedimos m�s memoria para hacer un array m�s grande
       if(index>=listSize)
       {
          printf("no hay mas lugar, redefinimos el array\r\n");
          listSize+=2; // agregamos dos mas
          //people = (Person*)realloc(people,sizeof(Person)*listSize);
          people = (Person**)realloc(people,sizeof(Person*)*listSize);
       }

        p = (Person*)malloc(sizeof(Person)); // creamos la siguiente estructura Person de forma din�mica
    }
    free(p); // liberamos esta struct porque no se guardo en el array (cuando ingrese salir)

    // luego los imprimirmos
    int i;
    for(i=0; i<index;i++)
        printPerson(people[i]);
    //______________________

    // liberamos todo
    for(i=0; i<index;i++)
        free(people[i]);

    free(people);
    //________________
*/
   return 0;
}
/**
/** \brief Pide al usuario los datos de una persona y los almacena en la struct
 * \param Person* p puntero a tipo Person donde se guardar�n los datos
 * \return 1: si se ingresa salir, 0 de lo contrario
 */
//int enterPerson(Person* p)
//{
    /** printf("Ingrese el nombre:");
     scanf("%s",p->name);
     if(strncmp(p->name,"salir",5)==0)
         return 1;
     printf("Ingrese la edad:");
     scanf("%d",&(p->age));
     return 0;*/
//}


/** \brief Imprime los datos de una persona
 * \param Person* p puntero a tipo Person donde se guardar�n los datos
 * \return void
 */
//void printPerson(Person* p)
//{
  //  printf("Nombre:\t%s \tedad:%d\r\n",p->name,p->age);
//}
