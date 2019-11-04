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
