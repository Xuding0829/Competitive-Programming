#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int tr[N], level[N];
int n, m;
// tr[i]数组用于统计坐标为i的点的个数
// level[i]数组表示i等级的星星数量

int lowbit(int x)
{
    return x & -x;
}

void add(int x)
{
    for (int i = x; i <= N; i += lowbit(i))
        tr[i]++; // 更新
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
    // sum（x）返回的是横坐标小于x的星星的总个数
}

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x++; // 题目中给的是0~n 而树状数组要求的是1~n，因此x++
        // 由于题目是根据y递增输入的数据，可以忽略y
        level[sum(x)]++;
        add(x); // 询问的是 该点之前的数，插入在最后
    }
    for (int i = 0; i < n; i++)
        cout << level[i] << endl;
    return 0;
}