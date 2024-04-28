#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 100010;
vector<int> a(N, 0);
vector<int> sum(N, 0);
int n;
void curry(vector<int> &s)
{
    for (int i = 0; i < N; i++)
    {
        if (s[i] >= 0)
        {
            s[i + 1] += s[i] / 10;
            s[i] %= 10;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    // 开始先将a和sum的值都进行赋值
    a[0] = 1;
    sum[0] = 1;
    for (int i = 2; i <= n; i++) // 注意我们开始的1的情况就已经赋值了，开始的
    {
        for (int j = 0; j < N; j++)
        {
            a[j] *= i;
            sum[j] += a[j];
        }
        curry(a);
        curry(sum);
    }
    while (sum.size() > 1 && sum.back() == 0)
    {
        sum.pop_back();
    }
    for (int i = sum.size() - 1; i >= 0; i--)
    {
        cout << sum[i];
    }
    puts("");
    return 0;
}