#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

void insertionSort (int vet[], int tam){
	int j, k, aux;
	for(j = 1; j < tam; j++){
		k = j;
		while(vet[k] < vet[k - 1]){
			aux = vet[k];
			vet[k] = vet[k - 1];
			vet[k - 1] = aux;
			k--;
			
			if(k == 0){
				break;
			}
		}
	}
	
	for(j = 0; j < tam; j++){
		printf("[%d] ", vet[j]);
	}
	
}


int main(void){
	clock_t t;
	srand(time(NULL));
	int i;
	int lista [TAM];
	
	for (i = 0; i < TAM; i++){
		lista [i] = rand() % 100;
		printf("[%d] ", lista[i]);
	}
	
	printf("\n\n ___________ ORDENANDO POR INSERTION SORT ___________\n\n");
	t = clock();
	insertionSort(lista, TAM);
	t = clock() - t;
	
	double tempo = (t / (CLOCKS_PER_SEC/1000));
	printf("\nTempo de execucao: %lf ", tempo);
	getch();
	return 0;
 
}
