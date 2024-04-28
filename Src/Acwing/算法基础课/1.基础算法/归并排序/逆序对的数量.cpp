#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 2e5 + 100;

int res;
int n, m;
int a[N], tmp[N];

void mergesort(int a[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    int i = l, j = mid + 1;
    mergesort(a, l, mid);
    mergesort(a, mid + 1, r);
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++], res += mid - i + 1;
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
        a[i] = tmp[j];
}

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergesort(a, 0, n - 1);
    cout << res << endl;
    return 0;
}