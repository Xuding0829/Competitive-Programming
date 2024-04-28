#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct node
{
    string s;
    int num;
};
const int N = 1e6;
int a[N];
bool cmp(struct node a, struct node b)
{
    if (a.s.length() != b.s.length())
        return a.s.length() > b.s.length();
    else
        return a.s > b.s;
}
int main()
{
    int n;
    int sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                sum++;
            }
    cout << sum << endl;
    return 0;
}