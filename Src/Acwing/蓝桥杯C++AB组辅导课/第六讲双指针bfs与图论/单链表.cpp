#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 100;
int a[N];
int n, m;
int e[N], ne[N], idx, head;

void init()
{
    head = -1;
}

void add_to_head(int k)
{
    ne[idx] = head;
    e[idx] = k;
    head = idx++;
}

void remove(int k)
{
    ne[k - 1] = ne[ne[k - 1]];
}

void add(int k, int x)
{
    ne[idx] = ne[k - 1];
    e[idx] = x;
    ne[k - 1] = idx;
    idx++;
}

signed main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        char op;
        cin >> op;
        if (op == 'H')
        {
            int x;
            cin >> x;
            add_to_head(x);
        }
        else if (op == 'I')
        {
            int k, x;
            cin >> k >> x;
            add(k, x);
        }
        else if (op == 'D')
        {
            int k;
            cin >> k;
            if (!k)
                head = ne[head];
            else
                remove(k);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    return 0;
}