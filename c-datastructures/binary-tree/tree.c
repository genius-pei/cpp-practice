#define _CRT_SECURE_NO_WARNINGS
#include"tree.h"
#include"Queue.h"

BTnode* buynode(char x)
{
	BTnode* node = (BTnode*)malloc(sizeof(BTnode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	node->data = x;
	node->left = node->right = NULL;
	return node;
}

void preorder(BTnode* root)//前序遍历，中左右
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(BTnode* root)//中序遍历，左中右
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
}
void postorder(BTnode* root)//后序遍历，左右根
{
	if (root == NULL)
	{
		printf("NULL ");
		return;

	}
	postorder(root->left);
	postorder(root->right);
	printf("%c ", root->data);
	
}

int BinaryTreeSize2(BTnode* root,int* psize)//求二叉树节点个数
{
	
	if (root == NULL)
	{
		printf("%p\n", root);
		return 0;
	}
	(*psize)++;
	BinaryTreeSize2(root->left,psize);
	BinaryTreeSize2(root->right,psize);
	return *psize;
	
}
int BinaryTreeSize1(BTnode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize1(root->left)
		+ BinaryTreeSize1(root->right);
}

int BinaryTreeDepth(BTnode* root)//求二叉树深度
{
	if (root == NULL)
	{
		return 0;
	}
	int leftdep = BinaryTreeDepth(root->left);
	int rightdep = BinaryTreeDepth(root->right);
	return 1 + (leftdep > rightdep ? leftdep : rightdep);
}

BTnode* BinaryTreeFind(BTnode* root, btdatatype x)//在二叉树中查找
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTnode* leftfind = BinaryTreeFind(root->left, x);
	if (leftfind)//如果左子树未找到
	{
		return leftfind;
	}
	BTnode* rightfind= BinaryTreeFind(root->right, x);
	if (rightfind)
	{
		return rightfind;
	}
	return NULL;
}
void BinaryTreeDestory(BTnode** root)//二叉树的销毁
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&((*root)->left));
	BinaryTreeDestory(&((*root)->right));
	free(*root);
	*root = NULL;
}
void leverorder(BTnode* root)//层序遍历
{
	QU q;
	QUinit(&q);
	QUpushi(&q, root);

	while (!QUempty(&q))//当队列不为时
	{
		//取队头，出队头
		BTnode* top = QUfront(&q);
		QUpop(&q);
		printf("%c ", top->data);
		//将队头非空左右孩子入列
		if (top->left)
			QUpushi(&q, top->left);
		if (top->right)
			QUpushi(&q, top->right);
	}
	
}


