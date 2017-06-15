#include <stdio.h>
#include <string.h>

/*
 * Verifica se a fila está cheia.
 * Retorna 1, caso positivo, ou 0, caso contrário.
 */
int cheia (int *fila, int *inicio, int *fim, int tamvetor){
	int tamanho = 0;

	if(*inicio<=*fim && *fim != -1){
		tamanho = *fim-*inicio+1;	
	} else {
		tamanho = tamvetor-*fim + *inicio + 2;
	}

	printf("Inicio %d Fim %d tamvetor %d tamanho%d\n",*inicio,*fim,tamvetor,tamanho);

	return(tamanho==tamvetor);
}

/*
 * Verifica se a fila está vazia.
 * Retorna 1, caso positivo, ou 0, caso contrário.
 */
int vazia (int *fila, int *inicio, int *fim, int tamvetor){
	int tamanho = 0;

	if(*inicio<=*fim){
		tamanho = *fim-*inicio+1;	
	} else {
		tamanho = tamvetor-*fim + *inicio + 2;
	}

	if(tamanho==0)
		return 1;
	return 0;
}

/*
 * Tenta inserir um elemento na fila.
 * Retorna o número do elemento ou -1 caso a fila esteja cheia.
 */
int inserir (int requisicao, int *fila, int *inicio, int *fim, int* tamvetor){
	int final = *fim;
	if(!cheia(fila,inicio,fim,*tamvetor)){
		*fim = *fim + 1;

		if(*fim != *tamvetor){
			*(fila+final) = requisicao;
		}else{
			*fim = 0;
			*(fila+0) = requisicao;
		}

		return 1;
	}

	return -1;

}

/*
 * Tenta remover um elemento da fila.
 * Retorna o número do elemento ou -1 caso a fila esteja vazia.
 */
int remover (int *fila, int *inicio, int *fim, int *tamvetor){
	int elemento;
	int inicial = *inicio;

	if(!vazia(fila,inicio,fim,*tamvetor)){
		
		elemento = *(fila+inicial);

		if(*inicio != *tamvetor-1)
			*inicio++;
		else
			*inicio=0;

		return elemento;
	}

	return -1;
}


/*
 * Imprime o estado atual da fila.
 */
void imprimir (int *fila, int *inicio, int *fim, int* tamvetor){
	int resultado;

	if(vazia(fila,inicio,fim,*tamvetor)){
		printf("Fila de impressao vazia.\n");
	} else {
		printf("Fila de impressao:");

		while(*fim != *inicio){
			resultado = remover(fila,inicio,fim,tamvetor);
			printf(" %d",resultado);
		}
		printf(".\n");
	}
}

int main(){
	// Vetor onde é armazenada a fila
	int fila[50];

	// Indicadores de início e de fim de fila
	int inicio = 0, fim = -1;

	// Guarda o tamanho máximo da fila de impressão
	int tamvetor = 0;

	// comando de entrada
	char entrada[30];
	char palavra[20];

	int i;

	int resultado,requisicao;

	scanf("%d",&tamvetor);

	do{
		i = 0;
		setbuf(stdin, 0);
		palavra[0] = 0;
		fgets(entrada,28,stdin);
		
		requisicao = 0;

		while(entrada[i] != '\n' && entrada[i] != ' '){
			palavra[i] = entrada[i];
			i++;
		}

		palavra[i] = 0;

		if(!strcmp(palavra,"iniciar")){
			resultado = remover(fila,&inicio,&fim,&tamvetor);
			if(resultado != -1){
				printf("Imprimindo requisicao %d.\n",resultado);
			} else {
				printf("Fila de impressao vazia.\n");
			}
		}

		if(!strcmp(palavra,"enviar")){
			// TROCAR POR SSCANF
			while(entrada[i] != '\n'){
				requisicao = (int)entrada[i]-48;
				i++;
			}

			resultado = inserir(requisicao,fila,&inicio,&fim,&tamvetor);
			if(resultado != -1){
				printf("Requisicao %d enviada para a fila de impressao.\n",requisicao);
			} else {
				printf("Fila de impressao cheia.\n");
			}
		}

		if(!strcmp(palavra,"imprimir")){
			imprimir(fila,&inicio,&fim,&tamvetor);
		}
		
	}while(strcmp(entrada,"FIM\n"));

	return 0;
}

