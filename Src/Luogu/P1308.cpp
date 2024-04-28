
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, words;
    getline(std::cin, words);
    getline(std::cin, s);
    for (int i = 0; i != words.length(); i++)
        if (words[i] >= 'A' && words[i] <= 'Z')
            words[i] = words[i] - 'A' + 'a';

    for (int i = 0; i != s.length(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';

    words = ' ' + words + ' ';
    s = ' ' + s + ' ';

    if (s.find(words) == std::string::npos)
        std::cout << "-1" << '\n';
    else
    {
        int firstpos = s.find(words);
        int pos = s.find(words);
        int cnt = 0;
        while (pos != -1)
            cnt++, pos = s.find(words, pos + 1);
        std::cout << cnt << " " << firstpos << '\n';
    }

    return 0;
}