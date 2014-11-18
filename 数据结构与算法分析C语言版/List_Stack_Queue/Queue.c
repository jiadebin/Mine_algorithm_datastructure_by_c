#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>

#define MINSIZE ( 5 )

struct QueueRecord{
    int capacity;
    int frontPos;
    int rearPos;
    int sizeEle;
    ElementType *val;
};

int IsEmpty(Queue Q){
    return Q->rearPos == Q->frontPos;   //rear = front时,表示空
}

int IsFull(Queue Q){
    return (Q->rearPos+1)%Q->capacity == Q->frontPos;   //即rear在front前面一个位置时表示满,需要浪费一个rear的空间
}

Queue CreateQueue(int maxElements){
    if(maxElements < MINSIZE){
        printf("size too small.");
        return NULL;
    }
    Queue q = malloc(sizeof(struct QueueRecord));
    if(q==NULL)
        printf("malloc error.");

    q->capacity = maxElements+1;    //因为rear浪费了一个位置,所以要+1

    q->val = malloc( (maxElements+1)*sizeof(ElementType));  //多申请一个空间,，满足用户需求的数量
    if(q->val == NULL)
        printf("val malloc error");
    MakeEmpty(q);

    return q;
}

void DisposeQueue(Queue Q){
    if(Q != NULL){
        free(Q->val);
        free(Q);
    }
}

void MakeEmpty(Queue q){
    q->frontPos = 0;
    q->rearPos =0;
    q->sizeEle = 0;
}

void Enqueue(ElementType X, Queue Q){
    if(!IsFull(Q)){
        Q->val[Q->rearPos] = X;
        Q->rearPos = (Q->rearPos+1)%Q->capacity;    //使用模操作实现循环数组利用
        Q->sizeEle++;
    }
    else
        printf("Queue is full.");
}

ElementType Front(Queue Q){
    ElementType x;
    if(!IsEmpty(Q)){
        x = Q->val[Q->frontPos];
    }
    else
        printf("queue is empty.");
    return x;
}

void Dequeue(Queue Q){
    if(!IsEmpty(Q)){
        Q->sizeEle --;
        Q->frontPos = (Q->frontPos+1)%Q->capacity;
    }
    else
        printf("queue is empty.");
}

ElementType FrontAndDequeue(Queue Q){
    ElementType x;
    if(!IsEmpty(Q)){
        x = Q->val[Q->frontPos];
        Dequeue(Q);
    }
    else
        printf("queue is empty.");
    return x;
}

