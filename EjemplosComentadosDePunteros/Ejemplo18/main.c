#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
/* Crear una struct con dos campos de cadena de caracteres, uno llamado 'key' y otro llamado 'value'.

struct S_Data
{
  char* key;
  char* value;
};

Hacer una función que reciba el nombre de un archivo y un array de estas estructuras.La función leerá un archivo de texto con el siguiente formato:

clave=valor
clave=valor

La función deberá leer cada línea del archivo y separar por el caracter '=' la clave y el valor, y deberá cargarlo en una struct del array, generando de forma dinámica las variables para almacenar ambas palabras, y luego guardando los punteros en la struct. Prototipo de la función:

int loadDataFile(char* fileName,struct S_Data* array, int arrayLen)

La función devolverá la cantidad de items que se cargaron en el array, y nunca se superará el tamaño del array

*/
typedef struct
{   //punteros a char
    char* key;
    char* value;
}S_data;
int loadDataFile(char* fileName,S_data* array,int arrayLen)
{
    FILE *fp;//puntero al archivo;
    char lineStr[128];//variable donde almacenamos la linea leida
    /*Abrimos el archivo para Lectura*/
    fp = fopen(fileName,"r");//MODO TEXTO DE LECTURA
    if(fp == NULL)//CHEQUEAMOS QUE EL ARCHIVO EXISTA
    {
        //DE LO CONTRARIO DEVUELVO UN ERROR
      perror("error opening file");
      return -1;//ERROR
    }
    //SI EXISTE EL ARCHIVO autos.csv
    int index=0;
    //
    while(fgets(lineStr,128,fp)!=NULL)//LEEMOS UNA LINEA(cadena,maximo de tamaño para esa cadena,puntero al archivo)
    {

        int indexDivider;
        int keyLen;
        int valueLen;

        indexDivider = strcspn(lineStr,"=");//devuelve la posicion del"="
        keyLen = indexDivider+1;//le sumamos 1 para guardar el espacio, teniedo en cuenta el \0
        valueLen = strlen(lineStr) - indexDivider -1;//largo total de la cadena de caracteres y le restamos el largo de la clave y el igual

        char* key =(char*)malloc(keyLen);//reservamos memoria, pedimos memoria
        char* value = (char*)malloc(valueLen);
//en lo siguiente copiamos la palabra que es la clave,
               //copiamos en el espacio reservado que apunta a key,laclave lineStr,cuantos caracteres copiamos?key len-1;
        strncpy(key,lineStr,keyLen-1);
        //al final.. caragamos 0x00, por eso utilizamos key[keyLen -1]//para asegurarnos el fin de la cadena de caracteres;
        key[keyLen-1]=0x00;
//copiamos en value  &lineStr//desde este espacio en la memoria[y desde esta posicion], la cantidad es valueLen -1 y lo copiamos en el espacio a donde apunta value;
        strncpy(value,&lineStr[keyLen],valueLen-1);
        value[valueLen-1]=0x00;//caracter terminador

        //copiamos esas direcciones de memoria en los campos de la estructura
        //index es una variable que arranca en cero y por cada linea se ira incrementado
        array[index].key = key;
        array[index].value = value;

        //contamos la cantidad de items en el array si se llega al maximo
        index++;
        if(index>=arrayLen)
        {
            break;
        }
    }
    fclose(fp);
    return index;
};


//int loadDataFile(char* fileName,S_data* array,int arrayLen);
int main()
{
    S_data array[16];
    int len = loadDataFile("dict.txt",array,16);

    for(int i=0;i<len;i++)
    {
        printf("%s = %s\r\n",array[i].key,array[i].value);
    }
    return 0;
}
 //name del archivo.AUTOSCSV a cadena de caracteres
                   //array de estructura del tipo s_data como un puntero
                   //int con el tamanio del array
