#include <stdio.h>
#include <stdlib.h>
#include "stdbool.h"
#include "string.h"
#include <dirent.h>

#define MAX 25

void pantalla1(char, char[]);
void pantalla2();
void pantalla3();
void pantalla4();

int main() {
	int opc;
	bool exit = false;
	char str, carac;
	char linea[42] = "-----------------------------------------\n";

	system("color 0F");
	system("mode 800");

	DIR* dir = opendir("inventario");
	if (dir) {
		closedir(dir);
	} else {
		system("mkdir inventario");
	}

	puts("\n\n\n\n\n\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("\t------------------------------------------------------------------------------------------BIENVENIDO-------------------------------------------------------------------------------------------");
	puts("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n");
	puts("\t\t\t\t\t\t\t\t\t\t\n");//puts("\t\t\t\t\t\t\t\t\t\tUsuario: \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t    ADMINISTRADOR DE TIENDA\n\n\n\n\n\n\n\n\n\n\n\n\n\n");//printf("\t\t\t\t\t\t\t\t\t\tContrase%ca: \n\n\n\n\n\n\n\n\n\n\n\n\n\n", 164);
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
		printf("Su seleccion: ");
		scanf("%i",&opc);
		switch(opc){
		case 1:
			pantalla1(str, linea);
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

void pantalla1( char str, char linea[] ) {
	FILE *inventario;
	char nomb[MAX];
	system("cls");
	puts("\n\n\n\n\n\t......................................................");
	inventario = fopen("inventario/NombreProd.txt", "a");
	printf("\t|Nombre del articulo:      |");
	fflush(stdin);
	gets(nomb);
	//puts("Ejemploarticulo");
  fputs(nomb, inventario);
  fputc(10, inventario);
	fclose(inventario);

	inventario = fopen("inventario/Descripcion.txt", "a");
	puts("\t......................................................");
	printf("\t|Descripcion del articulo: |");
	//puts("VESTIDO ROJO LARGO");
	fputs(nomb, inventario);
  fputc(10, inventario);
	while ((str = getchar()) != '\n') {
    fputc(str, inventario);
  }
  fputc(10, inventario);
	fclose(inventario);

	inventario = fopen("inventario/piezas.txt", "a");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	//puts("5");
	fputs(nomb, inventario);
  fputc(10, inventario);
	while ((str = getchar()) != '\n') {
    fputc(str, inventario);
  }
  fputc(10, inventario);
	fclose(inventario);

	inventario = fopen("inventario/precio.txt", "a");
	puts("\t......................................................");
	printf("\t|Precio:                   |");
	//puts("$200");
	fputs(nomb, inventario);
  fputc(10, inventario);
	while ((str = getchar()) != '\n') {
    fputc(str, inventario);
  }
  fputc(10, inventario);
	fclose(inventario);

	inventario = fopen("inventario/codigo.txt", "a");
	puts("\t......................................................");
	printf("\t|Codigo del articulo:      |");
	fputs(nomb, inventario);
  fputc(10, inventario);
	while ((str = getchar()) != '\n') {
    fputc(str, inventario);
  }
  fputc(10, inventario);
	fclose(inventario);
	//puts("EJEMPLO12345             ");

	system("cls");
	system("color 2F");
	puts("\n\n\n\n\n\t\t\t SE HA GUARDADO EXITOSAMENTE\n\n\n\n\n");
	system("pause");
	system("color 0F");
}

void pantalla2() {
	char art[20];
	int valido, opc;
	system("cls");
	puts("Buscar en el sistema: ");
	fflush(stdin);
	gets(art);
	valido = strcmp(art,"Ejemploarticulo");
	if (valido != 0) {
		system("cls");
		system("color C0");
		puts("\n\n\n\n\n\t\t\t NO HAY ARTICULOS DISPONIBLES\n\n\n\n\n");
		system("pause");
		system("color 0F");
	} else{
		system("cls");
		puts("\n\n\n\n\n\t......................................................");
		printf("\t|1)Nombre del articulo:      |");
		puts("Ejemploarticulo");
		puts("\t......................................................");
		printf("\t|2)Descripcion del articulo: |");
		puts("VESTIDO ROJO LARGO");
		puts("\t......................................................");
		printf("\t|3)Piezas:                   |");
		puts("5");
		puts("\t......................................................");
		printf("\t|4)Precio:                   |");
		puts("$200");
		puts("\t......................................................");
		printf("\t|5)Codigo del articulo:      |");
		puts("0123456789 ");
		puts("\t......................................................");
		printf("Seleccione la opcion que desea modificar: ");
		scanf("%d", &opc);

		system("cls");
		puts("Usted selecciono la opcion 5) \n");
		puts("|valor anterior:	0123456789");
		printf("|Valor actual: ");
		scanf("%d", &valido);

		system("cls");
		system("color 2F");
		puts("\n\n\n\n\n\t\t\t SE HA GUARDADO EXITOSAMENTE\n\n\n\n\n");
		system("pause");
		system("color 0F");
	}


}

void pantalla3() {
	char art[20];
	int valido, opc;
	system("cls");
	puts("Buscar en el sistema: ");
	fflush(stdin);
	gets(art);
	valido = strcmp(art,"Ejemploarticulo");
	if (valido != 0) {
		system("cls");
		system("color C0");
		puts("\n\n\n\n\n\t\t\t NO EXISTE O NO HAY ARTICULOS DISPONIBLES\n\n\n\n\n");
		system("pause");
		system("color 0F");
	} else {
		system("cls");
		puts("\n\n\n\n\n\t......................................................");
		printf("\t|Nombre del articulo:      |");
		puts("Ejemploarticulo");
		puts("\t......................................................");
		printf("\t|Piezas:                   |");
		puts("5");
		puts("\t......................................................");
		system("pause");
	}
}

void pantalla4() {
	system("cls");

	/*
	puts("\n\n\n\n\n\t......................................................");
	printf("\t|Nombre del articulo:      |");
	puts("Ejemploarticulo");
	puts("\t......................................................");
	printf("\t|Descripcion del articulo: |");
	puts("VESTIDO ROJO LARGO");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	puts("5");
	puts("\t......................................................");
	printf("\t|Precio:                   |");
	puts("$200");
	puts("\t......................................................");
	printf("\t|Codigo del articulo:      |");
	puts("1234567890");
	puts("\n\n\t......................................................");
	printf("\t|Nombre del articulo:      |");
	puts("Ejemploarticulo2");
	puts("\t......................................................");
	printf("\t|Descripcion del articulo: |");
	puts("VESTIDO ROJO CORTO");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	puts("0");
	puts("\t......................................................");
	printf("\t|Precio:                   |");
	puts("$300");
	puts("\t......................................................");
	printf("\t|Codigo del articulo:      |");
	puts("1122334455");
	puts("\t......................................................\n\n");
	*/
	system("pause");
}
