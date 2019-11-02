#include "mochila.h"
void initMochila(Mochila M,int size){
  //Create itens array
	M->itens = (Item*) malloc(sizeof(Item)*size);
}
void insertItem(Mochila M,int valor, int peso){
  M.itens.weight=peso;
  M.itens.profit=valor;
}
