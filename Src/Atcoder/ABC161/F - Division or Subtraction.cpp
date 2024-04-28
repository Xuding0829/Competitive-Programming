#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;
int a[N];
int n, m, res;

// 题意：给你一个数n，问存在多少个k，满足 n - k 或者 n / k 最后为1
// 对于整除操作，这个数k一定是n的因数，寻找n的满足操作的因子
// 对于减操作，这个数 k 一定是（n - 1) 的因子 （理由如下:n - (n - 1) == 1, n - 1 == p * k, n - k - k - k-...- k(p个k) == 1） 
// 对于任意的一个数n， 一定存在两个数 n，（n - 1），一定不存在1
signed main()
{
    cin >> n;
    set<int> st;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            int tmp = n;
            while (tmp % i == 0)
                tmp /= i;
            if (tmp % i == 1)
                st.insert(i);
        }
    }

    for (int i = 1; i <= n / i; i++)
        if ((n - 1) % i == 0)
            st.insert(i), st.insert((n - 1) / i);

    st.erase(1);
    st.insert(n);
    cout << st.size() << endl;
    return 0;
}