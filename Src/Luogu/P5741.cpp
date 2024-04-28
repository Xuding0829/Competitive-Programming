#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
struct Stu
{
    string name;
    int c, m, e;
} a[MAXN];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].name >> a[i].c >> a[i].m >> a[i].e; // 输入
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int ans = abs(a[i].c - a[j].c);
            int ans1 = abs(a[i].m - a[j].m);
            int ans2 = abs(a[i].e - a[j].e);
            int ans3 = abs(a[i].e + a[i].c + a[i].m - a[j].c - a[j].m - a[j].e); // 总分相减
            if (ans <= 5 && ans1 <= 5 && ans2 <= 5 && ans3 <= 10)
            {
                if (a[i].name > a[j].name)
                    cout << a[j].name << " " << a[i].name << "\n";
                else
                    cout << a[i].name << " " << a[j].name << "\n";
            }
        }
    }
    return 0;
}