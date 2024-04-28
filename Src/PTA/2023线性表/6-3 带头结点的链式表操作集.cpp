#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef enum
{
    false,
    true
} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

List MakeEmpty();
Position Find(List L, ElementType X);
bool Insert(List L, ElementType X, Position P);
bool Delete(List L, Position P);

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    bool flag;

    L = MakeEmpty();
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        flag = Insert(L, X, L->Next);
        if (flag == false)
            printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else
        {
            flag = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (flag == false)
                printf("Wrong Answer.\n");
        }
    }
    flag = Insert(L, X, NULL);
    if (flag == false)
        printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    flag = Insert(L, X, P);
    if (flag == true)
        printf("Wrong Answer\n");
    flag = Delete(L, P);
    if (flag == true)
        printf("Wrong Answer\n");
    for (P = L->Next; P; P = P->Next)
        printf("%d ", P->Data);
    return 0;
}
/* 你的代码将被嵌在这里 */
List MakeEmpty()
{
    List head = (List)malloc(sizeof(struct LNode));
    head->Next = NULL;
    return head;
}

Position Find(List L, ElementType X)
{
    List t;
    for (t = L->Next; t; t = t->Next)
    {
        if (t->Data == X)
            return t;
    }
    return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
    List t;
    t = (List)malloc(sizeof(List));
    t->Data = X;
    if (P == L->Next)
    {
        t->Next = L->Next;
        L->Next = t;
        return true;
    }

    for (List i = L->Next; i; i = i->Next)
    {
        if (i->Next == P)
        {
            t->Next = i->Next;
            i->Next = t;
            return true;
        }
    }
    printf("Wrong Position for Insertion\n");
    return false;
}

bool Delete(List L, Position P)
{
    Position s = L;

    while (s && s->Next != P)
        s = s->Next;

    if (s == NULL)
    {
        printf("Wrong Position for Deletion\n");
        return false;
    }

    s->Next = s->Next->Next;
    return true;
}