#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

#define   MAX  4 /* máximo na fila */

int fila[MAX];
int inicioFila, finalFila, maximo, num;

char menuOpcoes (void)
{
	char opcao;
	system("cls");
	printf("\n _____________ GERENCIAMENTO FILA________________\n");
    printf("\n 1- Adicionar à fila");
    printf("\n 2- Remover da fila");
    printf("\n 3- Consultar fila");
    printf("\n 4- Sair");
    printf("\n ________________________________________________");
    printf("\n Escolha: ");
    fflush(stdin);
    opcao = getche();
    return opcao;      
}

void admin (char tecla)
{
	switch(tecla)
	{
		case '1': adiciona();
		break;
		
		case '2': removeFila();
		break;
		
		case '3': consultaFila();
		break;
		
		case'4': exit(0);
		
		default: printf("\n Opção inválida!!!!");
		
		getch();
	}
}

int adicionaFila (void)
{
	printf("\n Insira o número a ser adicionado: ");
	fflush (stdin);
	scanf("%d", &num);
	
	if(finalFila == MAX) /* valida se a fila está cheia */
	{
		printf("\n Fila lotada!!");
		getch();
	} else {
		fila[finalFila] = num;
		finalFila++;
	}
	
	getch();
}

int removeFila (void)
{
	int aux;
	if(inicioFila == finalFila) /* valida se a fila esta vazia */
	{
		printf("\n Fila vazia!!");
		inicioFila = finalFila = 0;
		getch();
	} else {
		printf("\n\n Número a ser removido: %02i", fila[inicioFila]);
		inicioFila++;
		maximo = finalFila;
		for (aux = 1; aux < maximo; aux++) /* faz com que todos da fila andem para frente */ 
		{
			fila[aux-1] = fila[aux];
		}
		inicioFila = 0;
		finalFila--;
	}
	getch();
}


int consultaFila (void)
{
	int i;
	printf("\n\n Números na fila: ");
	if(fila[MAX] == 0) /* valida se há pedidos na fila */
	{
		printf("nenhum!!");
	} else {
		for(i = inicioFila; i < finalFila; i++) /* varre pelos pedidos na fila */
		{
			printf("[%02i]", fila[i]);
		}
	}
	
	getch();
}


int main (void)
{	
	char opc;
	inicioFila = finalFila = 0; /* vila vazia */
	
	setlocale(LC_ALL, "");
	
	do{
        opc = menuOpcoes();              
        admin(opc);              
    }while(opc != '4');
	
	getch();	
	return 0;
}

