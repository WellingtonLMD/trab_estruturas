#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct fila{
    char requests[100];
    struct Fila *proximo;
}Fila;

Fila* inserirFila(){
    primeiro = 0;
    ultimo = 0;
    s = 0;
}

bool empty(){
    if (s > 0){
        return false;
	}
    else{
        return true;
	}
}

void push(Nodo *novoItem){
    if(empty()){
        primeiro = novoItem;
        ultimo = novoItem;
    }

    else{
        ultimo->proximo = novoItem;
        ultimo = novoItem;
    }
    s++;
}

void debug(){
	printf("Tamanho: %d\n", s);

	if(s==1){
		printf("Apenas o seguinte item: %s", primeiro->request);
	}

    else if(s>1){
        printf("Primeiro da Fila: " , primeiro->request);
        printf("Ultimo da Fila: " , ultimo->request);

    }
}

void Filaprint(Nodo *novo){
	int cont, i;

	for(cont=0, i=0; cont<s; cont++){

		printf("%c", novo->request);

	}


}

void pop(){
    if(empty()){
        printf("Fila vazia, nao ha o que remover.\n");
     }

	 else if (s==1){
         //zera a estrutura quando remove o ultimo
         primeiro = 0;
         ultimo = 0;
         s = 0;
     }

     else{
         primeiro = primeiro->proximo;
         s--;
     }
}

Nodo* front()
{
    return primeiro;
}

int size()
{
    return s;
}
