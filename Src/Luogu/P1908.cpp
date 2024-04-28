#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 100;
int a[N], tmp[N];
int res;

int mergesort(int a[], int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) >> 1;

    res = mergesort(a, l, mid) + mergesort(a, mid + 1, r);

    int i = l, j = mid + 1;
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
    return res;
}

signed main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << mergesort(a, 0, n - 1) << endl;
    return 0;
}