#include <bits/stdc++.h>

#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const double eps = 1e-6;
const int mod = 1e9 + 7;
const int N = 1e6 + 100;

int n;

int main()
{
    cin >> n;
    string s;
    cin >> s;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
        if (s[i] == 'L')
            x++;
        else
            y++;

    cout << x + y + 1 << endl;
}
