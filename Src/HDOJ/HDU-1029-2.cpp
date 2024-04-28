#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];

signed main()
{
    while (scanf("%d", &n) != EOF)
    {
        int cnt = 0, num = 0;
        //统计次数，  答案
        for (int i = 0, x; i < n; i++)
        {
            scanf("%d", &x);
            //如果cnt==0，更新x，cnt++
            if (!cnt)
            {
                num = x;
                cnt++;
            }
            else
            {
                //如果当前输入的x与之前出现次数最多的数字相同cnt++
                if (x == num)
                    cnt++;
                //否则--
                else
                    cnt--;
            }
        }
        //数字相当于一种竞争关系，cnt记录数字之间的差距
        printf("%d\n", num);
    }
    return 0;
}

//5
//1 1 2 2 3
//输出3
//由于答案出现次数大于   n/2    保证了该算法在当前条件下的正确性