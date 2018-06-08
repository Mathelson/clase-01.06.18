#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

typedef struct{

    char name[32];
    char surname[32];
    int age;

} S_Person;

/** \brief  Pide al usuario los datos y los guarda en la struct
 * \param structu S_Person* puntero a struct donde se almacenan los datos ingresados
 * \return void
 */
 void loadData(S_Person* persona)
{
    getString("Ingrese el Nombre:",persona->name);
    getString("Ingrese el Apellido:",persona->surname);
    persona->age=getInt("Ingrese la edad:");

}
/** \brief Guarda una Struct al final de un archivo binario bin.data
 * \param struct s_person* p puntero a structura a se escrita
 * \return 0;Error, 1:Ok
 *
 */
 int savePerson(S_Person* persona)
 {
     FILE* fp;//creamos una variable como puntero al archivo
     fp=fopen("bin.dat","ab+");//lo abrimos con modificador ab+, lo crea si no existe+ y la b es de binario a=append
     if(fp==NULL)
     {
         printf("Error opening file");
         return 0;
     }
     fwrite(persona,sizeof(S_Person),1,fp);//escribe la estructura al final del archivo que abrimos
    //puntero que queremos escribir, tamanio, bloque y la cantidad de bloques
    //en este caso pasamos los bytes de la estructua de una vez para poder escribirlos;
    //por ultimo el puntero al archivo donde vamos a escribir
     fclose(fp);//cerramos
     return 1;//escribimos correctamente
 }
/** \brief Busca en el archivo la estructura con el apellido pasado como argumento y la devuelve
 * \param char* surname apellido
 * \return puntero a estructura que se leyo del archivo o NULL si no existe el apellido
 */
 S_Person* readPerson(char* surname)
 {
     FILE* fp;
     fp=fopen("bin.dat","rb");//lectura binaria
     if(fp==NULL)//chequeamos que el archivo se pueda abrir
     {
         printf("Error no se encontro el apellido");
         return NULL;
     }
     S_Person* pRet = malloc(sizeof(S_Person));//mismo espacio de memoria para la struct pRet
     int flagFound = 0;
     while(fread(pRet,sizeof(S_Person),1,fp)!=0)//mientras se alla leido algun bloque, entramos al while
     {
         if(strcmp(surname,pRet->surname)==0)//si el campo surname de esa estructura que leimos del archivo es igual
            //a la cadena de caracter que recibimos como argumento
         {
             flagFound=1;//lo ponemos en uno para devolver la estructura que ya esta cargada con los datos, cuando HICE EL FREAD
             break;//encontramos la estructura con el apellido que estabamos buscando
         }
     }
     fclose(fp);
     if(flagFound)
        return pRet;
     free(pRet);//para que cada vez que llamemos a esta funcion no me ocupe cada vez mas memoria
     return NULL;
 };

int main()
{
    S_Person persona;
    char out='s';

    while(out=='s')
    {
        loadData(&persona);
        savePerson(&persona);
        out = getChar("Ingresar uno nuevo? s/n:");//pedimos al usuario que ingrese la persona
    }
    char encontrarApellido[64];
    getString("Ingrese apellido a buscar en archivo:",encontrarApellido);
    S_Person* personaEncontrada = readPerson(encontrarApellido);//Estructura que nos devuelve la funcion

    if(personaEncontrada!=NULL)
    {
        printf("Se encontro: nombre: %s apellido: %s edad: %d\r\n",personaEncontrada->name,personaEncontrada->surname,personaEncontrada->age);
        free(personaEncontrada);
    }
    else
        printf("El apellido ingresado no esta en el archivo");

    return 0;
}
