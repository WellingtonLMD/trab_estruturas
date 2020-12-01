#include "stack.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

Stack *CreateStack(int size){
    Stack *stack;

    stack = (Stack *) malloc(sizeof(Stack));

    stack->valores = (int *) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int InsertStack(Stack *stack, int valor){
    if(stack->top + 1 == stack->size){
        return 0;
    }

    stack->top++;
    stack->valores[stack->top] = valor;

    return 1;
}

int RemoveStack(Stack *stack, int *valor){
    if(stack->top < 0){
        return 0;
    }

    *valor = stack->valores[stack->top];
    stack->top--;

    return 1;
}

void DestroyStack(Stack *stack){
    free(stack->valores);
    free(stack);
}


void ShuffleStack(Stack *stack){
    int i, j, n;
    int aux;
    
    srand(time(NULL));
    n = stack->top + 1;

    for(i = 0; i < n; i++){
        j = i + rand()%(n - i);

        aux = stack->valores[i];
        stack->valores[i] = stack->valores[j];
        stack->valores[j] = aux;
    }
}

void PrintStack(Stack *stack){
    int i;

    for(i = 0; i < stack->top + 1; i++){
        printf("%d ", stack->valores[i]);
    }
}
