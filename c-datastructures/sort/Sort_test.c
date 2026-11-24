#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"

void test01()
{
	int a[] = { 5,4,3,7,8,6,9 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("排序之前:");
	arrprint(a, n);
		insertsort(a, n);
		printf("排序之后:");
		arrprint(a, n);

}
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	int* a8= (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}
	int begin1 = clock();
	insertsort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	shellsort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();

	//int begin7 = clock();
	//BubbleSort(a7, N);
	//int end7 = clock();
	
	int begin8 = clock();
	CountSort(a8, N);
	int end8 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	//printf("BubbleSort:%d\n", end7 - begin7);
	printf("CountSsort:%d\n", end8 - begin8);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
}

void test02()
{
	int a[] = { 5,4,3,7,8,6,9 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("排序之前:");
	arrprint(a, n);
	SelectSort(a, n);
	printf("排序之后:");
	arrprint(a, n);
}
void test03()
{

	int a[] = { 5,4,3,7,8,6,9 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("排序之前:");
	arrprint(a, n);
	QuickSort(a, 0, n - 1);
	printf("排序之后:");
	arrprint(a, n);
}
void test04()
{
	int a[] = { 5,4,3,7,8,6,9 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("排序之前:");
	arrprint(a, n);
	Quick_SortNOR(a, 0, n - 1);
	printf("排序之后:");
	arrprint(a, n);
}
void test05()
{
	int a[] = { 5,4,3,7,8,6,9 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("排序之前:");
	arrprint(a, n);
	MergeSort(a, n);
	printf("排序之后:");
	arrprint(a, n);
}
int main()
{
	/*test01();*/
	TestOP();
	//test02();
	//test03();
	//test04();
	//test05();
	return 0;
}