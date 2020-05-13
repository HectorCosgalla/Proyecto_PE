#include <stdio.h>
#include <stdlib.h>
#define max 2

void sumaMatrices(float A[max][max],float B[max][max],int f,int c);
void escalarMatrices(float A[max][max],int f,int c);
void multiplicarMatrices(float A[max][max],float B[max][max],int f,int c,int f2, int c2);

int main() {
	int f,c,f2,c2;
	printf("Introduce el tamaño de la matriz A: ");
	scanf("%i%i",&f,&c);
	float A[f][c];
	printf("Introduce el tamaño de la matriz B: ");
	scanf("%i%i",&f2,&c2);
	float B[f2][c2];
	for(int n=0;n<f;n++){
		for(int m=0;m<c;m++){
			printf ("\n Introduzca un valor en la posicion [%d][%d] de la matriz A:",n,m);
			scanf ("%f",&A[n][m]);
		}
	}
	for(int n=0;n<f2;n++){
		for(int m=0;m<c2;m++){
			printf ("\n Introduzca un valor en la posicion [%d][%d] de la matriz B:",n,m);
			scanf ("%f",&B[n][m]);
		}
	}
	//sumaMatrices(A,B,f,c);
	//escalarMatrices(A,f,c);
	multiplicarMatrices(A,B,f,c,f2,c2);
	system("pause");
	return 0;
}

void sumaMatrices(float A[][2],float B[][2],int f,int c){
	float C[f][c];
	for(int n=0;n<f;n++){
		for(int m=0;m<c;m++){
			C[n][m]=A[n][m]+B[n][m];
			printf("C[%i][%i]=%f\n",n,m,C[n][m]);
		}
	}	
}

void escalarMatrices(float A[max][max],int f,int c){
	float C;
	printf ("\n Introduzca el valor de C: ");
	scanf ("%f",&C);
	float B[f][c];
	for(int n=0;n<f;n++){
		for(int m=0;m<c;m++){
			B[n][m]=A[n][m]*C;
			printf("B[%i][%i]=%f\n",n,m,B[n][m]);
		}
	}	
}

void multiplicarMatrices(float A[max][max],float B[max][max],int f,int c,int f2,int c2){
	float C[f][c2];
	int acu,con;
	for(int n=0;n<f;n++){
		for(int m=0;m<c2;m++){
				for(acu=0,con=0;con<c;con++)
				acu+=A[n][con]*B[con][m];
				
				C[n][m]=acu;
		}
	}
	for(int n=0;n<f;n++){
		for(int m=0;m<c2;m++){
			printf("%f",C[n][m]);
		}
		puts("\n");
	}
}		
