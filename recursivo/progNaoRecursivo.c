/*  
	Crie um programa em C para calcular a soma dos numeros inteiros entre 1 e n, onde n é fornecido pelo usuario como entrada
	Crie duas funções soma (uma recursiva e outra não recursiva) que recebe como parametro de entrada o numero lido
*/

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <locale.h>

int main (void);
int fatorialNaoRec (int n);


int fatorialNaoRec (int n){
	int result, cont;
	result = 1;
	if(n != 0){
		for (cont = 1; cont <= n; cont ++){
			result = result * cont;
		}
	}
	return result;
}

int fatorialRec (int n){
	if (n == 0 || n == 1)
		return 1;
	else 
		return (n * fatorialRec (n-1)); 
}

int main (void){
	int num, resp;
	setlocale(LC_ALL, "");
	printf("\n ________________CALCULO DE FATORIAL________________ ");
	printf("\n Insira um número inteiro: ");
	fflush(stdin);
	scanf("%i", &num);
	
	resp = fatorialRec(num);
	printf("\n O fatorial de %i é igual a: %i", num, resp);
	getch();
	return 0;
}
