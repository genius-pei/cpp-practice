#define _CRT_SECURE_NO_WARNINGS
#include"heap.h"
void CreateNDate()
{
	// 造数据
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("创建文件失败");
		return;
	}
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
	const char* file = "data.txt"; //最开始当前目录下面没有这个文件
	FILE* fout = fopen(file, "r"); //然后你以W+的方式创建了一个新文件并打开了
	if (fout == NULL)
	{
		perror("无法打开文件");
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
		fscanf(fout, "%d", &minheap[i]); //然后新文件里面没有数据 你的读取就是有问题的
	}
	//创建堆结构,向下建堆
	for (int i = (k - 1 - 1) / 2;i >= 0;i--)
	{
		Adjustdown(minheap, i, k);

	}
	//遍历剩下n-k数据，与堆顶比较
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minheap[0])
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

int main()
{
	CreateNDate();
	topk();
	return 0;
}
