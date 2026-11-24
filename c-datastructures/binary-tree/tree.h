#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef char btdatatype;
typedef struct binarytreenode
{
	btdatatype data;
	struct binarytreenode* left;
	struct binarytreenode* right;
}BTnode;

void preorder(BTnode* root);//前序遍历，中左右
void inorder(BTnode* root);//中序遍历，左中右
BTnode* buynode(char x);//创建节点
int BinaryTreeSize1(BTnode* root);//求二叉树节点个数
int BinaryTreeSize2(BTnode* root,int* psize);//求二叉树节点个数
int BinaryTreeDepth(BTnode* root);//求二叉树深度
BTnode* BinaryTreeFind(BTnode* root, btdatatype x);//在二叉树中查找
void BinaryTreeDestory(BTnode** root);//二叉树销毁
void leverorder(BTnode* root);//层序遍历
