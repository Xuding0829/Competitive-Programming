#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string sa, sb;
        cin >> sa;
        sb = sa;
        reverse(sa.begin(), sa.end());
        cout << sb << sa;
        cout << endl;
    }
}
