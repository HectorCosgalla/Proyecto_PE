#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"

void pantalla1();
void pantalla2();
void pantalla3();
void pantalla4();

int main() {
	int opc;
	bool exit = false;
	puts("\n\n\n\n\n\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("\t------------------------------------------------------------------------------------------BIENVENIDO-------------------------------------------------------------------------------------------");
	puts("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n");
	puts("\t\t\t\t\t\t\t\t\t\tUsuario: \n");
	printf("\t\t\t\t\t\t\t\t\t\tContrase%ca: \n\n\n\n\n\n\n\n\n\n\n\n\n\n", 164);
	puts("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	system("pause");
	do {
		system("cls");
		puts("\n\n\n\t\t\t\t\t\t\t\t\t\t\tOpciones: ");
		puts("1)Introducir articulo. ");
		puts("\n\n\t\t\t\t\t2)Modificar articulo. ");
		puts("\n\n\t\t\t\t\t\t\t\t\t\t3)Consultar disponibilidad de un articulo. ");
		puts("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t4)Consultar inventario.");
		puts("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t5)Salir\n\n\n\n\n\n\n");
		scanf("%i",&opc);
		switch(opc){
		case 1:
			pantalla1();
			break;
		case 2:
			pantalla2();
			break;
		case 3:
			pantalla3();
			break;
		case 4:
			pantalla4();
			break;
		case 5:
			exit = true;
			break;
		default:
			puts("ERROR: OPCION INCORRECTA, INTENTELO NUEVAMENTE");
			system("pause");
		}
		system("cls");
	} while(exit == false);
	return 0;
}

void pantalla1() {
	system("cls");
	puts("\n\n\n\n\n\t......................................................");
	printf("\t|Nombre del articulo:      |");
	puts("Ejemploarticulo          |");
	puts("\t......................................................");
	printf("\t|Descripcion del articulo: |");
	puts("VESTIDO ROJO LARGO       |");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	puts("5                        |");
	puts("\t......................................................");
	printf("\t|Codigo del articulo:      |");
	puts("EJEMPLO12345             |");
	puts("\t......................................................");
	system("pause");
}

void pantalla2() {
	system("cls");
	puts("\n\n\n\t\t\tBuscar en el sistema: ");
	system("pause");
	system("cls");
	puts("\n\nSeleccione la opcion que desea modificar:\n");
	printf("\t|1)Nombre del articulo:      |");
	puts("Ejemploarticulo          |");
	puts("\t......................................................");
	printf("\t|2)Descripcion del articulo: |");
	puts("VESTIDO ROJO LARGO       |");
	puts("\t......................................................");
	printf("\t|3)Piezas:                   |");
	puts("5                        |");
	puts("\t......................................................");
	printf("\t|4)Codigo del articulo:      |");
	puts("EJEMPLO12345             |");
	puts("\t......................................................");
	system("pause");
}

void pantalla3() {
	system("cls");
	puts("\n\n\n\t\t\tBuscar en el sistema: ");
	system("pause");
	system("cls");
	printf("\t|Nombre del articulo:      |");
	puts("Ejemploarticulo          |");
	puts("\t......................................................");
	printf("\t|Descripcion del articulo: |");
	puts("VESTIDO ROJO LARGO       |");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	puts("5                        |");
	puts("\t......................................................");
	printf("\t|Codigo del articulo:      |");
	puts("EJEMPLO12345             |");
	puts("\t......................................................");
	system("pause");
}

void pantalla4() {
	system("cls");
	printf("\t|Nombre del articulo:      |");
	puts("Ejemploarticulo          |");
	puts("\t......................................................");
	printf("\t|Descripcion del articulo: |");
	puts("VESTIDO ROJO LARGO       |");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	puts("5                        |");
	puts("\t......................................................");
	printf("\t|Codigo del articulo:      |");
	puts("EJEMPLO12345             |");
	puts("\t......................................................\n\n");
	printf("\t|Nombre del articulo:      |");
	puts("Ejemploarticulo2         |");
	puts("\t......................................................");
	printf("\t|Descripcion del articulo: |");
	puts("VESTIDO ROJO LARGO       |");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	puts("5                        |");
	puts("\t......................................................");
	printf("\t|Codigo del articulo:      |");
	puts("EJEMPLO12345             |");
	puts("\t......................................................\n\n");
	system("pause");
}
