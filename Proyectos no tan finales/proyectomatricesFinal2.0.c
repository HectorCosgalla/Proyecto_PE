#include "stdio.h"
#include "stdbool.h"
#include "math.h"
#define MAX 3

//Developed by Hector Cosgalla y Heberth Negron
/********** PROTOTIPO DE FUNCIONES **********/
void lecturaMatrices(float a[][MAX], float b[][MAX], int *, int *, int, int *);
void sumarMatrices(float a[][MAX], float b[][MAX], int, int);
void matrizEscalar(float a[][MAX], int, int, int);
void productoMatrices(float a[][MAX], float b[][MAX], int, int, int);
void matrizTranspuesta(float a[][MAX], int, int);
void inversaMatriz(float a[][MAX], int);
void sistemaEcuaciones(float a[][MAX], int, int);
float determinanteMatriz(float a[][MAX], int);
float cofactores(float a[][MAX], int n, int, int);
void metodoCramer(float a[][MAX], int, int);

int main(){
	/********** DECLARACION DE VARIABLES **********/
	float a[MAX][MAX], b[MAX][MAX];
	int n, m, opc, q, p;
	bool ban;
	n = 0;
	m = 0;
	opc = 0;
	q = 0;
	p = 0;
	ban = false;
	/********** ENTRADAS **********/
	/********** SALIDAS **********/
	/********** PROCESOS **********/
	do {
		printf("1) Suma de matrices (A+B)\n");
		printf("2) Escalar de una matriz (A*q)\n");
		printf("3) Producto de una matriz (A*B)\n");
		printf("4) Transpuesta de una matriz (a^T)\n");
		printf("5) Inversa de una matriz (a^-1)\n");
		printf("6) Solucion de metodo de ecuaciones(x1+x2+x3+...+xn=a)\n");
		printf("7) Determinante de una matriz\n");
		printf("8) Solucion de un sistema de ecuaciones por el metodo de Cramer\n");

		scanf("%d", &opc);
		switch (opc) {
		case 1:
			lecturaMatrices(a, b, &n, &m, opc, &p);
			sumarMatrices(a, b, n, m);
			ban = true;
			break;
		case 2:
			printf("Ingrese la constante a multiplicar: ");
			scanf("%d", &q);
			lecturaMatrices(a, b, &n, &m, opc, &p);
			matrizEscalar(a, n, m, q);
			ban = true;
			break;
		case 3:
			lecturaMatrices(a, b, &n, &m, opc, &p);
			productoMatrices(a, b, n, m, p);
			ban = true;
			break;
		case 4:
			lecturaMatrices(a, b, &n, &m, opc, &p);
			matrizTranspuesta(a, n, m);
			ban = true;
			break;
		case 5:
			lecturaMatrices(a, b, &n, &m, opc, &p);
			inversaMatriz(a, n);
			ban = true;
			break;
		case 6:
			lecturaMatrices(a, b, &n, &m, opc, &p);
			sistemaEcuaciones(a, n, m);
			ban = true;
			break;
		case 7:
			lecturaMatrices(a, b, &n, &m, opc, &p);
			printf("El determinante es: %f", determinanteMatriz(a,n));
			ban = true;
			break;
		case 8:
			puts("Introduzca el orden de la matriz y posteriormente los coeficientes de las variables");
			lecturaMatrices(a, b, &n, &m, opc, &p);
			metodoCramer(a, n, m);
			ban = true;
			break;
		default:
			printf("ERROR: SELECCION ERRONEA\n");
			printf("\n");
			break;
		}
	} while(ban == false);
	return 0;
}

/********** FUNCIONES **********/
void lecturaMatrices(float a[][MAX], float b[][MAX], int *n, int *m, int opc, int *p) {
	do {
		printf("Ingrese la cantidad de filas: ");
		scanf("%d", n);
		printf("Ingrese la cantidad de columnas: ");
		scanf("%d", m);
		if (*n > MAX || *m > MAX) {
			printf("ERROR: Matriz mas grande de la permitida\n");
			printf("\n");
		}
	} while(*n > MAX || *m > MAX);
	if (opc == 1) {
		for (int i = 0; i < *n; i++) {
			for (int j = 0; j < *m; j++) {
				printf("A[%d][%d]: ", i, j);
				scanf("%f", &a[i][j]);
				printf("B[%d][%d]: ", i, j);
				scanf("%f", &b[i][j]);
			}
			printf("\n");
		}
	}
	if (opc == 2 || opc == 4 || opc == 5 || opc == 6 || opc == 7 || opc == 8) {
		for (int i = 0; i < *n; i++) {
			for (int j = 0; j < *m; j++) {
				printf("A[%d][%d]: ", i, j);
				scanf("%f", &a[i][j]);
			}
		}
	}
	if (opc == 3) {
		do {
			printf("Ingrese la cantidad de columnas de B:");
			scanf("%d", p);
			if (*p > MAX) {
				printf("ERROR: Matriz mas grande de la permitida\n");
				printf("\n");
			}
		} while(*p > MAX);
		for (int i = 0; i < *n; i++) {
			for (int j = 0; j < *m; j++) {
				printf("A[%d][%d]: ", i, j);
				scanf("%f", &a[i][j]);
			}
		}
		for (int i = 0; i < *m; i++) {
			for (int j = 0; j < *p; j++) {
				printf("B[%d][%d]: ", i, j);
				scanf("%f", &b[i][j]);
			}
		}
	}
}

