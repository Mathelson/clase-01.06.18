#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

 struct S_Person{
 char name[20];
 int age;
};
typedef struct S_Person persona;

int enterPerson(persona* p);
void printPerson(persona* p);
int main()
{
    persona p;

    while(enterPerson(&p)==0)//EL USUARIO NO INGRESO LA PALABRA SALIR
    printPerson(&p);

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



