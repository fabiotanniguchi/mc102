#include<stdio.h>

// Calcula media parcial do aluno
// - recebe os valores das 3 provas e dos 3 trabalhos
// - imprime na tela a media parcial
//
// MC102W - Fabio Takahashi Tanniguchi (RA 145980) 

int main(){
	float 	prova1,
		prova2,
		prova3,
		trab1,
		trab2,
		trab3,
		mediaProvas,
		mediaTrab,
		mediaParcial;

	// leitura os dados
	scanf("%f %f %f %f %f %f",&prova1,&prova2,&prova3,&trab1,&trab2,&trab3);

	// calculo de medias
	mediaProvas = (3*prova1 + 3*prova2 + 4*prova3)/10;
	mediaTrab = (trab1 + trab2 + trab3)/3;

	mediaParcial = (7*mediaProvas + 3*mediaTrab)/10;

	printf("%.2f\n",mediaParcial);

	return 0;
}

