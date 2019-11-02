#include <stdio.h>
#include <stlib.h>
//definindo estrutura
typedef struct Item{
  int weight;
  int profit;
} Item;
typedef struct {
    PCelula inicio;
    Item *items;
}Mochila;
void initMochila(Mochila M);
void insertItem(Mochila M,int valor, int peso);
