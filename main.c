#include "mochila.h"
//função main
int main(int argc, char ** argv){
	//declaração de variáveis
	double tempo;
	char *input;
	int i,totalProfit=0,totalWeight=0;
	int size;
	int capacity=40;
	int *selected;
	Mochila M;

	//verificar parâmetros da main
	if(argc!=2) {
		printf("\nErro: Argumentos da função main inválidos!\n\n");
		return 0;
	}
	input = argv[1];
	//chamada da função de ler arquivo
	clock_t timeIni= clock();
	readFile(input,&size,&M);
	//cria o vetor selected para definir os itens selecionados
	selected = (int*) malloc(sizeof(int)*size);
	//chama a função bruteforce para selecionar os itens
	totalProfit = bruteforce(&M,size,capacity,selected);
	//printa as saidas
	printada(&M,size,selected,totalWeight,totalProfit);
	//desaloca a memoria
	desaloca(&M,selected);
	//calculando e imprimindo o tempo
	timeIni = clock() - timeIni;
	tempo=((double)timeIni)/CLOCKS_PER_SEC;
	printf("Tempo:%lf\n",tempo );
	return 0;
}
