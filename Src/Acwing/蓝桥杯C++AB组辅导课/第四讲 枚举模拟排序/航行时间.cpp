#include <bits/stdc++.h>
// #define int long long
typedef long long ll;
using namespace std;

const int N = 2e5 + 100;
int a[N];

// 启程 ：出发时间 - 时差 + 航行时间 = 到达时间
// 返程 ：出发时间 + 时差 + 航行时间 = 到达时间
// 航行时间=(去乘降落时间-去乘起飞时间+回程降落时间-回程起飞时间)/2

int get_time()
{
    int h1, m1, s1, h2, m2, s2, d = 0;
    scanf("%d:%d:%d %d:%d:%d (+%d)", &h1, &m1, &s1, &h2, &m2, &s2, &d);
    return d * 24 * 3600 + h2 * 3600 + m2 * 60 + s2 - h1 * 3600 - m1 * 60 - s1;
}

signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int time1 = get_time();
        int time2 = get_time();
        int res = (time1 + time2) / 2;
        printf("%02d:%02d:%02d\n", res / 3600, res / 60 % 60, res % 60);
    }
    return 0;
}