void sumarMatrices(float a[][MAX], float b[][MAX], int n, int m) {
	float c[MAX][MAX];

	printf("C: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c[i][j] = a[i][j] + b[i][j];
			printf("%f  ", c[i][j]);
		}
		printf("\n");
	}
}

void matrizEscalar(float a[][MAX], int n, int m, int q) {
	float c[MAX][MAX];

	printf("C: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c[i][j] = q * a[i][j];
			printf("%f  ", c[i][j]);
		}
		printf("\n");
	}
}

void productoMatrices(float a[][MAX], float b[][MAX], int n, int m, int p){
	float c[MAX][MAX];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			c[i][j] = 0;
		}
	}
	printf("C:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < m; k++) {
				c[i][j] = c[i][j] + a[i][k]*b[k][j];
			}
			printf("%f ", c[i][j]);
		}
		printf("\n");
	}

}

void matrizTranspuesta(float a[][MAX], int n, int m){
	float b2[MAX][MAX];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			b2[j][i] = a[i][j];
		}
	}

	printf("C:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%f ", b2[i][j]);
		}
		printf("\n");
	}
}

void inversaMatriz(float a[][MAX], int n){
	float c[MAX][MAX], inverso, negativo, desech, desech2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				c[i][j] = 1;
			} else {
				c[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (a[i][i] != 1) {
			inverso = 1 / a[i][i];
			for (int j = 0; j < n; j++) {
				a[i][j] = a[i][j] * inverso;
				c[i][j] = c[i][j] * inverso;
			}
		}
		for (int j = 0; j < n; j++) {
			if (j != i) {
				negativo = -a[j][i];
				for (int k = 0; k < n; k++) {
					desech = negativo * a[i][k];
					desech2 = negativo * c[i][k];
					a[j][k] = a[j][k] + desech;
					c[j][k] = c[j][k] + desech2;
				}
			}
		}
	}

printf("\n");
printf("A^-1: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%f   ", c[i][j] );
		}
		printf("\n");
	}
}

void sistemaEcuaciones(float a[][MAX], int n, int m){
	float inverso, negativo, desech;
	for (int i = 0; i < n; i++) {
		if (a[i][i] != 1) {
			inverso = 1 / a[i][i];
			for (int j = 0; j < m; j++) {
				a[i][j] = a[i][j] * inverso;
			}
		}
		for (int j = 0; j < n; j++) {
			if (j != i) {
				negativo = -a[j][i];
				for (int k = 0; k < m; k++) {
					desech = negativo * a[i][k];
					a[j][k] = a[j][k] + desech;
					printf("%f  ", a[j][k]);
				}
			}
		}
		printf("\n");
	}

	printf("Valores de:\n");
	for(int i=0; i<n; i++){
		printf("x%d =   %f", i, a[i][m-1]);
		printf("\n");
	}
}

float determinanteMatriz(float a[][MAX], int n){
	float det = 0;
	int j;
	if (n == 1) {
		det = a[0][0];
	} else {
		for (j = 0; j < n; j++) {
			det = det + a[0][j] * cofactores(a, n, 0, j);
		}
	}
	return det;
}

float cofactores(float a[][MAX], int n, int f, int c){
	float b[MAX][MAX];
	n = n - 1;
	int i, j;
	int x = 0;
	int y = 0;
	for (i = 0; i < n + 1; i++) {
		for (j = 0; j < n + 1; j++) {
			if (i != f && j != c) {
				b[x][y] = a[i][j];
				y++;
				if (y >= n) {
					x++;
					y = 0;
				}
			}
		}
	}
	return pow(-1, f + c) * determinanteMatriz(b, n);
}

void metodoCramer(float a[][MAX], int n, int m){
	float A, x ,y, z, w;
	float terminosIndependientes[MAX], b[MAX][MAX], c[MAX][MAX], d[MAX][MAX], e[MAX][MAX];
	puts("Introduzca los terminos independientes: ");
	for(int i = 0; i < n; i++){
		scanf("%f",&terminosIndependientes[i]);
		puts("\n");
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			b[i][j]=a[i][j];
			c[i][j]=a[i][j];
			//d[i][j]=a[i][j];
			//e[i][j]=a[i][j];
		}
	}
	for(int i = 0; i < n; i++){
		b[i][0]=terminosIndependientes[i];
	}
	for(int i = 0; i < n; i++){
		c[i][1]=terminosIndependientes[i];
	}
	/*for(int i = 0; i < n; i++){
		d[i][2]=terminosIndependientes[i];
	}
	for(int i = 0; i < n; i++){
		e[i][3]=terminosIndependientes[i];
	}*/
	A = determinanteMatriz(a, n);
	x = determinanteMatriz(b, n) / A;
	y = determinanteMatriz(c, n) / A;
	//z = determinanteMatriz(d, n) / A;
	//w = determinanteMatriz(e, n) / A;
	if(n==2){
		printf("x = %f\n", x);
		printf("y = %f\n", y);
	}
	/*if(n==3){
		printf("x = %f\n", x);
		printf("y = %f\n", y);
		printf("z = %f\n", z);
	}
	if(n==4){
		printf("x = %f\n", x);
		printf("y = %f\n", y);
		printf("z = %f\n", z);
		printf("z = %f\n", w);
	}*/
}
