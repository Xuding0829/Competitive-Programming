#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N], p[N], cnt[N];
int n, m;

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i, cnt[i] = 1;

    while (m--)
    {
        string op;
        int a, b;
        cin >> op;
        if (op == "Q1")
        {
            cin >> a >> b;
            puts(find(a) == find(b) ? "Yes" : "No");
        }
        else if (op == "Q2")
        {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
        else if (op == "C")
        {
            cin >> a >> b;

            if (find(a) != find(b))
                cnt[find(b)] += cnt[find(a)], p[find(a)] = find(b);

            // a = find(a), b = find(b);
            // if (a != b)
            //     p[a] = b, cnt[b] += cnt[a];

            // 大家看y总这段代码时要注意，在C操作时，y总先把a，b的根结点取出来了：
            // a = find(a), b = find(b);，
            // 因此接下来是先将集合a接到集合b下再把a的连通块大小加到b上，
            // 还是先把a的连通块大小加到b上再操作集合都是可以的，
            // 如果大家没有提前一步的处理，就必须要先加连通块大小再操作集合，
            // 否则操作完集合后，a和b的根结点将会重叠，导致输出错误！
        }
    }
    return 0;
}