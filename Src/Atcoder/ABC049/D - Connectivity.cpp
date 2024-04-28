#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
typedef pair<int, int> PII;

// 题意：求每座城市有几种交通工具
// 求两个并查集的交集大小

map<int, int> mp;
map<PII, int> mp2;

int Hash(int a, int b)
{
    return a * N + b;
}

struct Node
{
    int n, p[N];

    int find(int x)
    {
        return x == p[x] ? x : p[x] = find(p[x]); // 查找祖先节点
    }

    void init(int n)
    {
        for (int i = 1; i <= n; i++)
            p[i] = i; // 初始化
    }

    void uni(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        p[fx] = p[fy] = p[x] = p[y] = min(x, y); // 连接ab两座城市
    }

    void uni2(int x, int y)
    {
        if (find(x) != find(y))
            p[find(x)] = find(y);
    }

} g1, g2;

signed main()
{
    int n, k, l, a, b;
    cin >> n >> k >> l;

    g1.init(n);
    g2.init(n);

    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b;
        g1.uni(a, b);
    }

    for (int i = 1; i <= l; i++)
    {
        cin >> a >> b;
        g2.uni(a, b);
    }

    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b;
        g1.uni2(a, b);
    }

    for (int i = 1; i <= l; i++)
    {
        cin >> a >> b;
        g2.uni2(a, b);
    }

    // a b 哈希做法
    // for (int i = 1; i <= n; i++)
    // {
    //     a = g1.find(i), b = g2.find(i);
    //     mp[Hash(a, b)]++;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     a = g1.find(i), b = g2.find(i);
    //     cout << mp[Hash(a, b)] << ' ';
    // }

    for (int i = 1; i <= n; i++)
    {
        a = g1.find(i), b = g2.find(i);
        mp2[make_pair(a, b)]++;
    }
    for (int i = 1; i <= n; i++)
    {
        a = g1.find(i), b = g2.find(i);
        cout << mp2[make_pair(a, b)] << endl;
    }

    return 0;
}