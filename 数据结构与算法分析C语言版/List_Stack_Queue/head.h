#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

struct Node;
typedef struct Node * NodePtr;
typedef NodePtr List;
typedef NodePtr Position;

typedef int ElementType;

//List
int isEmpty(List L);
int isLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
void PrintList(List L);
List MakeList();


#endif // HEAD_H_INCLUDED
