#include "Stack_by_array.h"

#include <stdio.h>
#include <stdlib.h>

#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

struct StackRecord{
    int capacity;
    int topOfStack;
    ElementType *val;
};

int IsEmpty(Stack S){
    return S->topOfStack == EmptyTOS;
}

int IsFull(Stack S){
    return S->topOfStack == ( S->capacity - 1 );
}

Stack CreateStack(int maxElements){
    if(maxElements < MinStackSize){
        printf("size too small.");
        return NULL;
    }
    Stack S = malloc(sizeof(struct StackRecord));
    if(S == NULL){
        printf("malloc error.");
        return NULL;
    }
    S->capacity = maxElements;

    S->val = malloc(maxElements*sizeof(ElementType));
    if(S->val == NULL){
        printf("val malloc error.");
    }
    MakeEmpty(S);

    return S;
}

void DisposeStack(Stack S){
    if(S != NULL){
        free(S->val);
        free(S);
    }
}

void MakeEmpty(Stack S){
    S->topOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S){
    if(!IsFull(S)){
        S->val[++S->topOfStack] = X;
    }
    else
        printf("stack already full.");
}

ElementType Top(Stack S){
    return S->val[S->topOfStack];
}

void Pop(Stack S){
    if(!IsEmpty(S)){
        S->topOfStack --;
    }
    else
        printf("stack already empty.");
}

ElementType TopAndPop(Stack S){
    ElementType x;
    if(!IsEmpty(S)){
        x = Top(S);
        Pop(S);

    }
    else{
        printf("stack is empty.");
    }
    return x;
}

