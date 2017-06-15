#include<stdio.h>

/*
 Verifica aprovação de vários alunos
 - pede primeiramente o número n de alunos
 - pede nas notas das provas, trabalhos e do exame (caso tenha feito)
   dos n alunos
 - imprime na tela se os n alunos foram aprovados

 MC102W - Fabio Takahashi Tanniguchi (RA 145980)
*/

int main(){

	unsigned int nAlunos, iterador;

	float 	prova1,
		prova2,
		prova3,
		trab1,
		trab2,
		trab3,
		exame,
		mediaProvas,
		mediaTrab,
		mediaParcial,
		mediaFinal;

	// leitura do numero de alunos a serem processados
	scanf("%d",&nAlunos);

	for(iterador = 1; iterador <= nAlunos; iterador++){

		// leitura das notas
		scanf("%f %f %f %f %f %f %f",&prova1,&prova2,&prova3,&trab1,&trab2,&trab3,&exame);

		if(exame == -1){
			exame = 0;
		}

		// calculo de medias
		mediaProvas = (3*prova1 + 3*prova2 + 4*prova3)/10;
		mediaTrab = (trab1 + trab2 + trab3)/3;

		mediaParcial = (7*mediaProvas + 3*mediaTrab)/10;

		if(mediaParcial < 5){
			mediaFinal = (mediaParcial + exame)/2;
		}else{
			mediaFinal = mediaParcial;
		}

		// imprime se foi aprovado ou nao
		if(mediaFinal < 5){
			printf("Reprovado\n");
		}else{
			printf("Aprovado\n");
		}

	};

	return 0;
}

