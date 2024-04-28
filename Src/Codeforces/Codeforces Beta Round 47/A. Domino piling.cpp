#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m, n;
    int k;
    int num = 0;
    cin >> m >> n;
    if (m < n)
        swap(m, n);
    if (n % 2 == 1)
    {
        n = n - 1;
        k = 1;
        num = m * n / 2 + m / 2;
    }
    else
    {
        num = m * n / 2;
    }

    cout << num << endl;
    return 0;
}
