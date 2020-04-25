#include "stdio.h"
#include <math.h>
#include "stdbool.h"
#include "string.h"
#define MAX 30

//Cadena de prueba: 4*(5-2)*(1*4-3)
/********** PROTOTIPO DE FUNCIONES **********/


int main(){
	/********** DECLARACION DE VARIABLES **********/
	int parenA = 0, parenC = 0, i = 0, j = 0, k = 0, len;
	char str[MAX];
	bool error = false;
	/********** ENTRADAS **********/
	printf("ingresa la cadena prro\n");
	fflush(stdin);
	gets(str);
	len = strlen(str)+1;

	/********** PROCESOS **********/
	while (str[i] != '\0' && error == false) {
		while (str[j] != '\0' && error == false) {
			if ((str[j] <= 39 || str[j] == 44 || str[j] == 46 || str[j] >= 58) && str[j] != 94 && str[j] != 120 && str[j] != 61) {
				printf("\nERROR DE LEXICO EN LA POSICION '%d'(caracter: %c)\n", j+1, str[j]);
				error = true;
			}
			j++;
		}
		j = 0;
		while (str[j] != '\0' && error == false) {
			if (((str[j] > 41 && str[j] <= 43) || str[j] == 47 || str[j] == 94) && ((str[j+1] > 41 && str[j+1] <= 43) || str[j+1] == 47 || str[j+1] == 94)) {
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
		i++;
	}
	i = 0, j = 0;
	char listaSalida[len], pila[len];
	for (int i = 0; i < len; i++) {
		listaSalida[i] = '\0';
		pila[i] = '\0';
	}
	while (str[i] != '\0' && error == false) {
		switch (str[i]) {
			case 48:
			case 49:
			case 50:
			case 51:
			case 52:
			case 53:
			case 54:
			case 55:
			case 56:
			case 57:
				listaSalida[j] = str[i];
				j++;
				break;
			case 40:
				if (pila[k] != '\0') {
					pila[k+1] = pila[k];
					pila[k] = str[i];
				} else {
					pila[k] = str[i];
				}
				break;
			case 41:
				while (pila[k] != '\0' && pila[0] != 40) {
					listaSalida[j] = pila[k];
					pila[k] = pila[k+1];
					k++;
					j++;
				}
				if (pila[0] == 40) {
					while (pila[k] != '\0') {
						pila[k] = pila[k+1];
						k++;
					}
				}
				k=0;
				break;
			case 94:
			case 42:
			case 47:
			case 43:
			case 45:
				pila[k] = str[i];
				break;
		}
		printf("%s || %s\n", listaSalida, pila);
		i++;
	}
	/********** SALIDAS **********/
	printf("%s %s\n", listaSalida, pila);
	printf("%s\n", str);
}
