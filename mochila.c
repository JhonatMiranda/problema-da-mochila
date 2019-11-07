#include "mochila.h"
void initMochila(Mochila *M,int size){
	//Cria um array de itens
	M->itens = (Item*) malloc(sizeof(Item)*size);
	M->inicio = &(M->itens[0]);
}
void insertItem(Mochila *M,int peso, int valor,int i){
	//insere os valores dos itens nos itens
		M->itens[i].weight=peso;
  	M->itens[i].profit=valor;
}
//função para calcular e escolher a melhor combinação
int bruteforce(Mochila *M,int size,int capacity,int *selected) {
	//declaração de variáveis
	int i,j,isSelected=1,maxWt,maxProfit;
	int iter=pow(2.0,size);
	int result=0;
	int temp[size];
	//inicializa o vetor temporário
	for(i =0;i<size;i++){
		temp[i]=0;
	}
	//calcula todos os subcojuntos passanda um por um
	for(i=0;i<iter;i++) {
		isSelected=1;
		maxProfit=0;
		maxWt=0;

		for(j=0;j<size;j++){
			if(temp[j]==1){
				maxWt+=M->itens[j].weight;
				maxProfit+= M->itens[j].profit;
			}
		}
		if( maxWt <= capacity && maxProfit>result){
			//copia os itens selecionados para o vetor selected
			for(j=0;j<size;j++)
				selected[j]=temp[j];
			result=maxProfit;
		}

		//calcula o proximo subconjunto
		for(j=0;j<size;j++){
			temp[j]=temp[j]+isSelected;
			isSelected = temp[j]/2;
			temp[j]=temp[j]%2;
		}
	}
	return result;
}

int readFile(char * filename,int *tamanho,Mochila *M) {
	//declaração de variáveis
	FILE *fp;
	int i=0,weight=0,profit=0;
	fp = fopen(filename,"r");
	//verifica se o ponteiro tem conteudo
	if(fp == NULL) {
		printf("\nERROR in opening the file!\n\n");
		return 0;
	}
	//le a quantidade de itens e os valores
	fscanf(fp,"%d",tamanho);
	//inicializa a mochila
	initMochila(M,*tamanho);
	for(i=0;i<*tamanho;i++){
			fscanf(fp,"%d,%d",&weight,&profit);
			insertItem(M,weight,profit,i);
	}
	//fecha o arquivo
	fclose(fp);
	return 0;
}
void desaloca(Mochila *M,int *selected){
	free(M->itens);
	free(selected);
}
void printada(Mochila *M,int size,int *selected,int totalWeight,int totalProfit){
	int i;
	printf("\nItens Selecionados: {");
	for(i=0;i<size;i++) {
		if(selected[i]==1) {
			totalWeight+=M->itens[i].weight;
			printf(" (Item%d, %d, %d),",i+1,M->itens[i].weight,M->itens[i].profit);
		}
	}
	printf(" }\n");

	printf("Valor Total = %d\n",totalProfit);
	printf("Peso Total = %d\n\n",totalWeight);
}
