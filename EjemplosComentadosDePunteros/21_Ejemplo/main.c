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
    //persona personas[1000];//ESTAS POSICIONES QUEDABAN FIJAS Y NUNCA PODIAN CRECER
    int tamanio_de_lista=2;/*como el tamanio va a ser variable definimos una para definir el tamanio del array en MALLOC*/
   persona* personas = (persona*)malloc(sizeof(persona)*tamanio_de_lista);//cantidad de bites que tiene la struct * cantidad de arrays CANTIDAD DE ESTRUCTURAS(TAMANIO_DE_LISTA)
    persona p;
    int index=0;//cantidad de personas ingresadas

    /**CARGA DE DATOS**/
    while(enterPerson(&p)==0)//EL USUARIO NO INGRESO LA PALABRA SALIR
    {
        personas[index]=p;
        index++;
        //PARA QUE EL ARRAY CREZCA
        if(index>=tamanio_de_lista)
        {
            printf("El array se quedo sin Espacio\r\n");
            tamanio_de_lista+=2;//criterio para agrandar el tamio y cargarlo nuevamente, se suman 2
                                //el array se incrementa de a dos posiciones
            /*SE INCREMENTA HASTA QUE SALGAMOS**/
            personas = (persona*)realloc(personas,sizeof(persona)*tamanio_de_lista);

        }
    }
    /**IMPRIMO LOS DATOS**/
    for(int i=0;i<index;i++)
    {
        printPerson(&personas[i]);
    }
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



