#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

ElementType Find(List L, int m);

int main()
{
    List L;
    int m;
    L = Read();
    scanf("%d", &m);
    printf("%d\n", Find(L, m));
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
ElementType Find(List L, int m)
{
    List p = L->Next;
    int index = 0;
    while (p)
    {
        p = p->Next;
        index++;
    }
    if (index < m)
        return ERROR;
    else
    {
        index = index - m + 1;
        while (index)
        {
            L = L->Next;
            index--;
        }
        return L->Data;
    }
}
