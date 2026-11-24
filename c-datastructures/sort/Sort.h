#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void insertsort(int* arr, int n);//直接插入排序
void arrprint(int* arr, int n);//数组打印
void shellsort(int* arr, int n);//希尔排序
void BubbleSort(int* a, int n);//冒泡排序
void SelectSort(int* arr, int n);//直接选择排序
void HeapSort(int* arr, int n);//堆排序
void QuickSort(int* arr, int left,int right);//快速排序
int _QuickSort(int* arr,int left,int right);//寻找基准值
int lomuto_QuickSort(int* arr, int left, int right);//lomuto寻找基准值
void Quick_SortNOR(int* arr, int left, int right);//非递归快速排序
void MergeSort(int* arr, int n);//归并排序
void CountSort(int* arr, int n);//计数排序