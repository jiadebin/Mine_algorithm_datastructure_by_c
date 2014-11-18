#include "head.h"

#include <stdio.h>
#include <stdlib.h>

struct Node{
    ElementType val;
    NodePtr next;
};

void PrintList(List L)
{
    Position p=L->next;
    while(p!=NULL){
        printf("%d, ", p->val);
        p=p->next;
    }
    printf("\n");
}

List MakeList()
{
    Position head = (Position)malloc(sizeof(struct Node));
    int val=1;
    Position p, q=head;
    while(val++<10){
        p=(Position)malloc(sizeof(struct Node));
        p->val=val;
        q->next=p;
        q=q->next;
    }
    q->next=NULL;
    return head;
}

int isEmpty(List L)
{
    return L->next==NULL;
}

int isLast(Position P, List L)
{
    return P->next==NULL;
}

Position Find(ElementType X, List L)
{
    Position p=L->next;
    while(p!=NULL&&p->val!=X)
        p=p->next;
    return p;
}

void Delete(ElementType X, List L)
{
    Position p=FindPrevious(X, L), temp;
    if(!isLast(p, L)){    //注意这句判断，如果p是last，那么说明没有找到X，即List中不存在X结点
        temp=p->next;
        p->next=temp->next;
        free(temp);
    }
}

Position FindPrevious(ElementType X, List L)
{
    Position pre=L;
    while(pre->next!=NULL&&pre->next->val!=X)
        pre=pre->next;
    return pre;
}

void Insert(ElementType X, List L, Position P)
{
    Position q=(Position)malloc(sizeof(struct Node));
    if(q==NULL)
        printf("malloc failed.");
    else{
        q->val=X;
        q->next=P->next;
        P->next=q;
    }
}

void DeleteList(List L)
{
    Position p=L->next, temp;
    L->next=NULL;
    while(p!=NULL){
        temp=p->next;
        free(p);
        p=temp;
    }
}
