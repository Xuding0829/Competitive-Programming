#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int h[N], e[N], w[N], ne[N], idx;
int d[N];
int n, m;
bool st[N];
typedef pair<int, int> PII;

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

int dijkstra()
{
    memset(d, 0x3f, sizeof(d));
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    d[1] = 0;
    heap.push({0, 1});
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, dis = t.first;
        if (st[ver])
            continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (d[j] > d[ver] + w[i])
                d[j] = d[ver] + w[i], heap.push({d[j], j});
        }
    }
    if (d[n] == 0x3f3f3f3f)
        return -1;
    else
        return d[n];
}

int main()
{
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dijkstra() << endl;
    return 0;
}