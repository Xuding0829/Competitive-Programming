#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

const int N = 1e6 + 10;
int val[N], ne[N];
int idx, head;

void inti()
{
    head = -1;
    idx = 0;
}

void add_to_head(int k)
{
    val[idx] = k;
    ne[idx] = head;
    head = idx;
    idx++;
}

void remove(int k)
{
    ne[k - 1] = ne[ne[k - 1]];
}

void add(int k, int x)
{
    val[idx] = x;
    ne[idx] = ne[k - 1];
    ne[k - 1] = idx;
    idx++;
}

int main()
{
    int t;
    cin >> t;
    inti();
    while (t--)
    {
        int x;
        char ch;
        cin >> ch;
        if (ch == 'H')
        {
            cin >> x;
            add_to_head(x);
        }
        else if (ch == 'I')
        {
            int k;
            cin >> k >> x;
            add(k, x);
        }
        else
        {
            cin >> x;
            if (!x)
                head = ne[head];
            remove(x);
        }
    }
    for (int i = head; i != -1; i = ne[i])
    {
        cout << val[i] << " ";
    }
    cout << endl;
    return 0;
}
