#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 100;

signed main()
{
    string s;
    cin >> s;
    vector<string> str(4);

    str[0] = "dream";
    str[1] = "dreamer";
    str[2] = "erase";
    str[3] = "eraser";

    for (int i = s.size() - 1; i >= 0; i--)
        for (int j = 0; j < 4; j++)
        {
            if (s.substr(i) == str[j])
            {
                s.erase(i, str[j].size());
                i = s.size() - 1;
                break;
            }
        }

    puts(s.size() == 0 ? "YES" : "NO");
    return 0;
}