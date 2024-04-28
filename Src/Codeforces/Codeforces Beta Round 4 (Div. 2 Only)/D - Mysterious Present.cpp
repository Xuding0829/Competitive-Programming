#include <bits/stdc++.h>

using i64 = long long;
struct node
{
    int w, h, id;
    bool operator<(const node &t)
    {
        if (w != t.w)
            return w < t.w;
        else
            return h < t.h;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, W, H;
    std::cin >> n >> W >> H;

    std::vector<node> letter;
    for (int i = 0; i < n; i++)
    {
        int w, h;
        std::cin >> w >> h;
        if (w <= W || h <= H)
            continue;
        letter.push_back({w, h, i});
    }

    std::sort(letter.begin(), letter.end());
    // for (auto [u, v, w] : letter)
    //     std::cout << u << ' ' << v << ' ' << w << '\n';
    n = letter.size();

    if (!n)
    {
        std::cout << "0\n";
        return 0;
    }

    int res = 0, pos;
    std::vector<int> f(n), pre(n, -1);
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (letter[j].w < letter[i].w && letter[j].h < letter[i].h && f[j] + 1 > f[i])
            {
                f[i] = f[j] + 1;
                pre[i] = j;
            }
        }
        if (f[i] > res)
            res = f[i], pos = i;
    }

    std::cout << res << '\n';
    std::vector<int> ans;
    while (pos != -1)
    {
        ans.push_back(letter[pos].id);
        pos = pre[pos];
    }
    std::reverse(ans.begin(), ans.end());
    for (auto x : ans)
        std::cout << x + 1 << ' ';
    return 0;
}