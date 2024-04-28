#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Merge(List L1, List L2)
{
    List p1, p2;
    List pm;
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p1 = L1->Next;
    p2 = L2->Next; // 注意题目中是有头结点的所以要用p1=L1->Next;而不是p1=L1；
    pm = p;
    while (p1 != NULL && p2 != NULL) // 注意题目中说了利用原来的节点所以不用每次都开辟
    // 一个空间然后把data存进去；但是需要开辟一个空间用来存放新的链表的头结点
    {
        if (p1->Data < p2->Data)
        {
            p->Next = p1;
            p = p->Next;
            p1 = p1->Next;
            // p->Next=Null;
        }
        else
        {
            p->Next = p2;
            p = p->Next;
            // p->Next=NULL;
            p2 = p2->Next;
        }
    }

    if (p1 == NULL) // 因为输出的时候l1和l2都是null所以得让他们的位置都指向空才行
    {
        p->Next = p2;
    }

    if (p2 == NULL)
    {
        p->Next = p1;
    }

    L1->Next = NULL;
    L2->Next = NULL;

    return pm;
}
