#include<stdio.h>

int main(){

	float a, b, c;

	printf("Digite três números para ser exibido o maior deles: ");
	scanf("%f %f %f",&a,&b,&c);

	if(a<b && b<c)
		printf("%f %f %f\n",a,b,c);
	else
		if(a<b && b>c)
			if(c<a)
				printf("%f %f %f\n",c,a,b);
			else
				printf("%f %f %f\n",a,c,b);
		else
			if(a>b && b<c)
				if(a>c)
					printf("%f %f %f\n",b,c,a);
				else
					printf("%f %f %f\n",b,a,c);
			else
				printf("%f %f %f\n",c,b,a);
	

	return 0;
}

