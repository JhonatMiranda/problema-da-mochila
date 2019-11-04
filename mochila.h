#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <time.h>
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
int readFile(char*,int*,Mochila*);
int bruteforce(Mochila*,int,int,int*);
void desaloca(Mochila *M,int *selected);
void printada(Mochila *M,int size,int *selected,int totalWeight,int totalProfit);
