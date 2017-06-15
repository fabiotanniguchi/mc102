#include<stdio.h>

int main(){

	float a,b,c;

	printf("Digite três comprimentos de um triângulo: ");
	scanf("%f %f %f",&a,&b,&c);


	if( (a+b > c) && (a+c > b) && (b+c > a) ){
		if(a==b && b==c)
			printf("Triângulo equilátero\n");
		else
			if( (a==b) || (a==c) || (b==c) )
				printf("Triângulo isósceles\n");
			else
				printf("É um triângulo, e ele não é equilátero nem isósceles\n");
	}
	else
		printf("Não é um triângulo válido\n");

	return 0;
}

