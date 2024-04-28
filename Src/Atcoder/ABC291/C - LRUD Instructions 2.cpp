#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int, int> PII;
vector<PII> p;
const int N = 2e5 + 100;
int a[N];
int n, m;

signed main()
{
    string s;
    cin >> n >> s;
    int x = 0, y = 0;
    p.push_back({x, y});
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R')
        {
            x += 1;
            p.push_back({x, y});
        }
        else if (s[i] == 'L')
        {
            x -= 1;
            p.push_back({x, y});
        }
        else if (s[i] == 'U')
        {
            y += 1;
            p.push_back({x, y});
        }
        else
        {
            y -= 1;
            p.push_back({x, y});
        }
    }

    sort(p.begin(), p.end());

    bool is_same = false;
    for (int i = 1; i < p.size(); i++)
    {
        if (p[i] == p[i - 1])
        {
            is_same = true;
            break;
        }
    }

    if (is_same)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}