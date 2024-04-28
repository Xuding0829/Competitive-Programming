#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 1;
    cin >> n;
    while (n > 1)
    {
        sum = (sum + 1) * 2;
        n--;
    }
    cout << sum;
    return 0;
}