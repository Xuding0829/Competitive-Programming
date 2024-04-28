#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum
{
    false,
    true
} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

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

    L = MakeEmpty();
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        if (Insert(L, X, 0) == false)
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &P);
        if (Delete(L, P) == false)
            printf(" Deletion Error.\n");
        if (Insert(L, 0, P) == false)
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}

/* 你的代码将被嵌在这里 */

List MakeEmpty()
{
    List L;
    // sizeof里边不能写List，因为List是指向结构体的指针，并不代表
    // LNode的存储长度，指针的大小是固定的，在32位操作系统中，始终是4个字节
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1; /* 保存线性表中最后一个元素的位置 ，现在是空表设为-1，后边直接+1即可*/
    return L;
}

Position Find(List L, ElementType X)
{
    int i;
    for (i = 0; i <= L->Last; i++)
    {
        if (X == L->Data[i])
        {
            return i;
        }
    }
    return ERROR;
}

bool Insert(List L, ElementType X, Position P)
{
    if (L->Last == MAXSIZE - 1) // 空间满
    {
        printf("FULL");
        return false;
    }
    // 插入的位置范围应该为[0,L->Last+1]，可以在最后一个位置的下一个位置插入
    if (P < 0 || P > L->Last + 1)
    {
        printf("ILLEGAL POSITION");
        return false;
    }
    int i;
    /*
    看给的样例，最大长度是5，所以当插入位置为6时，说FULL，同理，当查找时，会说
    位置不合法，对于5的查找，位置是0，此时对于已经插进去的1,2,3,4,5来说，5是最后一个元素
    为0，（恰为空表时的-1 +1），再往后又没了元素。同理对于元素1，它的查找结果为4，
    （5位0，4为1,3为2,2为3,1为4.。。）
    */
    for (i = L->Last + 1; i > P; i--)
    {
        // 在P处插入，所以P位置之后的元素全都后移，注意下标问题
        L->Data[i] = L->Data[i - 1];
    }
    L->Data[i] = X; // 跳出循环，此时i=P，进行插入
    L->Last++;      // 又插入了一个，所以位置++
    return true;
}

bool Delete(List L, Position P)
{
    int i;
    if (P < 0 || P > L->Last)
    {
        // 删除的位置非法，包含空表情况，因为那是的Last=-1
        printf("POSITION %d EMPTY", P);
        return false;
    }
    // 删除第P个位置，所以P位置元素变为它的下一个，依次左移
    for (i = P; i < L->Last; i++)
    {
        L->Data[i] = L->Data[i + 1];
    }
    L->Last--; // 总的位置长度-1.
    return true;
}