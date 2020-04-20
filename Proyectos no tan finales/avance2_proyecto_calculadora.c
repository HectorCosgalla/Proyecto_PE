#include "stdio.h"
#include <math.h>
#include "stdbool.h"
#include "string.h"
#define MAX 30

	//Cadena de prueba: 4*(5-2)(1*4-3)
	/********** PROTOTIPO DE FUNCIONES **********/


	int main(){
		/********** DECLARACION DE VARIABLES **********/
		int parenA = 0, parenC = 0, i = 0, j = 0, k=0, aux=0;
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
			}
			i++;
		}
		//INICIO
		char E;
		bool precedencia = false;
		int len=strlen(str)+1;
		char pila[len];
		char listaSalida[len];
		for (size_t i = 0; i < len; i++) {
			pila[i] = '\0';
			listaSalida[i] = '\0';
		}
		i=0;
		j=0;
		while(str[i] != '\0' && error == false){
			E = str[i];
			if(E>47 && E<58){
				listaSalida[j]=E;
				j++;
			}
			if(E==40){
				pila[k]=E;
				k++;
			}
			if(E==41){
				while(pila[k] != '\0' && pila[k] != 40){
					printf("%c && %c\n", listaSalida[j], pila[k+1]);
					listaSalida[j]=pila[k+1];
					k++;
					j++;
				}
				k=0;
				if (pila[k] == 40) {
					while (pila[k]!='\0') {
						pila[k] = pila[k+1];
						k++;
					}
				}
			}

			if(E == 42 || E == 43 || E == 45 || E == 47 || E == 94){
				pila[k]=E;
				k++;
			}
			i++;
			printf("%s || %s\n", listaSalida, pila);
		}
		i = 0;
		while (pila[i] != '\0') {
			listaSalida[j] = pila[i];
			j++;
			i++;
		}
		printf("Lista de salida=%s\n", listaSalida);
		/********** SALIDAS **********/
		printf("\nLista de entrada=%s\n", str);
		fflush(stdin);
		return 0;
	}
