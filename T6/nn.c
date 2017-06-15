#include<stdio.h>
#include<math.h>

/*
	Laboratorio 06 de MC102
	Vizinho mais proximo (usando vetores) por distancia euclidiana

	Fabio Takahashi Tanniguchi - RA 145980
	MC102W - 1o semestre 2013
*/

void calcularMaisProximos(int nDimensoes, float vetores[20][20], int nClasses, float testes[20][20], int nTestes, int maisProximos[20]){

	int i, j, k;
	float menorDistancia;
	float distancia;
	int indiceMaisProximo;
	int primeiraVez = 1;
	float somatorio = 0.0;

	for(i=0; i<nTestes; i++){
		primeiraVez = 1;

		for(j=0; j<nClasses; j++){

			for(k=0; k<nDimensoes; k++){
				somatorio += pow(testes[i][k] - vetores[j][k],2.0);
			}
			distancia = sqrt(somatorio);
			// distancia = raiz quadrada do somatorio ((xi - yi)^2)

			somatorio = 0.0; // zera o somatorio

			if(primeiraVez){ // na primeira vez vamos pegar a distancia
					// e o indice como se fosse o mais proximo
					// para servir de parametro as futuras comparacoes
				menorDistancia = distancia;
				indiceMaisProximo = j;
				primeiraVez = 0; // nao sera mais primeiraVez nas proximas vezes
			} else {
				if(distancia <= menorDistancia){ // achada distancia ainda menor
					menorDistancia = distancia;
					indiceMaisProximo = j;
				}
			}

			distancia = 0.0;
		}
		maisProximos[i] = indiceMaisProximo; // o indice mais proximo
						     // da posicao i do vetor de teste
						     // eh guardado
	}
}

int main(){
	int nDimensoes = 0, nClasses = 0, nTestes = 0;
	float vetores[20][20], testes[20][20];
	int maisProximos[20];
	int i,j;

	// lendo dimensoes, numero de classes e numero de testes
	scanf("%d %d %d",&nDimensoes,&nClasses,&nTestes);

	for(i=0; i< nClasses; i++){ // lendo vetor de classes
		for(j=0; j<nDimensoes; j++){
			scanf("%f",&vetores[i][j]);
		}
	}

	for(i=0; i< nTestes; i++){ // lendo vetor de testes
		for(j=0; j<nDimensoes; j++){
			scanf("%f",&testes[i][j]);
		}
	}

	// sera feito o calculo dos mais proximos de cada elemento de teste guardando
	// os indices no vetor maisProximos
	calcularMaisProximos(nDimensoes, vetores, nClasses, testes, nTestes, maisProximos);

	for(i=0; i<nTestes; i++){ // percorre vetor e imprime
		printf("%d\n",maisProximos[i]);
	}

	return 0;
}

