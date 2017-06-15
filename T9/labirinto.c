#include <stdio.h>

void leituraDados(char matriz[25][25], FILE *arqEntrada, int *nLinha, int *nColuna, int *nLinhaInicial, int *nColunaInicial){
	int i, j;
	char aux;

	*nLinha = 0;
	*nColuna = 0;

	fscanf(arqEntrada, "%d %d", nLinha, nColuna);

	fscanf(arqEntrada, "%d %d", nLinhaInicial, nColunaInicial);

	for(i = 0; i < *nLinha; i++){
		for(j = 0; j < *nColuna; j++)
				fscanf(arqEntrada, "%c", &matriz[i][j]);
		fscanf(arqEntrada, "%c", &aux);
	}
}

void menorCaminho(){

}

void escreveDados(char matriz[25][25], FILE *arqSaida, int nLinha, int nColuna){
	int i,j;
	for(i = 0; i < nLinha; i++){
		for(j = 0; j < nColuna; j++){
			if(i == 0 && j == 0)
			    continue;
			else
			    fprintf(arqSaida,"%c",matriz[i][j]);
		}
	}
}

int main (int argc, char *argv[]){
	char matriz[25][25];

	int nLinha, nColuna, nLinhaInicial, nColunaInicial;

	FILE *arqEntrada, *arqSaida;
	
	arqEntrada = fopen(argv[1], "r");
	arqSaida = fopen(argv[2],"w");

	if (arqEntrada != NULL){
		leituraDados(matriz, arqEntrada, &nLinha, &nColuna, &nLinhaInicial, &nColunaInicial);
		menorCaminho();
		escreveDados(matriz, arqSaida, nLinha, nColuna);
	}

	fclose(arqEntrada);
	fclose(arqSaida);

	return 0;
}

