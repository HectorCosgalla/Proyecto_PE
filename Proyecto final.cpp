#include <stdio.h>
#include<stdlib.h>

int main() {
	int opc;
	puts("\n\n\n\n\n\n\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("\t------------------------------------------------------------------------------------------BIENVENIDO-------------------------------------------------------------------------------------------");
	puts("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n\n\n\n\n");
	puts("\t\t\t\t\t\t\t\t\t\tUsuario: \n");
	puts("\t\t\t\t\t\t\t\t\t\tContrase�a: \n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	puts("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	puts("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
	system("pause");
	system("cls");
	puts("\n\n\n\t\t\t\t\t\t\t\t\t\t\tOpciones: ");
	puts("1)Introducir art�culo. ");
	puts("\n\n\t\t\t\t\t\t2)Modificar articulo. ");
	puts("\n\n\t\t\t\t\t\t\t\t\t\t\t3)Consultar disponibilidad de un articulo. ");
	puts("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t4)Consultar inventario. \n\n\n\n\n\n\n");
	scanf("%i",&opc);
	switch(opc){
	case 1:	system("cls"); 
	puts("\n\n\n\n\n\t......................................................");
	printf("\t|Nombre del art�culo:      |");
	puts("Ejemploarticulo          |");
	puts("\t......................................................");
	printf("\t|Descripci�n del art�culo: |");
	puts("VESTIDO ROJO LARGO       |");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	puts("5                        |");
	puts("\t......................................................");
	printf("\t|C�digo del art�culo:      |");
	puts("EJEMPLO12345             |");
	puts("\t......................................................");
	break;
	case 2: system("cls");
	puts("\n\n\n\t\t\tBuscar en el sistema: ");
	system("pause");
	system("cls");
	puts("\n\nSeleccione la opcion que desea modificar:\n");
	printf("\t|1)Nombre del art�culo:      |");
	puts("Ejemploarticulo          |");
	puts("\t......................................................");
	printf("\t|2)Descripci�n del art�culo: |");
	puts("VESTIDO ROJO LARGO       |");
	puts("\t......................................................");
	printf("\t|3)Piezas:                   |");
	puts("5                        |");
	puts("\t......................................................");
	printf("\t|4)C�digo del art�culo:      |");
	puts("EJEMPLO12345             |");
	puts("\t......................................................");
	break;
	case 3: system("cls");
	puts("\n\n\n\t\t\tBuscar en el sistema: ");
	system("pause");
	system("cls");
	printf("\t|Nombre del art�culo:      |");
	puts("Ejemploarticulo          |");
	puts("\t......................................................");
	printf("\t|Descripci�n del art�culo: |");
	puts("VESTIDO ROJO LARGO       |");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	puts("5                        |");
	puts("\t......................................................");
	printf("\t|C�digo del art�culo:      |");
	puts("EJEMPLO12345             |");
	puts("\t......................................................");
	break;
	case 4: system("cls");
	printf("\t|Nombre del art�culo:      |");
	puts("Ejemploarticulo          |");
	puts("\t......................................................");
	printf("\t|Descripci�n del art�culo: |");
	puts("VESTIDO ROJO LARGO       |");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	puts("5                        |");
	puts("\t......................................................");
	printf("\t|C�digo del art�culo:      |");
	puts("EJEMPLO12345             |");
	puts("\t......................................................\n\n");
	printf("\t|Nombre del art�culo:      |");
	puts("Ejemploarticulo2         |");
	puts("\t......................................................");
	printf("\t|Descripci�n del art�culo: |");
	puts("VESTIDO ROJO LARGO       |");
	puts("\t......................................................");
	printf("\t|Piezas:                   |");
	puts("5                        |");
	puts("\t......................................................");
	printf("\t|C�digo del art�culo:      |");
	puts("EJEMPLO12345             |");
	puts("\t......................................................\n\n");
	
	
	}
	system("pause");
	system("cls");
	return 0;
}

