#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6;

int t;

int isprime(int x)
{
    if (x <= 2)
        return 1;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return 1;
}

void solve()
{
    int m;
    cin >> m;
    for (int i = 2;; i++)
    { // m is prime && i is prime but i+m is not prime
        if (!isprime(i + m) && isprime(i))
        {
            cout << i << endl;
            return;
        }
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
