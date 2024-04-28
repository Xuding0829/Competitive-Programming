#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 200;

int n, m;
char start[N], aim[N];

void turn(int x) // 翻转硬币
{
    if (start[x] == '*')
        start[x] = 'o';
    else
        start[x] = '*';
}

signed main()
{
    cin >> start >> aim;

    for (int i = 0; start[i]; i++)
    {
        if (start[i] != aim[i])
        {
            turn(i); // 翻转相邻两个
            turn(i + 1);
            n++; // 翻转次数增加
        }
    }
    cout << n << endl;
    return 0;
}