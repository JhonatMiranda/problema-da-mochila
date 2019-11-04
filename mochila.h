#include <stdio.h>
#include <stdlib.h>
//definindo estruturas
typedef struct Item{
  int weight;
  int profit;
}Item;
typedef struct {
    Item *inicio;
    Item *itens;
}Mochila;
//declarando funções
void initMochila(Mochila *M,int size);
void insertItem(Mochila *M,int peso, int valor,int i);
