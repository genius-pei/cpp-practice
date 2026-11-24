#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//typedef struct listnode listnode;
struct Listnode
{
	int val;
	struct listnode* next;
};

//struct listnode* removeelements(struct listnode* head, int val)
//{
//	listnode* newhead, * newtail;
//	newhead = newtail = NULL;
//	listnode* pcur = head;
//	while (pcur)
//	{
//		if (pcur->val != val)
//		{
//			//尾插
//			//链表为空
//			if (newhead == NULL)
//			{
//				newhead = newtail = pcur;
//			}
//			else
//			{
//				newtail->next = pcur;
//				newtail = newtail->next;
//			}
//		}
//		pcur = pcur->next;
//	}
//	if (newtail)
//	{
//		newtail->next = NULL;
//	}
//	return newhead;
//}
//
////反转链表
//struct ListNode* reverseList(struct ListNode* head)
//
//{
//
//    struct ListNode* n1, * n2, * n3;
//
//    n1 = NULL;
//
//    n2 = head;
//
//    n3 = n2->next;
//
//    while (n2)
//
//    {
//
//        n2->next = n1;
//
//        n1 = n2;
//
//        n2 = n3;
//
//        if (n3)
//
//        {
//
//            n3 = n3->next;
//
//        }
//
//    }
//
//    return n1;
//
////中间节点
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow, * fast;
//    slow = fast = head;
//    if (head = NULL)
//    {
//        return NULL;
//    }
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
//struct ListNode* middleNode(struct ListNode* head)
//{
//    struct ListNode* slow, * fast;
//    slow = fast = head;
//    if (head = NULL)
//    {
//        return NULL;
//    }
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}

//合并两个有序链表


//struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
//{
//	if (list1 == NULL && list2 == NULL) return NULL;
//	//处理特殊情况：一个链表为空，另一个链表不为空
//	if (list1 == NULL)  return list2;
//	if (list2 == NULL)  return list1;
//
//	struct ListNode* newhead, * newtail;
//	newhead = newtail = NULL;
//	struct ListNode* l1 = list1;
//	struct ListNode* l2 = list2;
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val)
//		{
//			if (newhead == NULL)
//			{
//				newhead = newtail = l1;
//			}
//			else
//			{
//				newtail->next = l1;
//				newtail = newtail->next;
//			}
//			l1 = l1->next;
//		}
//		else
//		{
//			if (newhead == NULL)
//			{
//				newhead = newtail = l2;
//			}
//			else
//			{
//				newtail->next = l2;
//				newtail = newtail->next;
//			}
//			l2 = l2->next;
//		}
//		if (l1)
//		{
//			newtail->next = l1;
//		}
//		if (l2)
//		{
//			newtail->next = l2;
//		}
//
//	}
//	return newhead;
//}

//链表的分割
  
////链表的回文结构
//ListNode* MIDELLE(ListNode* head)
//{
//    ListNode* slow, * fast;
//    slow = fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//    return slow;
//}
////反转链表
//ListNode* reverselist(ListNode* head)
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = n2->next;
//    while (n2)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n3)
//        {
//            n3 = n3->next;
//        }
//
//    }
//    return n1;
//}
//
//
//bool chkPalindrome(ListNode* A)
//{
//    // write code here
//    //寻找中间节点
//    ListNode* mid = MIDELLE(A);
//    //反转链表
//    ListNode* right = reverselist(mid);
//    //遍历链表
//    ListNode* left = A;
//    while (right)
//    {
//        if (left->val != right->val)
//        {
//            return false;
//        }
//        left = left->next;
//        right = right->next;
//    }
//    return true;
//
//}
//};

//相交链表
//typedef struct ListNode ListNode;
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
//{
//    ListNode* pa = headA;
//    ListNode* pb = headB;
//    int sizea = 0;
//    int sizeb = 0;
//    while (pa) {
//        sizea++;
//        pa = pa->next;
//    }
//    while (pb) {
//        sizeb++;
//        pb = pb->next;
//    }
//    int gap = abs(sizea - sizeb); // 长度差
//
//    // 让长链表先走gap步
//    ListNode* shortlist = headA;
//    ListNode* longlist = headB;
//    if (sizea > sizeb) {
//        // 交换指针
//        ListNode* temp = shortlist;
//        shortlist = longlist;
//        longlist = temp;
//    }
//    while (gap--) {
//        longlist = longlist->next;
//    }
//
//    while (shortlist && longlist) {
//        if (longlist == shortlist) {
//            return longlist;
//        }
//        shortlist = shortlist->next;
//        longlist = longlist->next;
//    }
//    return NULL;
//}

////环形链表
//bool hasCycle(struct ListNode* head)
//{
//    struct ListNode* slow = head;
//    struct ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (fast == slow)//相遇
//        {
//            return true;
//        }
//    }
//    return false;
//}
////寻找相遇节点
//typedef struct ListNode ListNode;
//struct ListNode* detectCycle(struct ListNode* head)
//{
//    ListNode* slow = head;
//    ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//        {
//            //寻找相遇点
//            ListNode* pcur = head;
//            while (pcur != slow)
//            {
//                pcur = pcur->next;
//                slow = slow->next;
//            }
//            //pcur=slow
//            return pcur;
//        }
//    }
//    return NULL;
//}