#include <cstdio>
#include <iostream>
using namespace std;
const int map[5][5] = {
    0, 0, 1, 1, 0,
    1, 0, 0, 1, 0,
    0, 1, 0, 0, 1,
    0, 0, 1, 0, 1,
    1, 1, 0, 0, 0};
int n, na, nb, a[201], b[201], ah = -1, bh = -1, ansa, ansb;

int main()
{
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++)
        cin >> a[i];
    for (int i = 0; i < nb; i++)
        cin >> b[i];
    while (n > 0)
    {
        n--;
        ah++;
        ah %= na;
        bh++;
        bh %= nb;
        ansa += map[a[ah]][b[bh]];
        ansb += map[b[bh]][a[ah]];
    }
    cout << ansa << " " << ansb;
    return 0;
}