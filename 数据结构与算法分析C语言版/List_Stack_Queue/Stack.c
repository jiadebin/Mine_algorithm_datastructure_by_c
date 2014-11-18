#include "Stack.h"

#include <stdio.h>
#include <stdlib.h>

struct Node{
    ElementType val;
    NodePtr next;
};

int IsEmpty(Stack S){
    return S->next == NULL;
}

Stack CreateStack(){
    printf("create stack.\n");
    Stack S = malloc(sizeof(struct Node));
    if(S==NULL)
        printf("malloc failed\n");

    S->next = NULL; //1��ע����䲻Ҫ�������� IsEmpty ���жϳ���

    MakeEmpty(S);   //2��ע����Ҫ���� 1 ֮��,��Ҫ�ߵ�˳��

    return S;
}

void MakeEmpty(Stack S){
    printf("make empty.\n");
    if(S==NULL)
        printf("please create stack first.");
    else{
        while(!IsEmpty(S)){
            Pop(S);
        }
    }
}

void Push(ElementType X, Stack S){
    printf("push %d\n", X);
    NodePtr temp = malloc(sizeof(struct Node));
    temp->val = X;
    temp->next = S->next;
    S->next = temp;
}

ElementType Top(Stack S){
    if(IsEmpty(S)){
        printf("stack is null.");
        return 0;
    }
    else
        return S->next->val;
}

void Pop(Stack S){
    if(IsEmpty(S))
        printf("stack is empty");
    else{
        NodePtr temp = S->next;
        S->next = S->next->next;
        free(temp);
    }
}
