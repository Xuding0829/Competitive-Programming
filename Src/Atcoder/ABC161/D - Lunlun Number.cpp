#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;
vector<int> p;
signed main()
{
    cin >> n;
    for (int i = 0; i <= 9; i++)
        p.push_back(i);

    int i = 1, j = 0;
    while (p.size() <= n)
    {
        if (abs(p[i] % 10 - p[j]) <= 1)
            p.push_back(p[i] * 10 + p[j]);
        j++;
        if (j == 10)
            i++, j = 0;
    }
    //  for(auto i : p)
    //      cout << i << endl;
    cout << p[n] << endl;
    return 0;
}