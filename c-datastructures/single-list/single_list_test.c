#define _CRT_SECURE_NO_WARNINGS
#include"single_list.h"
void test01()
{
	SLTNODE* node1 = (SLTNODE*)malloc(sizeof(SLTNODE));
	SLTNODE* node2 = (SLTNODE*)malloc(sizeof(SLTNODE));
	SLTNODE* node3 = (SLTNODE*)malloc(sizeof(SLTNODE));
	SLTNODE* node4 = (SLTNODE*)malloc(sizeof(SLTNODE));
	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;
	SLTNODE* plist = node1;
	sltprint(plist);

}
void test02()
{
	SLTNODE* plist = NULL;//创建空链表
	
	sltpushback(&plist, 1);
	sltpushback(&plist, 1);
	sltpushback(&plist, 2);
	sltpushback(&plist, 4);
	sltpushfrond(&plist, 5);
	sltpushback(&plist, 3);
	sltpushfrond(&plist, 5);
	sltpopfront(&plist);
	sltpopback(&plist);
	sltprint(plist);
	SLTNODE* find= sltfind(plist, 4);
	/*if (find)
	{
		printf("找到了\n");
		
	}
	else
	{
		printf("未找到\n");
	}*/
	/*sltinsert(&plist, find, 100);*/
	sltinsertafter(find, 50);
	//slterase(&plist, find);
	/*slteraseafter(find);*/
	slistdestory(&plist);
	sltprint(plist);
}
int main()
{
	test01();
	/*test02();*/
	return 0;
}