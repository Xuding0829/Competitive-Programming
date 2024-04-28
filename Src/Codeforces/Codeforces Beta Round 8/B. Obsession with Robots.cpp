#include <bits/stdc++.h>

#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 300;
const int inf = 0x3f3f3f3f;

int a[N];
int n, m;
bool flag;
string s;

int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int sx = 150, sy = 150;
bool vis[300][300] = {0};

signed main()
{
    ios;
    int T;
    T = 1;
    // cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        vis[sx][sy] = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'L')
                sx--;
            else if (s[i] == 'R')
                sx++;
            else if (s[i] == 'U')
                sy++;
            else
                sy--;

            if (vis[sx][sy])
            {
                cout << "BUG" << endl;
                return 0;
            }

            vis[sx][sy] = 1;

            int cnt = 0;
            for (int j = 0; j < 4; j++)
                if (vis[sx + dir[j][0]][sy + dir[j][1]])
                    cnt++;
                    
            if (cnt != 1)
            {
                cout << "BUG" << endl;
                return 0;
            }
        }
        cout << "OK" << endl;
    }
    return 0;
}
