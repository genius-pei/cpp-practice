#define _CRT_SECURE_NO_WARNINGS
#include"Sort.h"
#include"stack.h"

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void insertsort(int* arr, int n)//直接插入排序
{
	for (int i = 0;i < n-1;i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end+1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}
void arrprint(int* arr,int n)
{
	for (int i = 0;i < n;i++)
	{
		printf("%d ", arr[i]);
		
	}
	printf("\n");
}
void shellsort(int* arr, int n)//希尔排序
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0;i < n - gap;i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + 1] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}
void BubbleSort(int* a, int n)//冒泡排序
{
	int exchange = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				exchange = 1;
				swap(&a[j], &a[j + 1]);
			}
		}
		if (exchange == 0)
		{
			break;
		}
	}
}
void SelectSort(int* arr, int n)//直接选择排序
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin + 1;i <= end;i++)//遍历寻找出最大，最小值
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}
		if (maxi == begin)
		{
			maxi = mini;
		}
		swap(&arr[mini], &arr[begin]);
		swap(&arr[maxi], &arr[end]);
		begin++;
		end--;
	}
}
void AdjustDown(int* a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 假设法，选出左右孩⼦中⼩的那个孩⼦
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* arr, int n)//堆排序
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(arr, n, i);
	}
	// O(N*logN)
	int end = n - 1;
	while (end > 0)
	{
		swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		--end;
	}

}
int _QuickSort(int* arr, int left, int right)
{
	int keyi = left;
	++left;
	while (left <= right)
	{
		while (arr[right] > arr[keyi])
		{
			//right从右向左走，寻找小于基准值的
			right--;
		}
		//left从左往右走，找大于基准值的
		while (arr[left] < arr[keyi])
		{
			left++;
		}
		if (left <= right)
		{
			swap(&arr[left++], &arr[right--]);
		}
	}
	swap(&arr[keyi], &arr[right]);
	return right;
}
int lomuto_QuickSort(int* arr, int left, int right)
{
	int keyi = left;
	int prev = left, cur = prev +1;
	while (cur <= right)
	{
		if (arr[cur] < arr[keyi])//当出现大于基准值的数跳过，将小于基准值的数与cur进行交换，最后将基准值交换
		{
			++prev;
			swap(&arr[cur], &arr[prev]);
			++cur;
		}
		else
		{
			++cur;
		}
	}
	swap(&arr[keyi], &arr[prev]);
	return prev;
}

void Quick_SortNOR(int* arr, int left, int right)//非递归快速排序
{
	ST st;
	stackinit(&st);
	stackpush(&st, left);
	stackpush(&st, right);
	
	{
		while (!stackempty(&st))//不为空时取栈顶两个
		{
			int end = stacktop(&st);
			stackpop(&st);
			int begin = stacktop(&st);
			stackpop(&st);
			//[begin，end]中寻找基准值
			int keyi = begin;
			int prev = begin, cur = prev + 1;
			while (cur <= end)
			{
				if (arr[cur] < arr[keyi])
				{
					++prev;
					swap(&arr[cur], &arr[prev]);
				}
				++cur;
			}
			swap(&arr[keyi], &arr[prev]);
			keyi = prev;
			//此时区间[begin,keyi,end]
			if (keyi + 1 < end)//右序列入栈
			{
				stackpush(&st, keyi + 1);
				stackpush(&st, end);
			}
			if (keyi - 1 > begin)
			{
				stackpush(&st, begin);
				stackpush(&st, keyi - 1);
			}
		}
		stackdestroy(&st);
	}
}
void QuickSort(int* arr, int left,int right)//快速排序
{
	if (left >= right)
	{
		return;
	}
	//int keyi = _QuickSort(arr,left,right);//寻找基准值，hore法
	int keyi = lomuto_QuickSort(arr, left, right);//lomuto法
	//left keyi right
	//左序列[left,keyi-1],右序列[keyi+1,right]
	QuickSort(arr, left, keyi - 1);
	QuickSort(arr, keyi + 1, right);
}

void _MergeSort(int* arr, int left, int right,int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = (left + right) / 2;
	//根据mid划分左右两个序列
	_MergeSort(arr, left, mid,tmp);
	_MergeSort(arr, mid+1, right,tmp);
	//合并两个有序序列
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	//对两个区间遍历，排序,合并
	int index = begin1;
	while (begin1 <= end1&&begin2<=end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	
	}
	while(begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}
	//将tmp的数据导入原数组
	for (int i = left;i <= right;i++)
	{
		arr[i] = tmp[i];
	}
}
void MergeSort(int* arr,int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(arr, 0, n - 1, tmp);
	free(tmp);
	tmp = NULL;
}
void CountSort(int* arr, int n)//计数排序
{
	//找最大最小值来确定count数组的大小
	int min = arr[0], max = arr[0];
	for (int i = 1;i < n;i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if(arr[i]>max)
		{
			max = arr[i];
		}
	}
	//max-min+1确定空间大小
	int range = max - min + 1;
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	memset(count, 0, sizeof(int) * range);
	for (int i = 0;i < n;i++)//统计每一个数出现的次数并储存在count中
	{
		count[arr[i] - min]++;
	}
	//将count数组还原到原数组使其有序
	int index = 0;
	for (int i = 0;i < range;i++)
	{
		while (count[i]--)
		{
			arr[index++] = i + min;
		}
	}
	free(count);
}


