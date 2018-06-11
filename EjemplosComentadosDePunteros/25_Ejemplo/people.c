#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"

/** \brief Inicializa el array de estructuras Person
 * \return void
 */
 PeopleList* list_initPeopleList(void)//
 {
     PeopleList* pl = (PeopleList*)malloc(sizeof(PeopleList));//creamos una struct del tipo peopleList
    pl->index=0;
    pl->listSize=2;
    pl->people = (Person**)malloc(sizeof(Person*)*pl->listSize);

    return pl;
 }
 /**NUEVA ESTRUCTURA DEL TIPO PERSONA*/
 /**PEDIMOS EN FORMA DINAMICA EL ESPACIO PARA CREAR UNA ESTRUCTURA DE ESTE TIPO*/
 /** \brief crea una estructura del tipo persona en forma dinamica
  *
  * \param
  * \param
  * \return devuelve un puntero a la estructura creada
  *
  */

  Person* list_newPerson(void)//
  {
    Person* p = (Person*)malloc(sizeof(Person));//Creamos en forma dinamica una estructura de este tipo
     /**  Person* p = (Person*)malloc(sizeof(Person));*/
                                            //buscams espacio en memoria
    return p;
  }


/**MOSTRAR PERSONA*/
/** \brief Imprime los datos de una persona
 * \param Person* p puntero a tipo Person donde se guardarán los datos
 * \return void
 */
void list_printPerson(Person* p)//
{
    printf("Nombre:\t%s \tedad:%d\r\n",p->name,p->age);
}


/**INGRESAR PERSONA*/
/** \brief Pide al usuario los datos de una persona y los almacena en la struct
 * \param Person* p puntero a tipo Person donde se guardarán los datos
 * \return 1: si se ingresa salir, 0 de lo contrario
 */
int list_enterPerson(Person* p)//
{
     printf("Ingrese el nombre:");
     scanf("%s",p->name);
     if(strncmp(p->name,"salir",5)==0)
         return 1;
     printf("Ingrese la edad:");
     scanf("%d",&(p->age));
     return 0;
}


/**ESATAS VARIABLES SON GLOBALES DEL ARCHIVO COLOCADO AL PRINCIPIO Y NO SON PERTENECIENTES AL MAIN COMO ANTER*/
//}
/**EL TAMANIO DE LISTA, CANTIDAD DE ITEMS QUE HAY EN EL ARRAY*/
/** \brief devuelve la cantidad de items en el array
 * \return cantidad de items en el array (cantidad en lista)
 */
 int list_getSize(PeopleList* pl)//
 {
    return pl->index;
 }

 /**DEVUELVE UN ITEM*/

 /** \brief Devuelve un item del array
  * \param indice a obtener
  * \return Puntero a estructura person que se encuentra en esa posicion del array
  *
  */
  Person* list_get(PeopleList* pl,int i)//
  {
      if(i<pl->index)
        return pl->people[i];//OBTENEMOS LA POSICION
      return NULL;
  }

/** \brief Libera la memoria pedida para crear el array
 * \return void
 */
void list_free(PeopleList* pl)//
{
    free(pl->people);

}
/**AGREGO PERSONAS, Y EN CASO QUE NO HALLA LUGAR EL ARRAY VA A CRECER*/
/**LO QUE ANTES HACIA CON EL WHILE*/
/** \brief Agrega una referencia a una estructura Person al array
 * \param Person p: Puntero a estructura person
 * \return void
 */

void list_addPerson(PeopleList* pl, Person* p)//
{
    pl->people[pl->index]=p;//
    pl->index++;

    if(pl->index>=pl->listSize)
    {
        printf("no hay mas lugar, redefinimos el array\r\n");
        pl->listSize+=2;//agregamos 2 mas
        pl->people = (Person**)realloc(pl->people,sizeof(Person*)*pl->listSize);
    }
}
//DEBEMOS SUBIR UNA POSICION TODOS LOS ITEMS QUE ESTAN DEBAJO DE ESA POSICION
/** \brief Elimina un item del array
 * \param indice a borrar
 * \return void
 */
 void list_remove(PeopleList* pl,int indexToDelete)//
 {
     int i;
     if(pl->index!=0 && indexToDelete<pl->index)//me aseguro de que el item exista
     {
         for(i=indexToDelete;i<(pl->index-1);i++)
         {
             pl->people[i] = pl->people[i+1];//Copio en la posicion que yo quiero eliminar, la que esta debajo
         }
         pl->index--;
     }
 }




