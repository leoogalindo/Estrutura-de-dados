#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

void selectionSort (int vet [], int tam){
	int j, indiceMenor, k, aux;
	
	for(k = 0; k < tam - 1; k++){
		indiceMenor = k;
		for(j = k + 1; j < tam; j++){
			if(vet[j] < vet[indiceMenor]){
				indiceMenor = j; //a posição do menor elemento
			}
		}
		
		if(k != indiceMenor){ //comparo o primeiro elemento com o menor 
			aux = vet[k];
			vet[k] = vet[indiceMenor];
			vet[indiceMenor] = aux;
		}		
	}
	
	for(k = 0; k < tam; k++){
		printf("[%d] ", vet[k]);      	
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
	
	printf("\n\n ___________ ORDENANDO POR SELECTION SORT ___________\n\n");
	t = clock();
	selectionSort(lista, TAM);
	t = clock() - t;
	
	double tempo = (t / (CLOCKS_PER_SEC/1000));
	printf("\nTempo de execucao: %lf ", tempo);
	getch();
	return 0;
 
}
