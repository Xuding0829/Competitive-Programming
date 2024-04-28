#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int data;
    struct ListNode *next;
};

struct ListNode *createlist();
struct ListNode *deleteeven(struct ListNode *head);
void printlist(struct ListNode *head)
{
    struct ListNode *p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    struct ListNode *head;

    head = createlist();
    head = deleteeven(head);
    printlist(head);

    return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode *createlist()
{
    int data;
    struct ListNode *p, *r;
    struct ListNode *head;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    r = head;
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->data = data;
        r->next = p;
        r = p;
    }
    r->next = NULL;
    return head;
}
struct ListNode *deleteeven(struct ListNode *head)
{
    struct ListNode *q, *p;
    p = head;
    q = head->next;
    while (q)
    {
        if (q->data % 2 == 0)
        {
            p->next = q->next;
        }
        else
        {
            p = p->next;
        }
        q = q->next;
    }
    return head->next;
}
