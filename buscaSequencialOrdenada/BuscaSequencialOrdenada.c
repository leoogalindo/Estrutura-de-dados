#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 30

int buscaSequencial (int vet[], int numEncontrar, int tam){
	int k = 0;
	int flag = 0; // não encontrei
	
	while (k < tam && flag == 0){
		if(vet[k] == numEncontrar){
			flag = 1;
		} else {
			k++;
		}
	}	
}


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


int main (){
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int i, resp;
	int lista [TAM];
	
	for (i = 0; i < TAM; i++){
		lista [i] = rand() % 10;
		printf("[%d] ", lista[i]);
	}
	
	printf("\n\n ___________ ORDENANDO POR INSERTION SORT ___________\n\n");
	
	insertionSort(lista, TAM);
		
	resp = buscaSequencial(lista, 5, TAM); // passo como parametro o vetor, o numero que quero encontrar e o tamanho do vetor 
	printf("\n\nBusca Sequencial!");
	 
	if(resp < 0){
		printf("\nValor não encontrado");
	} else {
		printf("\nEncontrou o valor na posição %d: ", resp);
	}	
	
	getch();
	return 0;
}
