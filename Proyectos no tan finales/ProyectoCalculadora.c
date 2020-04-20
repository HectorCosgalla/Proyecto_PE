#include "stdio.h"
#include <math.h>
#include "stdbool.h"
#define MAX 30

//Cadena de prueba: 6-(8^3))*2+5-7/8^7
/********** PROTOTIPO DE FUNCIONES **********/
//void comprobLexico(char str[]);

int main(){
  /********** DECLARACION DE VARIABLES **********/
  int parenA = 0, parenC = 0, i = 0, j = 0;
  char str[MAX];
  bool error = false;
  /********** ENTRADAS **********/
  printf("ingresa la cadena prro\n");
  fflush(stdin);
  gets(str);
  /********** PROCESOS **********/
  while (str[i] != '\0' && error == false) {
    if (i == 0) {
      while (str[j] != '\0' && error == false) {
        if ((str[j] <= 39 || str[j] == 44 || str[j] == 46 || str[j] >= 58) && str[j] != 94) {
          printf("\nERROR DE LEXICO EN LA POSICION '%d'(caracter: %c)\n", j+1, str[j]);
          error = true;
        }
        j++;
      }
      j = 0;
      while (str[j] != '\0' && error == false) {
        if (((str[j] > 41 && str[j] <= 43) || str[j] == 45 || str[j] == 47 || str[j] == 94) && ((str[j+1] > 41 && str[j+1] <= 43) || str[j+1] == 45 || str[j+1] == 47 || str[j+1] == 94)) {
          printf("\nERROR SINTACTICO EN LA SECUENCIA: '%c%c')\n", str[j], str[j+1]);
          error = true;
        }
        if (str[j] == 40 && str[j+1] == 41) {
          printf("\nERROR SINTACTICO EN LA SECUENCIA: '%c%c')\n", str[j], str[j+1]);
          error = true;
        }
        if (str[j] == 40)
          parenA++;
        if (str[j] == 41)
          parenC++;
        if ((str[j+1] == '\0') && (parenA != parenC)) {
          printf("\nERROR SINTACTICO EN LA OPERACION:\n");
          printf("\n%s HACEN FALTA PARENTESIS\n", str);
          error = true;
        }
        j++;
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
