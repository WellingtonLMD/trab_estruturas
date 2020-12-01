#ifndef LIST_H
#define LIST_H

struct Music;


typedef struct Node{
    struct Music *music;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct{
    Node *begin;
    Node *end;
}LinkedList;

LinkedList *CreateList();
void InsertList(LinkedList *list, struct Music *music);
void PrintList(LinkedList *list);
void DestroyList(LinkedList *list);

#endif
