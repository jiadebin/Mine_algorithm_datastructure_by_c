#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

struct Node;
typedef struct Node * NodePtr;
typedef NodePtr Stack;

typedef int ElementType;

int IsEmpty(Stack S);
Stack CreateStack();
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif // STACK_H_INCLUDED
