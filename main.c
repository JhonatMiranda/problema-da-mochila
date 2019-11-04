#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "mochila.h"

//declaração de funções
int readFile(char*,int*,Mochila*);
int bruteforce(Mochila*,int,int,int*);

//função main
int main(int argc, char ** argv){

	//declaração de variáveis
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
	readFile(input,&size,&M);
	//cria o vetor selected para definir os itens selecionados
	selected = (int*) malloc(sizeof(int)*size);
	//chama a função bruteforce para selecionar os itens
	totalProfit = bruteforce(&M,size,capacity,selected);
	//printa as saidas
	printf("\nItens Selecionados: {");
	for(i=0;i<size;i++) {
		if(selected[i]==1) {
			totalWeight+=M.itens[i].weight;
			printf(" (Item%d, %d, %d),",i+1,M.itens[i].weight,M.itens[i].profit);
		}
	}
	printf(" }\n");

	printf("Valor Total = %d\n",totalProfit);
	printf("Peso Total = %d\n\n",totalWeight);

	//desaloca a memoria
	free(M.itens);
	free(selected);
	return 0;
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
			/*Copies the selected item in array. */
			for(j=0;j<size;j++)
				selected[j]=temp[j];
			result=maxProfit;
		}

		/*Calculate the next subset */
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
