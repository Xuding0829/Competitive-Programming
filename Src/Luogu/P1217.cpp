#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

bool st[100000001];

void prime(int number)
{

    memset(st, true, sizeof(st));
    st[0] = st[1] = false;
    for (int i = 2; i * i <= number; i++)
    {
        if (st[i])
        {
            for (int j = 2 * i; j <= number; j += i)
            {
                st[j] = false;
            }
        }
    }
}

bool check(int num)
{
    int temp = num;
    int sumcmp = 0;
    while (temp != 0)
    {
        int c = temp % 10;
        sumcmp = sumcmp * 10 + c;
        temp = temp / 10;
    }
    if (sumcmp == num)
        return true;
    else
        return false;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (b >= 10000000)
        b = 9999999;
    if (a % 2 == 0)
        a++;
    prime(b);
    for (; a <= b; a += 2)
    {
        if (st[a] && check(a))
        {
            printf("%d\n", a);
        }
    }
    return 0;
}