#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 100010, M = N * 2; // 最多N个节点，最多M条边
int n;                           // 需要输入n-1个边
int h[N], e[M], ne[M], idx;      // e存值，ne存下一个点的地址,h存链表的头
// 注意这个N和M，踩过一次坑
int ans = N; // 此处初始化的意思就是在取min时（很有可能）被赋为第一个值
bool st[N];  // 看看这个点是否走过
void add(int a, int b)
{ // 建立单向边，从a至b
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int dfs(int u)
{
    st[u] = true;          // 说明这个点已经走过去了
    int size = 0, sum = 0; //(初始化）如果为叶子节点的话，那么sum为0，没有子块
    // size指u节点的单个子树的值
    for (int i = h[u]; i != -1; i = ne[i])
    {                 // 遍历u的所有子节点
        int j = e[i]; // j代表u的联通节点，u->j
        if (st[j])
        { // 这个点已经遍历过，那么看u的下一个子节点
            continue;
        }
        int s = dfs(j);      // 取得当前u的子节点j的子树林节点和
        size = max(size, s); // 比较当前的子节点的最大值和之前的子节点的最大值
        sum += s;            // 计算u节点所统领的所有子节点
    }
    size = max(size, n - sum - 1); // size是u的最大子树
    // n-sum-1值图在去除以n为根的树后剩下的子节点值
    ans = min(size, ans); //(题目)如果将这个点删除后，剩余各个连通块中点数的最大值最小
    return sum + 1;       // 返回u节点+所有u节点统领的节点的综合
}
int main()
{
    cin >> n;
    memset(h, -1, sizeof(h)); // 将每个节点的链表设置为空
    for (int i = 1; i < n; i++)
    { // 这里不能用while（n--）的形式，因为要用到n作为树的总节点数
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans;
    return 0;
}