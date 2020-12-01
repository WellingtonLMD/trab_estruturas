#include "List.h"
#include "MPlayer.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *CreateList(){
    LinkedList *list;

    list = (LinkedList *) calloc(1, sizeof(LinkedList));

    return list;
}


void InsertList(LinkedList *list, struct Music *music){
    Node *node;

    node = (Node *) malloc(sizeof(Node));
    node->music = music;

    if(list->begin == NULL){
        node->next = NULL;
        node->prev = NULL;
        list->begin = node;
        list->end = node;
    }else{
        node->next = NULL;
        node->prev = list->end;

        list->end->next = node;

        list->end = node; 
    }
}

void PrintList(LinkedList *list){
    Node *node;

    node = list->begin;

    while(node){        
        printf("Musica: %s\n", node->music->name);
        printf("Autor: %s\n\n", node->music->author);
    
        node = node->next;
    }
}


void DestroyList(LinkedList *list){
    Node *n, *aux;

    list->begin->prev = NULL;
    list->end->next = NULL;
    
    n = list->begin;

    while(n){
        aux = n->next;
        free(n);
        n = aux;
    }

    free(list);
}
