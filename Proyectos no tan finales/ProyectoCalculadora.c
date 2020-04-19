#include "stdio.h"
#include <math.h>
#include "stdbool.h"
#define MAX 30

//Cadena de prueba: 6-(8^3)#*2+5-7/8^7
/********** PROTOTIPO DE FUNCIONES **********/
//void comprobLexico(char str[]);

int main(){
  /********** DECLARACION DE VARIABLES **********/
  int parenA = 0, ParenC = 0, i = 0, j = 0;
  char str[MAX];
  bool error = false;
  /********** ENTRADAS **********/
  printf("ingresa la cadena prro\n");
  fflush(stdin);
  gets(str);
  /********** PROCESOS **********/
  while (str[i] != '\0' && error == false) {
    if (i == 0) {
      while (str[i] != '\0' && error == false) {
        if ((str[i] <= 39 || str[i] == 44 || str[i] == 46 || str[i] >= 58) && str[i] != 94) {
          printf("\nERROR DE LEXICO EN LA POSICION '%d'(caracter: %c)\n", i+1, str[i]);
          error = true;
        }
      }
    }
    i++;
  }
  /********** SALIDAS **********/
  printf("\n%s\n", str);
  fflush(stdin);
  return 0;
}

/********** FUNCIONES *********
void comprobLexico(char str[]) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] <= 39 || str[i] == 44 || str[i] == 46 || str[i] >= 58 && str[i] != 94) {
      printf("\nERROR DE LEXICO EN LA POSICION '%d'(caracter: %c)\n", i, str[i]);
      G(3)#*2+5-7/8^7
    }
    i++;
  }
}
*/
