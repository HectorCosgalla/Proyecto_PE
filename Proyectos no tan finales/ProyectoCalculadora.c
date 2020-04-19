#include "stdio.h"
#include <math.h>
#define MAX 30
/********** PROTOTIPO DE FUNCIONES **********/
void comprobSintacticos(char str[]);

int main(){
  /********** DECLARACION DE VARIABLES **********/
  char str[MAX];

  /********** ENTRADAS **********/
  printf("ingresa la cadena prro\n");
  fflush(stdin);
  gets(str);
  /********** PROCESOS **********/
  comprobSintacticos(str);
  /********** SALIDAS **********/
  printf("%s\n", str);
  fflush(stdin);
  return 0;
}

/********** FUNCIONES **********/
void comprobSintacticos(char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] <= 39 || str[i] == 44 || str[i] == 46 || str[i] >= 58) {
      printf("\nERROR SINTACTICO EN %c\n", str[i]);

    }
    i++;
  }
}
