#include <stdio.h>
#include <stdlib.h>

//#include "head.h"
#include "Queue.h"

int main()
{
    /*
    //List
    List L=MakeList();
    PrintList(L);

    printf("%d, %d\n", isEmpty(L), FindPrevious(7, L));
    Delete(7, L);
    PrintList(L);


    //Stack
    Stack s = CreateStack(10);
    int i=0;
    for(i=0; i<10; i=i+2)
    {
        Push(i, s);
    }

    while(!IsEmpty(s))
    {
        int x = TopAndPop(s);
        printf("%d\n", x);
    }
    */
    int i;
    Queue q = CreateQueue(5);
    for(i=0; i<12; i=i+2)
    {
        Enqueue(i, q);
    }

    while(!IsEmpty(q))
    {
        int x = FrontAndDequeue(q);
        printf("%d\n", x);
    }
    return 0;
}
