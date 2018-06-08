#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "people.h"

/**DEFINIMOS EN FORMA GLOBAL EL ARRAY, LA VARIABLE QUE LLEVA LA CUENTA del contador*/
int listSize;
Person** people;
int index;

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
     /**  Person* p = (Person*)malloc(sizeof(Person));*/                                           //buscams espacio en memoria
    return p;
  }



/** \brief Imprime los datos de una persona
 * \param Person* p puntero a tipo Person donde se guardarán los datos
 * \return void
 */
void list_printPerson(Person* p)
{
    printf("Nombre:\t%s \tedad:%d\r\n",p->name,p->age);
}



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

/** \brief Agrega una referencia a una struct Person al array
 *
 * \param person p: puntero a estructura person
 * \param
 * \return void
 *
 */

void list_newPerson(Person* p)
{
       people[index]=p; // copiamos el puntero a la estrcutura cargada "p" a una posicion del array de punteros.
       index++;

       // si no hay mas lugar, pedimos más memoria para hacer un array más grande
       if(index>=listSize)
       {
          printf("no hay mas lugar, redefinimos el array\r\n");
          listSize+=2; // agregamos dos mas
          //people = (Person*)realloc(people,sizeof(Person)*listSize);
          people = (Person**)realloc(people,sizeof(Person*)*listSize);
       }
/**ESATAS VARIABLES SON GLOBALES DEL ARCHIVO COLOCADO AL PRINCIPIO Y NO SON PERTENECIENTES AL MAIN COMO ANTER*/
}

/** \brief devuelve la cantidad de items en el array
 *
 * \param
 * \param
 * \return cantidad de items en el array (cantidad en lista)
 */
 int list_getSize(void)
 {
    return index;
 }
 /** \brief Devuelve un item del array
  *
  * \param indice a obtener
  * \param
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

