#include<stdio.h>
#include<string.h>
#include<tgmath.h>

/*
Parque de Diversoes
Lab de MC102 - Turma W

Fabio Takahashi Tanniguchi - RA 145980
1o semestre 2013
*/

int main(){
	char nomeEntrada[50];
	float precoEntrada;
	int prioridadeEntrada;

	float dinheiro;
	float precos[16];

	int contadorBrinquedos = 0;
	double qtdeBrinquedos = 0;
	int i;
	double referencia = 0.0;

	scanf("%f",&dinheiro); // leitura do dinheiro que Rodka tem

	for(i = 0; i<16; i++){
		precos[i] = -1; // inicializacao do vetor de precos
				// das atracoes
	}

	do{
		scanf("%s",nomeEntrada);

		if(strcmp(nomeEntrada,"0;0;0") == 0){
			break;
		}

		// ja que nao eh o final do processamento
		// lemos o preco da atracao e a prioridade dela
		scanf(" ; %f ; %d",&precoEntrada,&prioridadeEntrada);

		// o preco da atracao vai no vetor de precos
		// na posicao de sua prioridade
		precos[prioridadeEntrada] = precoEntrada;

		qtdeBrinquedos++;

	}while(precoEntrada >= 0);
	
	do{
		if(precos[contadorBrinquedos+1] < dinheiro){ // se ainda da para ir na proxima atracao do vetor
			contadorBrinquedos++;
			dinheiro = dinheiro - precos[contadorBrinquedos];
		} else {
			break; // nao da para ir em mais atracoes
		}
	}while(precos[contadorBrinquedos+1] != -1); // caso va em todas as atracoes

	referencia = (2.0 * qtdeBrinquedos)/3.0;

	referencia = ceil(referencia);

	if(dinheiro <= 0){
		printf("Rodka nao vai ao parque.\n");
		return 0;
	}

	if((double)contadorBrinquedos >= referencia){
		printf("Rodka vai ao parque.\n");
		printf("Ira em %d brinquedos.\n",contadorBrinquedos);
		printf("E lhe sobrarao %.2f reais.\n",dinheiro);
	}else{
		printf("Rodka nao vai ao parque.\n");
	}
	
	return 0;
}

