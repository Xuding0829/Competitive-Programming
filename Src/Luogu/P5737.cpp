#include <bits/stdc++.h>
using namespace std;
int ans = 0;
vector<int> v;
void runnian(int x, int y)
{
    for (int i = x; i <= y; i++)
    {
        if (i % 400 == 0)
        {
            ans++;
            v.push_back(i);
        }
        else if (i % 4 == 0 && i % 100 != 0)
        {
            ans++;
            v.push_back(i);
        }
    }
}

int main()
{
    int x, y;
    cin >> x >> y;

    runnian(x, y);
    cout << ans << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}