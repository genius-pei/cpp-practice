 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int removeElement(int* nums, int numsSize, int val)
//{
//    int count = 0;
//    for (int i = 0; i < numsSize; i++) {
//        if (nums[i] != val) {
//            nums[count] = nums[i];
//            count++;
//        }
//    }
//    return count;
//}
void merge(int* nums1, int numnsize, int m, int* nums2, int numsize2, int n)
{
	int l1 = m - 1;
	int l2 = n - 1;
	int l3 = m + n - 1;
	while (l1 >= 0 && l2 >= 0)
	{
		if (nums1[l1] > nums2[l2])
		{
			nums1[l3--] = nums1	[l1--];
		}
		else 
		{
			nums1[l3--] = nums2[l2--];
		}
	}
	while (l2 >= 0)
	{
		nums1[l3--] = nums2[l2--];
	}
}
int main()
{
	int nums1[10] = { 1, 2, 3, 0, 0, 0 };
	int nums2[] = { 2, 5, 6 };
	int m = 3;
	int n = 3;

	printf("Before merge: ");
	for (int i = 0; i < m + n; i++) {
		printf("%d ", nums1[i]);
	}
	printf("\n");

	merge(nums1, 6, m, nums2, 3, n);

	printf("After merge: ");
	for (int i = 0; i < m + n; i++) {
		printf("%d ", nums1[i]);
	}
	printf("\n");

	return 0;
}
