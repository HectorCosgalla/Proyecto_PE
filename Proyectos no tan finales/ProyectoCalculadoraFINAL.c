#include "stdio.h"
#include <math.h>
#include "stdbool.h"
#include "string.h"
#define MAX 30

//Cadena de prueba: 4*(5-2)*(1*4-3)
/********** PROTOTIPO DE FUNCIONES **********/


int main(){
	/********** DECLARACION DE VARIABLES **********/
	int parenA = 0, parenC = 0, i = 0, j = 0, k = 0, len, aux = 0;
	char str[MAX];
	bool error = false;
	/********** ENTRADAS **********/
	printf("ingresa la expresion aritmetica\n");
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
	if (error == false) {
		i = 0, j = 0;
		char listaSalida[len], pila[len];
		for (int i = 0; i < len; i++) {
			listaSalida[i] = '\0';
			pila[i] = '\0';
		}
		while (str[i] != '\0') {
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
					pila[k] = str[i];
					k++;
					break;
				case 41:
					k--;
					while (pila[k] != 40) {
						listaSalida[j] = pila[k];
						pila[k] = '\0';
						k--;
						j++;
					}
					if (pila[k] == 40) {
						pila[k] = '\0';
					}
					break;
				case 94:
					pila[k] = str[i];
					k++;
				case 42:
				case 47:
					k--;
					while (pila[k] != 40 && pila[k] != 94 && pila[k] != 43 && pila[k] != 45 && pila[k] != '\0') {
						listaSalida[j] = pila[k];
						pila[k] = '\0';
						k--;
						j++;
					}
					k++;
					pila[k] = str[i];
					k++;
					break;
				case 43:
				case 45:
					k--;
					while (pila[k] != 40 && (pila[k] != 94 || pila[k] != 47 || pila[k] != 42) && pila[k] != '\0') {
						listaSalida[j] = pila[k];
						pila[k] = '\0';
						k--;
						j++;
					}
					k++;
					pila[k] = str[i];
					k++;
					break;
			}
			i++;
		}
		k--;
		while (pila[k] != '\0') {
			listaSalida[j] = pila[k];
			pila[k] = '\0';
			k--;
			j++;
		}
		i = 0, j = 0, k = 0;
		int listaSalidaint[MAX];
		while (listaSalida[i] != '\0') {
			if (listaSalida[i] < 58 && listaSalida[i] > 47) {
				switch (listaSalida[i]) {
					case 48:
						listaSalidaint[j] = 0;
						break;
					case 49:
						listaSalidaint[j] = 1;
						break;
					case 50:
						listaSalidaint[j] = 2;
						break;
					case 51:
						listaSalidaint[j] = 3;
						break;
					case 52:
						listaSalidaint[j] = 4;
						break;
					case 53:
						listaSalidaint[j] = 5;
						break;
					case 54:
						listaSalidaint[j] = 6;
						break;
					case 55:
						listaSalidaint[j] = 7;
						break;
					case 56:
						listaSalidaint[j] = 8;
						break;
					case 57:
						listaSalidaint[j] = 9;
						break;
				}
				j++;
			}
			if (listaSalida[i] == 42 || listaSalida[i] == 43 || listaSalida[i] == 45 || listaSalida[i] == 47 || listaSalida[i] == 94) {
				j--;
				switch (listaSalida[i]) {
					case 42:
						listaSalidaint[j-1] = listaSalidaint[j-1] * listaSalidaint[j];
						break;
					case 43:
						listaSalidaint[j-1] = listaSalidaint[j-1] + listaSalidaint[j];
						break;
					case 45:
						listaSalidaint[j-1] = listaSalidaint[j-1] - listaSalidaint[j];
						break;
					case 47:
						listaSalidaint[j-1] = listaSalidaint[j-1] / listaSalidaint[j];
						break;
					case 94:
						listaSalidaint[j-1] = pow(listaSalidaint[j-1],listaSalidaint[j]);
						break;
				}
			}
			i++;
		}
		/********** SALIDAS **********/
		printf("\n");
		printf("el resultado es: %d\n",listaSalidaint[0]);
		printf("\n");
	}

}
