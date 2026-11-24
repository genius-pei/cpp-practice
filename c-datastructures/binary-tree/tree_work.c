#define _CRT_SECURE_NO_WARNINGS
bool isUnivalTree(struct TreeNode* root) {

    if (root == NULL)

    {

        return true;

    }

    if (root->left && root->val != root->left->val)

    {

        return false;

    }



    if (root->right && root->val != root->right->val)

    {

        return false;

    }

    return isUnivalTree(root->left) && isUnivalTree(root->right);

}
#include <stdio.h>


typedef struct treenode
{
    char data;
    struct treenode* left;
    struct treenode* right;
}treenode;
treenode* buynode(char x)
{
    treenode* node = (treenode*)malloc(sizeof(treenode));
    if (node == NULL)
    {
        exit(1);
    }
    node->data = x;
    node->left = node->right = NULL;
    return node;

}
treenode* creattree(char* arr, int* pi)
{
    if (arr[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    treenode* root = buynode(arr[*pi]);
    (*pi)++;
    root->left = creattree(arr, pi);
    root->right = creattree(arr, pi);
    return root;
}
void inorder(treenode* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%c ", root->data);
    inorder(root->right);
}
int main() {
    //读取字符串
    char arr[100];
    scanf("%s", arr);
    int i = 0;
    treenode* root = creattree(arr, &i);
    inorder(root);
}
