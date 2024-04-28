#include <bits/stdc++.h>
using namespace std;

bool zhishu(int a)
{
    if (a == 2)
        return true;
    if (a == 1)
        return false;
    for (int i = sqrt(a); i >= 2; i--)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 4; i <= N; i += 2)
    {
        for (int j = 2; j < N / 2; j++)
        {
            if (zhishu(j) && zhishu(i - j))
            {
                cout << i << '=' << j << '+' << i - j << endl;
                break;
            }
        }
    }
    return 0;
}