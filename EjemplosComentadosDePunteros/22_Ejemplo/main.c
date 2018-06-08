/*teniamos array dinamico de structura tipo personas
  modificarlo, para no crear un array de persona sinode puntero a estructuras person

  perona o person en forma dinamica
  vamos a crear un array de punteros a esos espacios de memoria que vamos a ir ingresando cada vez que ingresemos una persona

  ANTER UTILIZAMOS UN ARRAY QUE YA ERA DE ESTRUCTURAS, CADA ITEM DEL ARRAY OCUPABA EL ESPACIO QUE OCUPA CADA ESTRUCTURA

  AHORA EL ARRAY ES SOLO DE PUNTEROS, CADA ITEM DEL ARRAY OCUPARA 4 BYTES, Y VA A APUNTAR A UN ESPACIO DE MEMORIA, GENERADO DE
  FORMA DINAMICA Y VA A TENER EL TAMANIO DE UNA ESTRUCTURA DEL TIPO PERSON
**/

/**SE ELIMINARON LOS & PORQUE P YA ES UN PUNTERO A LA DIRECCION DE MEMORIA */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

 struct S_Person{
 char name[20];
 int age;
};
typedef struct S_Person persona;

int enterPerson(persona* p);
void printPerson(persona* p);
int main()
{

    int tamanio_de_lista=2;
  // persona* personas = (persona*)malloc(sizeof(persona)*tamanio_de_lista);//cantidad de bites que tiene la struct * cantidad de arrays CANTIDAD DE ESTRUCTURAS(TAMANIO_DE_LISTA)
   /**TIPO DE DATO PERSONA ES UNA PUNTERO A UN ARRAY DONDE LOS ITEMS DEL ARRAY SON PUNTEROS DEL TIPO PERSON*/
   persona** personas = (persona**)malloc(sizeof(persona*)*tamanio_de_lista);//


   // persona p;
   persona* p = (persona*)malloc(sizeof(persona));//RESERVAMOS DE FORMA DINAMICA EL TAMANIO DE LA ESTRUCTURA
    int index=0;//cantidad de personas ingresadas

    /**CARGA DE DATOS**/
    while(enterPerson(p)==0)//EL USUARIO NO INGRESO LA PALABRA SALIR
    {
       // personas[index]=p;
       /**pasamos la direccionde memoria de p*/
       personas[index]=p;//COPIAMOS ESA DIRECCION AL ARRAY
        index++;
        //PARA QUE EL ARRAY CREZCA
        if(index>=tamanio_de_lista)
        {
            printf("El array se quedo sin Espacio\r\n");
            tamanio_de_lista+=2;//criterio para agrandar el tamio y cargarlo nuevamente, se suman 2
                                //el array se incrementa de a dos posiciones
            /*SE INCREMENTA HASTA QUE SALGAMOS**/
            //personas = (persona*)realloc(personas,sizeof(persona)*tamanio_de_lista);
         personas = (persona**)realloc(personas,sizeof(persona*)*tamanio_de_lista);

        }
           p = (persona*)malloc(sizeof(persona));//CREAMOS OTRO ESPACIO DE MEMORIA//Y LO VOLVEMOS A CARGAR


    }
       free(p);
    /**IMPRIMO LOS DATOS**/
    for(int i=0;i<index;i++)

        //printPerson(&personas[i]);
        printPerson(personas[i]);//& se lo quitamos porque el array ya es de punteros


     for(int i=0;i<index;i++)

        //printPerson(&personas[i]);
        free(personas[i]);//& se lo quitamos porque el array ya es de punteros


      free(personas);
    system("PAUSE");
    return 0;
}
/** \brief pide al usuario los datos de una persona y los almacena en la estructura
 * \param person* p puntero a tipo Person donde se gurdaran los datos
 * \return 1: si se ingresa salir, 0  de lo contrario
 */
 int enterPerson(persona* p)
 {
     printf("Ingrese el Nombre:");
     scanf("%s",p->name);
     if(strncmp(p->name,"salir",5)==0)//comparamos si lo ingresado es igual a salir con strncmp, con n indicamos la cantidad de caracteres que tiene
        return 1;
     printf("Ingrese La edad:");
     scanf("%d",&(p->age));//direccion de memoria del campo age
     return 0;
 }
 /** \brief Imprime los datos de una persona
  * \param Person* p puntero a tipo Persona donde se guardaran los datos
  * \return void
  *
  */
  void printPerson(persona* p)
  {
      printf("Nombre:\t %s \tedad:%d\r\n",p->name,p->age);
  }



