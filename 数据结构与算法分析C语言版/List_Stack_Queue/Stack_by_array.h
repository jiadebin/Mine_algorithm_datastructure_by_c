#ifndef STACK_BY_ARRAY_H_INCLUDED
#define STACK_BY_ARRAY_H_INCLUDED

struct StackRecord;
typedef struct StackRecord * NodePtr;
typedef NodePtr Stack;

typedef int ElementType;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int maxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);

#endif // STACK_BY_ARRAY_H_INCLUDED
