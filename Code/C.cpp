#include <bits/stdc++.h>

using i64 = long long;
int a[] = {5, 2, 3, 4, 1, 6};
int b[] = {2, 3, 5, 1, 4, 6};

struct BTNode
{
    int data;
    BTNode *lchild, *rchild;
} ;

BTNode* creat_bt_tree(int a[], int b[], int n)
{

}

void destroy_bt_tree(BTNode* bt)
{
    if (!bt->lchild && !bt->rchild)
        free(bt);
    else
        destroy_bt_tree(bt->lchild), destroy_bt_tree(bt->rchild);
}

int leaf_sum(BTNode* bt)
{
    if(!bt->lchild && !bt->rchild)
        return bt->data;
    else
        return leaf_sum(bt->lchild) + leaf_sum(bt->rchild);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    BTNode *BT;

    creat_bt_tree(a, b, 6);

    std::cout << leaf_sum(BT) << '\n';

    destroy_bt_tree(BT);

    return 0;
}