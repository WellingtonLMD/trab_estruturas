#ifndef Fila_h
#define Fila_h

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    char request[100];
    struct nodo *proximo;
}Nodo;

    void push(Nodo *nodo);
    void pop();
    bool empty();
    int  size();
    void debug();
    void print();
    Nodo *front();

    Nodo *primeiro;
    Nodo *ultimo;
    int s; // size

#endif
