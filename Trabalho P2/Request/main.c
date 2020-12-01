#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Fila.h"

int main(void){
	setlocale(LC_ALL, "Portuguese");
    Nodo *head = inserirFila();
	Nodo *aux;//cria um ponteiro de nodo auxiliar para conseguir usar request da Fila.h
	int op=0;//usa tanto no while quanto no switch

	while(op!=4){
		//menu
		printf("=====Menu de Requests=====");
		printf("\n (1)Adicionar Nova Request");
		printf("\n (2)Visualizar primeiro e ultimo");
		printf("\n (3)Finalizar Request");
		printf("\n (4)Sair");
		printf("\n >");
		scanf("%d", &op);

		system("cls");

		switch(op){

			case 1:
				printf("=====Menu de Requests=====");
				printf("\n>(1)Adicionar Nova Request");

				/*Quando selecionada a opção 1, se cria um novo nodo
				para adicionar um novo 'Objeto' na Fila*/

				printf("\n\nNova request: ");
				scanf("%s", aux);//leitura da variável Nodo *auxiliar
				;//vai apontar para request, na Fila.h

				push(aux);//adiciona o valor passado em aux na Fila de requests

				printf("\n\n");
				system("cls");
				break;

			case 2:
				printf("=====Menu de Requests=====");
				printf("\n>(2)Visualizar primeiro e ultimo");
				//mostra quem está por ultimo e quem esta em primeiro
				//nas requests
				debug(aux);

				printf("\n\n");
				system("pause");
				system("cls");
				break;

			case 3:
				printf("=====Menu de Requests=====");
				printf("\n (1)Adicionar Nova Request");
				printf("\n (2)Visualizar primeiro e ultimo");
				printf("\n>(3)Finalizar Request");
				printf("\n (4)Sair");
				printf("\n\nRealizar request");

				//realiza a request da ponta(a primeira da fila)
				pop(aux);
				debug(aux);
				system("pause");
				system("cls");
				break;

			case 4:
				printf("=====Menu de Requests=====");
				printf("\n (1)Adicionar Nova Request");
				printf("\n (2)Visualizar primeiro e ultimo");
				printf("\n (3)Finalizar Request");
				printf("\n>(4)Sair");
				printf("\n\nSaindo...\n\n");
				system("pause");
				system("cls");
				break;

			default:
				printf("Operação inválida\n\n");
				system("pause");
				system("cls");
				break;
		}
	}
}
