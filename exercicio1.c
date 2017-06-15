#include<stdio.h>

int main(){

	float a, b, c;

	printf("Digite três números para ser exibido o maior deles: ");
	scanf("%f %f %f",&a,&b,&c);

	if(a<b && b<c)
		printf("%f\n",c);
	else
		if(a<b && b>c)
			printf("%f\n",b);
		else
			if(a>b && b<c)
				if(a>c)
					printf("%f\n",a);
				else
					printf("%f\n",c);
			else
				printf("%f\n",a);
	

	return 0;
}

