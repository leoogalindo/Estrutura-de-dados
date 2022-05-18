#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define TAM 10

void selectionSort (int vet [], int tam){
	int j, indiceMenor, k, aux;
	indiceMenor = k;
	
	for(k = 0; k < tam - 1; k++){
		for(j = k + 1; j < tam; j++){
			if(vet[j] < vet[indiceMenor]){
				indiceMenor = j; //a posição do menor elemento
			}
		}
		
		if(vet[k] > vet[indiceMenor]){ //comparo o primeiro elemento com o menor 
			aux = vet[k];
			vet[k] = vet[indiceMenor];
			vet[indiceMenor] = aux;
		}		
	}
	
	for(k = 0; k < tam; k++){
		printf("[%d] ", vet[k]);      	
	}									
}

int buscaBinaria (int vet[], int numEncontrar, int inicio, int final){
	int meio = (inicio + final) / 2;
	
	if(final < inicio){
		return -1; //nao encontro o valor procurado
	}
	
	if(vet[meio] == numEncontrar){
		return meio;
	} else if (numEncontrar < vet[meio]){
		return buscaBinaria(vet, numEncontrar, inicio, meio-1);
	} else {
		return buscaBinaria(vet, numEncontrar, meio+1, final);
	}
	
}


int main (){
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int i;
	int lista [TAM];
	int resp;
	
	for (i = 0; i < TAM; i++){
		lista [i] = rand() % 100;
		printf("[%d] ", lista[i]);
	}
	
	printf("\n\n ___________ ORDENANDO POR SELECTION SORT ___________\n\n");
	
	selectionSort(lista, TAM);
	
	resp = buscaBinaria(lista, 20, 0, TAM-1); // passo como parametro meu vetor, o numero que eu quero encontrar, o inicio do vetor, e o final
	
	printf("\n\nBusca binária!");
	if(resp < 0){
		printf("\nValor não encontrado");
	} else {
		printf("\nEncontrou o valor na posição %d: ", resp);
	}
	
	getch();
	
	getch();
	return 0;
}
