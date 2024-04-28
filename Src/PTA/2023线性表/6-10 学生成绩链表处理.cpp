#include <stdio.h>
#include <stdlib.h>

struct stud_node
{
    int num;
    char name[20];
    int score;
    struct stud_node *next;
};

struct stud_node *createlist();
struct stud_node *deletelist(struct stud_node *head, int min_score);

int main()
{
    int min_score;
    struct stud_node *p, *head = NULL;

    head = createlist();
    scanf("%d", &min_score);
    head = deletelist(head, min_score);
    for (p = head; p != NULL; p = p->next)
        printf("%d %s %d\n", p->num, p->name, p->score);

    return 0;
}

/* 你的代码将被嵌在这里 */
void *creat_stud_node(size_t size)
{
    struct stud_node *temp = NULL;
    temp = (struct stud_node *)malloc(size);
    if (temp != NULL)
    {
        return temp;
    }
    return NULL;
}

struct stud_node *createlist()
{
    int size = sizeof(struct stud_node);
    struct stud_node *head = NULL, *tail = NULL, *p;
    p = creat_stud_node(size);
    p->next = NULL;
    scanf("%d", &p->num);
    while (p->num != 0)
    {
        scanf("%s %d", &p->name, &p->score);
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            tail->next = p;
        }
        tail = p;
        tail->next = NULL;
        p = creat_stud_node(size);
        scanf("%d", &p->num);
    }
    return head;
}

struct stud_node *deletelist(struct stud_node *head, int min_score)
{
    struct stud_node *ptr1, *ptr2;
    // 要删除的数据在表头
    while (head != NULL && head->score < min_score)
    {
        ptr1 = head;
        head = head->next;
        free(ptr1);
        ptr1 = NULL;
    }
    if (head == NULL)
    {
        return NULL;
    }
    // 要删除的数据不在表头
    ptr1 = head;
    ptr2 = head->next;
    while (ptr2 != NULL)
    {
        if (ptr2->score < min_score)
        {
            ptr1->next = ptr2->next;
            free(ptr2);
            ptr2 = NULL;
        }
        else
        {
            ptr1 = ptr2;
        }
        ptr2 = ptr1->next;
    }
    return head;
}