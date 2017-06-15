#include<stdio.h>

int main(){

	int	d1, d2,
		m1, m2,
		a1, a2;

	printf("Digite uma data DD/MM/AAAA para comparação: ");
	scanf("%d/%d/%d",&d1,&m1,&a1);

	printf("Digite a segunda data DD/MM/AAAA: ");
	scanf("%d/%d/%d",&d2,&m2,&a2);

	if(a1 == a2)
		if(m1 == m2)
			if(d1 < d2)
				printf("%d/%d/%d\n",d1,m1,a1);
			else
				printf("%d/%d/%d\n",d2,m2,a2);
		else
			if(m1 < m2)
				printf("%d/%d/%d\n",d1,m1,a1);
			else
				printf("%d/%d/%d\n",d2,m2,a2);
	else
		if(a1 < a2)
			printf("%d/%d/%d\n",d1,m1,a1);
		else
			printf("%d/%d/%d\n",d2,m2,a2);
	

	return 0;
}

