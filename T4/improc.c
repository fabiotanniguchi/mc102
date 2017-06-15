#include<stdio.h>


/*
   "Processador de imagens"
    - recebe os valores (no de colunas, no de linhas e limiar)
    - faz, respectivamente, as operações de media local, negativo e limiar
    - retorna na tela a matriz resultante


   Fabio Takahashi Tanniguchi - RA 145980
   1o semestre 2013 - MC102W
*/

void mediaLocal(int entrada[25][25], int saida[25][25], int linhas, int colunas){
	int i,j,soma;

	for(i=1; i<(linhas-1); i++){
		for(j=1; j<(colunas-1); j++){
			// soma com a vizinhança e faz a media
			soma = entrada[i-1][j-1]
				+ entrada[i-1][j]
				+ entrada[i-1][j+1]
				+ entrada[i][j-1]
				+ entrada[i][j]
				+ entrada[i][j+1]
				+ entrada[i+1][j-1]
				+ entrada[i+1][j]
				+ entrada[i+1][j+1];

			soma = soma/9;

			// valor da media vai para a matriz resultante
			saida[i-1][j-1] = soma;
		}
	}
}

void negativo(int matriz[25][25], int linhas, int colunas){
	int i,j;

	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			matriz[i][j] = 255 - matriz[i][j];
		}
	}
}

void limiar(int matriz[25][25], int linhas, int colunas, int nLimiar){
	int i,j;

	for(i=0;i<linhas;i++){
		for(j=0;j<colunas;j++){
			if(matriz[i][j] < nLimiar){
				matriz[i][j] = 0;
			} else {
				matriz[i][j] = 255;
			}
		}
	}
}

int main(){
	int entrada[25][25];
	int saida[25][25];
	int linhas, colunas, nLimiar, i, j;

	scanf("%d %d %d",&colunas,&linhas,&nLimiar);

	// preenche a matriz com os dados de entrada
	for(i=0; i<linhas; i++){
		for(j=0;j<colunas;j++){
			scanf("%d",&entrada[i][j]);
		}
	}

	mediaLocal(entrada,saida,linhas,colunas);

	negativo(saida,linhas-2,colunas-2);

	limiar(saida,linhas-2,colunas-2,nLimiar);

	for(i=0; i<(linhas-2); i++){
		for(j=0; j<(colunas-2); j++){
			printf("%d ",saida[i][j]);

			if(j == colunas-3)
				printf("\n");
		}
	}

	return 0;
}

