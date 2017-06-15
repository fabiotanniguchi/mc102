#include<stdio.h>

/*
 Calcula media parcial do aluno
 - recebe os valores das 3 provas, dos 3 trabalhos e do exame final
   (caso não tenha feito exame deve ser inputado valor -1)
 - imprime na tela se o aluno foi aprovado

 MC102W - Fabio Takahashi Tanniguchi (RA 145980)
*/

int main(){
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

	// leitura os dados
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

	if(mediaFinal < 5){
		printf("Reprovado\n");
	}else{
		printf("Aprovado\n");
	}

	return 0;
}

