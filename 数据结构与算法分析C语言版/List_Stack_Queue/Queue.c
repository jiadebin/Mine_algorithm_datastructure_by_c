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
    return Q->rearPos == Q->frontPos;   //rear = frontʱ,��ʾ��
}

int IsFull(Queue Q){
    return (Q->rearPos+1)%Q->capacity == Q->frontPos;   //��rear��frontǰ��һ��λ��ʱ��ʾ��,��Ҫ�˷�һ��rear�Ŀռ�
}

Queue CreateQueue(int maxElements){
    if(maxElements < MINSIZE){
        printf("size too small.");
        return NULL;
    }
    Queue q = malloc(sizeof(struct QueueRecord));
    if(q==NULL)
        printf("malloc error.");

    q->capacity = maxElements+1;    //��Ϊrear�˷���һ��λ��,����Ҫ+1

    q->val = malloc( (maxElements+1)*sizeof(ElementType));  //������һ���ռ�,�������û����������
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
        Q->rearPos = (Q->rearPos+1)%Q->capacity;    //ʹ��ģ����ʵ��ѭ����������
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

