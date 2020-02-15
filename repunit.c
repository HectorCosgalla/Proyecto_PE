//repunit

#include <stdio.h>
#include <stdbool.h>

//comentario

int main(){
	int num,y;
	bool x=true;
	printf("Introduzca el numero a evaluar: ");
	scanf("%i",&num);
	while(num>0){
		y=num%10;
		num=(num-y)/10;
		if(y!=1){
			x=false;
		}
	}
	if (x==true){
		printf("El numero es repunit");
	}
	if (x==false){
		printf("El numero no es repunit");
	}
	return 0;
}

/**** HOLA HEBETH, TE ESTOY OBSERVANDO OwO ****/
