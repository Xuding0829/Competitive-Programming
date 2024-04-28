#include <iostream>
#include <algorithm>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
const int N = 1e6 + 100;
int a[N];
int n, m;

void quicksort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j)
    {
        do
            i++;
        while (a[i] < x);
        do
            j--;
        while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    quicksort(a, l, j);
    quicksort(a, j + 1, r);
}

bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    ios;
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, cmp);
        //注意格式
        cout << a[0];
        for (int i = 1; i < m; i++)
            cout << ' ' << a[i];
        cout << endl;
    }

    return 0;
}