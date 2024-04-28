#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;

const int N = 1e6 + 100;
int a[N], b[N], tr[N];
int n, m;
int res;

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int v)
{
    for (int i = x; i < N; i += lowbit(i))
        tr[i] += v;
} // tr[]数组存储的是数字出现的次数

int query(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
} // query(i) 函数返回的是小于i的个数

signed main()
{
    cin >> n;
    // 题目本质求逆序对数量
    // 对于a[i], 求a[i]前面比a[i]小，后面比a[i]大的数
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i]++; // 防止a[i]为零的情况

    for (int i = 1; i <= n; i++)
    {
        add(a[i], 1);
        b[i] = i - query(a[i]); // 数组长度 - 小于a[i]的个数 == 1~i中比a[i]大的数的个数
    }

    memset(tr, 0, sizeof(tr));

    for (int i = n; i >= 1; i--) //
    {
        add(a[i], 1);
        b[i] += query(a[i] - 1); // 求比a[i]小的数的个数
    }

    for (int i = 1; i <= n; i++)
        res += (1 + b[i]) * b[i] / 2;

    cout << res << endl;
    return 0;
}
