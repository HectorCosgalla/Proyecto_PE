#include "stdio.h"
#include "stdbool.h"
#define MAX 3

/********** PROTOTIPO DE FUNCIONES **********/
void lecturaMatrices(int a[][MAX], int b[][MAX], int *, int *, int, int *);
void sumarMatrices(int a[][MAX], int b[][MAX], int, int);
void matrizEscalar(int a[][MAX], int, int, int);
void productoMatrices(int a[][MAX], int b[][MAX], int, int, int);
void matrizTranspuesta(int a[][MAX], int, int);

int main(){
  /********** DECLARACION DE VARIABLES **********/
  int a[MAX][MAX], b[MAX][MAX], n, m, opc, q, p;
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
      default:
        printf("ERROR: SELECCION ERRONEA\n");
        printf("\n");
        break;
    }
  } while(ban == false);
  return 0;
}

/********** FUNCIONES **********/
void lecturaMatrices(int a[][MAX], int b[][MAX], int *n, int *m, int opc, int *p) {
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
        scanf("%d", &a[i][j]);
        printf("B[%d][%d]: ", i, j);
        scanf("%d", &b[i][j]);
      }
      printf("\n");
    }
  }
  if (opc == 2 || opc == 4) {
    for (int i = 0; i < *n; i++) {
      for (int j = 0; j < *m; j++) {
        printf("A[%d][%d]: ", i, j);
        scanf("%d", &a[i][j]);
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
        scanf("%d", &a[i][j]);
      }
    }
    for (int i = 0; i < *m; i++) {
      for (int j = 0; j < *p; j++) {
        printf("B[%d][%d]: ", i, j);
        scanf("%d", &b[i][j]);
      }
    }
  }
}

void sumarMatrices(int a[][MAX], int b[][MAX], int n, int m) {
  int c[MAX][MAX];

  printf("C: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i][j] = a[i][j] + b[i][j];
      printf("%d  ", c[i][j]);
    }
    printf("\n");
  }
}

void matrizEscalar(int a[][MAX], int n, int m, int q) {
  int c[MAX][MAX];

  printf("C: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c[i][j] = q * a[i][j];
      printf("%d  ", c[i][j]);
    }
    printf("\n");
  }
}

void productoMatrices(int a[][MAX], int b[][MAX], int n, int m, int p){
  int c[MAX][MAX];
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
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }

}

void matrizTranspuesta(int a[][MAX], int n, int m){
  int b2[MAX][MAX];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      b2[j][i] = a[i][j];
    }
  }
  
  printf("C:\n");
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", b2[i][j]);
    }
    printf("\n");
  }
}
