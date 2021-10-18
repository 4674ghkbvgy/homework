#include <iostream>

using namespace std;
typedef struct TreeNode
{
    char val;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode() : val('0'), lchild(NULL), rchild(NULL) {}
} TreeNode;
TreeNode *readFile(TreeNode *&root, FILE *fp)
{
    char key;
    fscanf(fp, "%c", &key);
    if (feof(fp) != 0)
        return root;
    if (key == '#')
        root = NULL;
    else
    {
        root = (TreeNode *)malloc(sizeof(TreeNode));
        root->val = key;
        readFile(root->lchild, fp);
        readFile(root->rchild, fp);
    }
    return root;
}
int Depth(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(Depth(root->lchild), Depth(root->rchild));
}int main()
{
    FILE *fp;
    if ((fp = fopen("a.txt", "r")) == 0 || fp == 0)
        exit(0);
    TreeNode *root;
    readFile(root, fp);
    cout << Depth(root);
}
