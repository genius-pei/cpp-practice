#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;
//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//private:int _a;
//};
//int main()
//{
//	A* p1 = (A*)malloc(sizeof(A));
//	free(p1);
//	A* p2 = new A(1);
//	delete p2;
//	A* p3 = new A[10];
//	delete[]p3;
//
//	return 0;
//}

//int main()
//{
//	for (size_t i = 0;i < 100000;i++)
//	{
//		//int* p1 = (int*)malloc(sizeof(int) * 1024);
//		int* p1 = new int[1024];
//		if (p1)
//		{
//			cout << i << "->" << p1 << endl;
//		}
//		else
//		{
//			break;
//		}
//
//	}
//}
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 2.5, d2 = 3.5;
	cout << Add(a1, a2) << endl;
	cout << Add(d1, d2) << endl;
	return 0;
}