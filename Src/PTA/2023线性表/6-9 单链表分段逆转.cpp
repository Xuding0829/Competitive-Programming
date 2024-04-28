#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Node *PtrToNode;
struct Node
{
    ElementType Data; /* 存储结点数据 */
    PtrToNode Next;   /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List ReadInput();       /* 裁判实现，细节不表 */
void PrintList(List L); /* 裁判实现，细节不表 */
void K_Reverse(List L, int K);

int main()
{
    List L;
    int K;

    L = ReadInput();
    scanf("%d", &K);
    K_Reverse(L, K);
    PrintList(L);

    return 0;
}

/* 你的代码将被嵌在这里 */

void K_Reverse(List L, int K)
{
    List l, l1, l2;
    l = (List)malloc(sizeof(struct Node));
    l->Next = NULL;
    int i, c = 1;
    l2 = l;
    while (c)
    {
        l1 = L;
        for (i = 0; i < K; i++)
        {
            if (l1->Next == NULL)
            {
                c = 0;
                break;
            }
            l1 = l1->Next;
        }
        while (l2->Next != NULL)
        {
            l2 = l2->Next;
        }
        if (c)
        {
            for (i = 0; i < K; i++)
            {
                l1 = L->Next;
                L->Next = l1->Next;
                l1->Next = l2->Next;
                l2->Next = l1;
            }
        }
        else
        {
            l2->Next = L->Next;
            L->Next = l->Next;
            free(l);
        }
    }
}