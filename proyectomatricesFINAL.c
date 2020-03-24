#include "stdio.h"
#include "stdbool.h"
#define MAX 3
//Hecho por: Hecot cosgalla y Hebeth Negron
/********** PROTOTIPO DE FUNCIONES **********/
void lecturaMatrices(float a[][MAX], float b[][MAX], int *, int *, int, int *);
void sumarMatrices(float a[][MAX], float b[][MAX], int, int);
void matrizEscalar(float a[][MAX], int, int, int);
void productoMatrices(float a[][MAX], float b[][MAX], int, int, int);
void matrizTranspuesta(float a[][MAX], int, int);
void inversaMatriz(float a[][MAX], int);

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
	if (opc == 2 || opc == 4 || opc == 5) {
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

printf("A^-1: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%f   ", c[i][j] );
		}
		printf("\n");
	}

/*	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%f   ", a[i][j] );
		}
		printf("\n");
	}
	float c[MAX][MAX], pivote;
	int m, x, y, i, j, k, l;
	for(i=0; i<n; i++)
	{
		j=i;
		pivote=a[i][j];
		c[i][j]=1/pivote;
		for(m=0; m<n; m++){
			if(m != i){
				c[i][m]=a[i][m]/pivote;
				c[m][j]=-a[m][j]/pivote;
			}
		}
		for(x=0 ;x<n; x++){
			for(y=0; y<n; y++){
				if(x!=i && y!=j){
					c[x][y]=a[x][y]-(a[i][y]*a[x][j])/pivote;
				}
			}
		}
		for(k=0; k<n; k++){
			for(l=0; l<n; l++){
				a[k][l]=c[k][l];
			}
		}
	}
	printf("C:\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%f  ",c[i][j]);
		}
		puts("\n");
	} */
}
