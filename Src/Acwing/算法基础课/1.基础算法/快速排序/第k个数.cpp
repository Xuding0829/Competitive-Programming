#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int n, m;
int a[N];

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
    quicksort(a, j + 1ll, r);
}

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    quicksort(a, 0, n - 1);
    cout << a[m - 1];
    return 0;
}