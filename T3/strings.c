#include<stdio.h>
#include<string.h>

/*
============================================
Lab 03 - Operações com Strings

Fábio Takahashi Tanniguchi - 145980 - MC102W
1º semestre - 2013
============================================
*/

int main(){
	char string[102], maiorPalavra[101], palavra[101], caracteres[256];
	char maisFrequente;
	int  maisPalavras = 0,
	     nCaracteres = 0,
	     qtdeVogais = 0,
	     nCharPalavra = 0,
	     nCharMaiorPalavra = 0,
	     caracterInt,
	     maiorFrequencia = 0,
	     i;

	for(i = 0; i<256; i++){
		caracteres[i] = 0; // zera vetor de caracteres ASCII
	}

	fgets(string,102,stdin);

	while(string[nCaracteres] != '\n'){
		caracterInt = (int)string[nCaracteres];

		if(string[nCaracteres] == 'A' || string[nCaracteres] == 'a' ||
		   string[nCaracteres] == 'E' || string[nCaracteres] == 'e' ||
		   string[nCaracteres] == 'I' || string[nCaracteres] == 'i' ||
		   string[nCaracteres] == 'O' || string[nCaracteres] == 'o' ||
		   string[nCaracteres] == 'U' || string[nCaracteres] == 'u'){
			qtdeVogais++;
		}

		if(string[nCaracteres] == ' '){
			if(nCharPalavra > nCharMaiorPalavra){ // palavra temporaria eh a maior
				nCharMaiorPalavra = nCharPalavra;

				palavra[nCharPalavra] = '\n'; // finaliza palavra
				palavra[nCharPalavra+1] = 0;

				strcpy(maiorPalavra,palavra);
			}
			nCharPalavra = 0;
			maisPalavras = 1;
		} else { // ainda nao chegamos ao final da palavra
			palavra[nCharPalavra] = string[nCaracteres];
			nCharPalavra++;
		}

		caracteres[caracterInt]++; // soma 1 na posicao ASCII do caracter

		nCaracteres++;
	}

	if(!maisPalavras || nCharPalavra > nCharMaiorPalavra){
	// verificacao necessaria para analisar a ultima palavra lida
	// ou quando so ha uma palavra lida (nunca chega em ' ' ao percorrer a string de entrada)
		palavra[nCharPalavra] = '\n'; // finaliza palavra
		palavra[nCharPalavra+1] = 0;

		strcpy(maiorPalavra,palavra);
	}

	for(i = 0; i<256; i++){
		if((caracteres[i] > maiorFrequencia) && (i >= 36) && (i <= 127)){
		// verifica maior frequencia nas posicoes ASCII de caracteres
		// coerentes (de 36 a 127), excluindo, portanto, caracteres de controle
			maiorFrequencia = caracteres[i];
			maisFrequente = (char)i;
		}
	}

	printf("%d; %s; %c; %d\n",qtdeVogais,maiorPalavra,maisFrequente,maiorFrequencia);

	return 0;
}

