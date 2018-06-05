#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    ArrayList* listaEmpleados; //Estructura,puntero porque debe estar en el head
    //constructor_
    listaEmpleados = al_newArrayList();//elementos guardados 0//size

    Employee* miEmpleado;//dato del csv un nuevo auto *(lista)=*autoAux error porque tengo dos copias de lo mismo
    Employee* aux;
    /**listaEmpleados->size prohibido*/
    miEmpleado = (Employee*)malloc(sizeof(Employee));

    //SETER
    miEmpleado->id =8;
    strcpy(miEmpleado->name,"juan");
     miEmpleado->isEmpty =1;
    strcpy(miEmpleado->name,"Gomez");

    //al_add()--resizeup
    al_add(listaEmpleados,miEmpleado);

     Employee* otroEMpleado;//dato del csv un nuevo auto *(lista)=*autoAux error porque tengo dos copias de lo mismo
   // Employee* aux;
    /**listaEmpleados->size prohibido*/
    miEmpleado = (Employee*)malloc(sizeof(Employee));

    //SETER
    miEmpleado->id =9;
    strcpy(miEmpleado->name,"Ana");
     miEmpleado->isEmpty =1;
    strcpy(miEmpleado->name,"Ruiz");
      al_add(listaEmpleados,otroEMpleado);



    //aux esta guardando el dato que guarda en la lista
    aux =(Employee*) al_get(listaEmpleados,0);
 //   printf("%d--%s\n",aux->id,aux->name);
   //  printf("%d--%s\n",otroEMpleado->id,otroEMpleado->name);



    printf("%d",al_len(listaEmpleados));
    //obtenerun dato de un campo// al_len() hace un return del size devuelve un 0

    for(int i=0;i<al_len(listaEmpleados);i++)
    {
        aux =(Employee*)al_get(listaEmpleados,i);
        printf("%d--%s\n",aux->id,aux->name);

    }
    al_sort()//para irdenar
//employee_compare(): DElegado
    return 0;
}
