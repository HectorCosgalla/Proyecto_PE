#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stdbool.h"
#include "string.h"
#include <dirent.h>

#define MAX 25
#define USUARIO "admin"
#define CONTRASENIA "negocio2020"

int login(void);
void pantalla1(char, char[]);
void pantalla2();
void pantalla3();
void mostrarInventario();
void agregarProductos();


/*struct articulos {
char producto[100];
char descripcion[100];
char unidades [100];
char precio[100];
int codigo [100];
struct articulos *enlace;
};
struct articulos *primero, *ultimo;*/

int main() {
	int log;
	log = login();
	if(log == 1){
		int opc;
		bool exit = false;
		char str, carac;
		char linea[42] = "-----------------------------------------\n";
		/*
		primero = (struct articulos *) NULL;
		ultimo = (struct articulos *) NULL;
		*/
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
				/*fflush(stdin);
				agregarProductos();*/
				break;
			case 2:
				pantalla2();
				break;
			case 3:
				pantalla3();
				break;
			case 4:
				//pantalla4();
				//mostrarInventario();
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
	}
	else{
		system("cls");
		printf("Ha excedido el numero de intentos permitidos");
	}
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
/*
void agregarProductos() {
int codigo;
struct articulos *nuevo;
nuevo = (struct articulos *) malloc(sizeof(struct articulos));
if (nuevo==NULL) printf( "No hay memoria disponible!\n");
fflush(stdin);
printf("\nAgrege nuevo producto\n");
printf("Nombre del producto: ");
gets(nuevo->producto);
fflush(stdin);
printf("Descripcion del producto: ");
gets(nuevo->descripcion);
fflush(stdin);
printf("Unidades del producto: ");
gets(nuevo->unidades);
fflush(stdin);
printf("Precio del producto: ");
gets(nuevo->precio);
fflush(stdin);
printf("Coloque un codigo al producto: ");
scanf("%d",nuevo->codigo);
nuevo->enlace = NULL;
if (primero==NULL) {
printf( "Primer elemento\n");
primero = nuevo;
ultimo = nuevo;
}
else {
ultimo->enlace = nuevo;
ultimo = nuevo;
}
}
void mostrarInventario() {
struct articulos *auxiliar;
int i;
i=0;
auxiliar = primero;
printf("\nEl inventario es:\n");
while (auxiliar!=NULL) {
printf("---------------------------");
printf("\nNombre del producto: %s",auxiliar->producto);
printf("\nDescripcion del producto: %s",auxiliar->descripcion);
printf("\nUnidades del producto: %s",auxiliar->unidades);
printf("\nPrecio del producto: %s",auxiliar->precio);
printf("\nCodigo del producto: %d",auxiliar->codigo);
auxiliar = auxiliar->enlace;
i++;
}
if (i==0){
printf( "\nLa lista está vacía!!\n" );};
fflush(stdin);
getchar();
system("cls");
}
*/

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

int login(void){
	int log = 0;
	int intentos = 0;
	char usuario[MAX];
	char contrasenia[MAX];
	
	while(intentos<3 && log == 0){
		system("cls");
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tUsuario: ");
		gets(usuario);
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\tContraseña:");
		gets(contrasenia);
	
		if(strcmp(usuario, USUARIO) == 0 && strcmp(contrasenia,CONTRASENIA) == 0){
			log = 1;
		} else {
			printf("Usuario o contraseña incorrecto\n");
			intentos++;
			system("pause");
		}
	}	
	return log;
	
}
