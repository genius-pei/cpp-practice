#define _CRT_SECURE_NO_WARNINGS
#include"tree.h"
BTnode* creatbinarytree()
{
	
	
		BTnode* nodeA = buynode('A');
		BTnode* nodeB = buynode('B');
		BTnode* nodeC = buynode('C');
		BTnode* nodeD = buynode('D');
		BTnode* nodeE = buynode('E');
		BTnode* nodeF = buynode('F');

		nodeA->left = nodeB;
		nodeA->right = nodeC;
		nodeB->left = nodeD;
		nodeC->left = nodeE;
		nodeC->right = nodeF;

		return nodeA;
	

}
void test01()
{
	BTnode* root = creatbinarytree();
	preorder(root);
	/*if (BinaryTreeFind(root, 'F'))
	{
		printf("找到了\n");
	}
	else
	{
		printf("没找到\n");
	}*/
}
void test02()
{
	BTnode* root = creatbinarytree();
    int size = 0;
	printf("size:%d\n", BinaryTreeSize1(root));
	printf("size:%d\n", BinaryTreeSize2(root,&size));
}
void test03()
{
	BTnode* root = creatbinarytree();
	leverorder(root);
}
int main()
{
	
	test01();
	//test02();
	/*test03();*/
	return 0;
}
