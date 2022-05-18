#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define TAM 10000

int bubbleSort (int vet [], int tam){
	int k, j, aux;
	
	for (k = 1; k < tam; k++){
		
		for(j = 0; j < tam - k; j++){
			
			if(vet[j] > vet[j + 1]){
				aux = vet[j];
				vet[j] = vet[j + 1];
				vet[j + 1] = aux;
			}
		}
	}
	
	for (k = 0; k < tam; k++){
		printf("[%d] ", vet[k]);
	}	

}


int main(void){
	clock_t t; //tipo da variavel
	srand(time(NULL));
	int i;
	int lista [TAM];
	
	for (i = 0; i < TAM; i++){
		lista [i] = rand() % 100;
		printf("[%d] ", lista[i]);
	}
	
	printf("\n\n __________________________________________ ORDENANDO POR BUBBLE SORT _________________________________________\n\n");
	t = clock(); //começa a contar
	bubbleSort(lista, TAM);
	t = clock() - t; // tempo final menos inicial
	
	double tempo = (t / (CLOCKS_PER_SEC/1000)); //transformando para milisegundos
	printf("\nTempo de execucao: %lf ", tempo);
	getch();
	return 0;
 
}
