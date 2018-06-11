#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"

/**DEFINIMOS EN FORMA GLOBAL EL ARRAY, LA VARIABLE QUE LLEVA LA CUENTA del contador*/
int listSize;//TAMANIO DEL ARRAY
Person** people;
int index;

/*int tamanio_de_lista=2;
persona** personas = (persona**)malloc(sizeof(persona*)*tamanio_de_lista);
int index=0;//cantidad de personas ingresadas*/


/** \brief Inicializa el array de estructuras Person//inicializa las variables globales
 *
 * \param
 * \param
 * \return void
 *
 */
 void list_initPeopleList(void)
 {
    index=0;
    listSize=2;
    people = (Person**)malloc(sizeof(Person*)*listSize);

    /** int listSize=2;
         Person** people = (Person**)malloc(sizeof(Person*)*listSize);

    */
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

  Person* list_newPerson(void)
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
void list_printPerson(Person* p)
{
    printf("Nombre:\t%s \tedad:%d\r\n",p->name,p->age);
}


/**INGRESAR PERSONA*/
/** \brief Pide al usuario los datos de una persona y los almacena en la struct
 * \param Person* p puntero a tipo Person donde se guardarán los datos
 * \return 1: si se ingresa salir, 0 de lo contrario
 */
int list_enterPerson(Person* p)
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
 int list_getSize(void)
 {
    return index;
 }

 /**DEVUELVE UN ITEM*/

 /** \brief Devuelve un item del array
  * \param indice a obtener
  * \return Puntero a estructura person que se encuentra en esa posicion del array
  *
  */
  Person* list_get(int i)
  {
      if(i<index)
        return people[i];//OBTENEMOS LA POSICION
      return NULL;
  }

/** \brief Libera la memoria pedida para crear el array
 * \return void
 */
void list_free(void)
{
    free(people);

}
/**AGREGO PERSONAS, Y EN CASO QUE NO HALLA LUGAR EL ARRAY VA A CRECER*/
/**LO QUE ANTES HACIA CON EL WHILE*/
/** \brief Agrega una referencia a una estructura Person al array
 * \param Person p: Puntero a estructura person
 * \return void
 */

void list_addPerson(Person* p)
{
    people[index]=p;//
    index++;

    if(index>=listSize)
    {
        printf("no hay mas lugar, redefinimos el array\r\n");
        listSize+=2;//agregamos 2 mas
        people = (Person**)realloc(people,sizeof(Person*)*listSize);
    }
}
//DEBEMOS SUBIR UNA POSICION TODOS LOS ITEMS QUE ESTAN DEBAJO DE ESA POSICION
/** \brief Elimina un item del array
 * \param indice a borrar
 * \return void
 */
 void list_remove(int indexToDelete)
 {
     int i;
     if(index!=0 && indexToDelete<index)//me aseguro de que el item exista
     {
         for(i=indexToDelete;i<(index-1);i++)
         {
             people[i] = people[i+1];//Copio en la posicion que yo quiero eliminar, la que esta debajo
         }
         index--;
     }
 }



