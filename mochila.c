#include "mochila.h"
void initMochila(Mochila M,int size){
  //Create itens array
	M->itens = (Item*) malloc(sizeof(Item)*size);
	M->inicio =&(M->itens[0])
}
void insertItem(Mochila M,int valor, int peso){
  M.itens.weight=peso;
  M.itens.profit=valor;
}
