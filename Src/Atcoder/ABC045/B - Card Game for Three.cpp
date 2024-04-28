#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int a[N];
int n, m;
int main()
{
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int id = 0; // id 指向谁的回合
    // 注意坑点：题目要求是轮到某人时那个人没有牌才是胜利，不是把牌打完是胜利
    while (s1.size() || s2.size() || s3.size())
    {
        if (!id)
        {
            if (!s1.size())
            {
                puts("A");
                return 0;
            }
            else
                id = s1[0] - 'a', s1.erase(0, 1); // id == 0 Alice
        }
        else if (id == 1)
        {
            if (!s2.size())
            {
                puts("B");
                return 0;
            }
            else
                id = s2[0] - 'a', s2.erase(0, 1); // id == 1 Bob
        }
        else if (id == 2)
        {
            if (!s3.size())
            {
                puts("C");
                return 0;
            }
            else
                id = s3[0] - 'a', s3.erase(0, 1); // id == 2 Charlie
        }

        // if (!s1.size())
        //     break;
        // else if (!s2.size())
        //     break;
        // else if (!s3.size())
        //     break;
    }

    // debug
    // cout << "s1 " << s1.size() << ' ' << s1 << endl;
    // cout << "s2 " << s2.size() << ' ' << s2 << endl;
    // cout << "s3 " << s3.size() << ' ' << s3 << endl;

    // if (!s1.size())
    //     puts("A");
    // else if (!s2.size())
    //     puts("B");
    // else if (!s3.size())
    //     puts("C");

    return 0;
}

// 感觉代码繁琐 博客 https://codeleading.com/article/38454116261/ 个人认为改代码精简 doge