#include <stdio.h>
const int maxn = 101;
struct student
{
    char name[20];
    char number[20];
    int grade;
};
int main()
{
    struct student stu[maxn];
    int n;
    int max = -1, min = 101;
    int x, y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", stu[i].name);
        scanf("%s", stu[i].number);
        scanf("%d", &stu[i].grade);
    }
    for (int i = 0; i < n; i++)
    {
        if (stu[i].grade > max)
        {
            max = stu[i].grade;
            x = i;
        }
        if (stu[i].grade < min)
        {
            min = stu[i].grade;
            y = i;
        }
    }
    printf("%s %s\n", stu[x].name, stu[x].number);
    printf("%s %s\n", stu[y].name, stu[y].number);
    return 0;
}