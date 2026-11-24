#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"

void HPsort2(int* arr, int n)//堆排序
{
	//根据数组建堆，向下调整建堆
	for (int i = (n - 1 - 1) / 2;i >= 0;i--)
	{
		Adjustdown(arr, i, n);
	}
	//根据堆进行排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		Adjustdown(arr, 0, end);
		end--;
	}

}

void creatdata()
{
	//造数据
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);

}
void topk()
{
	int k = 0;
	printf("请输入k\n");
	scanf("%d", &k);
	const char* file = "data.txt";
	FILE* fout= fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen");
		exit(1);
	}
	//创建前k的数组成堆的空间
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	for (int i = 0;i < k;i++)
	{
		fscanf(fout, "%d", &minheap[i]);
	}
	//创建堆结构,向下建堆
	for (int i = (k - 1 - 1) / 2;i >= 0;i--)
	{
		Adjustdown(minheap, i, k);

	}
	//遍历剩下n-k数据，与堆顶比较
	int x = 0;
	while (fscanf(fout,"%d",&x) != EOF)
	{
		if(x>minheap[0])
		{ 
			minheap[0] = x;
			Adjustdown(minheap, 0, k);
		}
	}
	for (int i = 0;i < k;i++)
	{
		printf("%d ", minheap[i]);
	}
	fclose(fout);

}
void test01()
{
	HP hp;
	HPinit(&hp);
	HPpush(&hp, 56);
	HPpush(&hp, 15);
	HPpush(&hp, 10);
	HPpop(&hp);
	HPprint(&hp);
	
	HPdestroy(&hp);
}
test02()
{
	HP hp;
	HPinit(&hp);
	HPpush(&hp, 66);
	HPpush(&hp, 26);
	HPpush(&hp, 76);
	HPprint(&hp);
	printf("\n");
	while (!HPempty(&hp))
	{
		int top = HPtop(&hp);
		printf("%d ", top);
		HPpop(&hp);
	}
	HPdestroy(&hp);
	
}
//int main()
//{
//	//test01();
//	/*test02();*/
//	int arr[6] = { 19, 23, 45, 43, 22, 11 };
//	/*HPsort1(arr, 6);*/
//	HPsort2(arr, 6);
//	for (int i = 0;i < 6;i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
int main()
{
	topk();
	return 0;
}