#include "stdio.h"
#include <math.h>
#define MAX 30
/********** PROTOTIPO DE FUNCIONES **********/


int main(){
  /********** DECLARACION DE VARIABLES **********/
  char str[MAX];

  /********** ENTRADAS **********/
  printf("ingresa la cadena prro\n");
  fflush(stdin);
  gets(str);
  /********** PROCESOS **********/
  /********** SALIDAS **********/
  printf("%s\n", str);
  fflush(stdin);
  return 0;
}

/********** FUNCIONES **********/
