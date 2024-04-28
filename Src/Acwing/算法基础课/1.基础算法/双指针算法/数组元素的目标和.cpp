
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 10;
int a[N];
int b[N];
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0, j = m - 1; i < n; i++)
    {
        while (j >= 0 && a[i] + b[j] > x)
            j--;
        if (a[i] + b[j] == x)
        {
            cout << i << " " << j;
            break;
        }
    }
    return 0;
}