#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "mochila.c"
#include "item.c"

/*Funtion declaration*/
int readFile(char*,int,int*,int*);
int bruteforce();

/*
* @brief: Main function where the execution starts
*/
int main(int argc, char ** argv){
	char *input;
	int i,totalProfit=0,totalWeight=0;
	int size;
	int capacity = 40;
	int *weight,*profit,*selected;
	Mochila M;
	if(argc!=2) {
		printf("\nError: Invalid number of arguments!\n\n");
		return 0;
	}
	input = argv[1];
	readFile(input,size,&weight,&profit);
	initMochila(M,size);
	selected = (int*) malloc(sizeof(int)*size);
	totalProfit = bruteforce();
	/*Prints the output*/
	printf("\nSelected Items: {");
	for(i=0;i<size;i++) {
		if(selected[i]==1) {
			totalWeight+=weight[i];
			printf(" (Item%d, %d, %d),",i+1,weight[i],profit[i]);
		}
	}
	printf(" }\n");

	printf("Total Profit = %d\n",totalProfit);
	printf("Total Weight = %d\n\n",totalWeight);

	/*Free the allocated memory*/
	free(selected);
	free(weight);
	free(profit);
	return 0;
}

/*
*@brief: Brute Force implementation of 0-1 Knapsack problem
*/
int bruteforce() {
	int i,j,isSelected=1,maxWt,maxProfit;
	int iter=pow(2.0,size);
	int result=0;
	int temp[size];
	/*Initialize the temp array */
	for(i =0;i<size;i++)
		temp[i]=0;

	for(i=0;i<iter;i++) {
		isSelected=1;
		maxProfit=0;
		maxWt=0;

		for(j=0;j<size;j++){
			if(temp[j]==1){
				maxWt+=weight[j];
				maxProfit+= profit[j];
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
int readFile(char * filename) {
	FILE *fp;
	int i=0;
	fp = fopen(filename,"r");
	if(fp == NULL) {
		printf("\nERROR in opening the file!\n\n");
		return 0;
	}
	while(!feof(fp)){
		if(i==0){
				fscanf(fp,"%d",&size);
				i++;
		}else{
		fscanf(fp,"%d,%d",&weight[i-1],&profit[i-1]);
		i++;
		}
	}
	fclose(fp);
	return 0;
}
