#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{

	}
	~SmartPtr()
	{
		cout << "delete:" << _ptr << endl;
		delete[] _ptr;
	}
private:
	T* _ptr;
};
int main()
{
	int* p1 = new int[10];
	SmartPtr<int> sp1(p1);
	return 0;
}