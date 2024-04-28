#include <bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
const int N = 2e5 + 100;
int a[N];
int n, m, res;

unordered_map<ll, int> mp;
vector<ll> p;

// 由题意：a[i] ^ a[i + 1] = a[i + 2]
// a[i + 1] ^ a[i + 2] = a[i + 3];
// a[i] == a[i + 3];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (!mp.count(x))
            p.push_back(x); // p数组保证元素不重复
        mp[x]++;            // 统计x出现次数
    }

    sort(p.begin(), p.end());

    if (mp.size() == 1) // 如果只有一个元素，当且仅当这个元素是0是，可以满足题意
    {
        if (p[0] == 0)
            puts("Yes");
        else
            puts("No");
        return 0;
    }

    if (n % 3) // 如果数组不全为零，那么数组长度必然是3的倍数
    {
        puts("No");
        return 0;
    }

    if (mp.size() == 2) // 当数组存在两个不相同的元素，由 s ^ s = 0,故此时，有2/3n的相同元素，1/3n为0
    {
        if (p[0] == 0 && mp[0] == n / 3 && mp[p[1]] == n / 3 * 2)
            puts("Yes");
        else
            puts("No");
        return 0;
    }

    if (mp.size() == 3)
    {
        if (mp[p[0]] == mp[p[1]] && mp[p[0]] == mp[p[2]] && (p[1] ^ p[0] ^ p[2]) == 0) // 注意括号，^的优先级低于 ==
            puts("Yes");                                                               // 当有三个互不相同的元素，各个元素的数量必须相同，且满足异或要求
        else
            puts("No");
        return 0;
    }

    puts("No");
    return 0;
}
/*
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        ans^=a;
    }
    if(ans==0) printf("Yes\n");
    else printf("No\n");
    return 0;
} 
*/