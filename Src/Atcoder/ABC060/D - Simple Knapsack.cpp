#include <bits/stdc++.h>

using i64 = long long;

struct Node
{
    i64 v, w;
    bool operator<(const Node &W) const
    {
        return w > W.w;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<Node> w1, w2, w3, w4;

    for (int i = 0; i < n; i++)
    {
        int v, w;
        std::cin >> v >> w;

        if (!i)
        {
            w1.push_back({v, w});
            continue;
        }

        int tmp = v - w1[0].v;
        if (tmp == 0)
            w1.push_back({v, w});
        else if (tmp == 1)
            w2.push_back({v, w});
        else if (tmp == 2)
            w3.push_back({v, w});
        else
            w4.push_back({v, w});
    }

    std::sort(w1.begin(), w1.end());
    std::sort(w2.begin(), w2.end());
    std::sort(w3.begin(), w3.end());
    std::sort(w4.begin(), w4.end());

    w1.insert(w1.begin(), {0, 0});
    w2.insert(w2.begin(), {0, 0});
    w3.insert(w3.begin(), {0, 0});
    w4.insert(w4.begin(), {0, 0});

    for (int i = 1; i < (int)w1.size(); i++)
        w1[i].w += w1[i - 1].w, w1[i].v += w1[i - 1].v;
    for (int i = 1; i < (int)w2.size(); i++)
        w2[i].w += w2[i - 1].w, w2[i].v += w2[i - 1].v;
    for (int i = 1; i < (int)w3.size(); i++)
        w3[i].w += w3[i - 1].w, w3[i].v += w3[i - 1].v;
    for (int i = 1; i < (int)w4.size(); i++)
        w4[i].w += w4[i - 1].w, w4[i].v += w4[i - 1].v;

    i64 res = 0;
    for (int i = 0; i < w1.size(); i++)
        for (int j = 0; j < w2.size(); j++)
            for (int k = 0; k < w3.size(); k++)
                for (int l = 0; l < w4.size(); l++)
                    if (w1[i].v + w2[j].v + w3[k].v + w4[l].v <= m)
                        res = std::max(res, w1[i].w + w2[j].w + w3[k].w + w4[l].w);

    std::cout << res << '\n';
    return 0;
}