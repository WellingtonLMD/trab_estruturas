#ifndef STACK_H
#define STACK_H

typedef struct{
    int *valores;
    int size;
    int top;
}Stack;

Stack *CreateStack(int size);
int InsertStack(Stack *stack, int valor);
int RemoveStack(Stack *stack, int *valor);
void DestroyStack(Stack *stack);
void ShuffleStack(Stack *stack);
void PrintStack(Stack *stack);

#endif /* STACK_H */