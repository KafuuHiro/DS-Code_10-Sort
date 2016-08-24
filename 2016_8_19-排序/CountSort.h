#pragma once

//------------------------------------------计数排序-------------------------------------------//
//
//空间复杂度：【O(log(N))】
//		就空间复杂度来说，主要是递归造成的栈空间的使用，如果递归树画出来，它就是一棵斜树。最好情况，递归树的
//		深度为log2n，其空间复杂度也就为O(logn)，最坏情况，需要进行n‐1递归调用，其空间复杂度为O(n)，平均情况，
//		空间复杂度也为O(logn)。
//
//时间复杂度：平均情况：O(N*log(N))
//			  最好情况：O(N*log(N))----->因为每次都将序列分为两个部分(一般二分都复杂度都和logN相关)，故为 O(N*logN)
//			  最坏情况：O(N^2)--->基本有序时，退化为冒泡排序，几乎要比较N*N次，故为O(N*N)
//
//稳定性：【不稳定】 
//
//
//思想：计数排序的基本思想是对于给定的输入序列中的每一个元素x，确定该序列中值小于x的元素的个数（此处并非比较
//	各元素的大小，而是通过对元素值的计数和计数值的累加来确定）。一旦有了这个信息，就可以将x直接存放到最终的输
//	出序列的正确位置上。例如，如果输入序列中只有17个元素的值小于x的值，则x可以直接存放在输出序列的第18个位置上。
//	当然，如果有多个元素具有相同的值时，我们不能将这些元素放在输出序列的同一个位置上，因此，还要作适当的修改
//
//
//思路：1、求出数据中的最值，开辟（max-min+1）个空间countArray
//		2、for循环，统计每个数据出现的次数，数据m的次数就存储在countArray[m]中
//		3、从首元素开始，一次根据countArray中数据次数，将元素放到第count个位置，当有重复，则后移

void CountSort(int* a, int size)
{	
	int max = a[0];
	int min = a[0];
	for (int i = 1; i < size; ++i)
	{
		if (max < a[i])
		{
			max = a[i];
		}
		if (min>a[i])
		{
			min = a[i];
		}
	}

	int range = max - min + 1;
	int* countArray = new int[range];
	memset(countArray,0,range*sizeof(int));

	for (int i = 0; i < size; ++i)
	{
		countArray[a[i] - min]++;
	}

	int index = 0;
	for (int i = 0; i < size; ++i)
	{
		while (countArray[i]-- > 0)
		{
			a[index++] = i;
		}
	}
	delete[] countArray;
}

void CountSortTest()
{
	int a[10] = { 5, 3, 1, 4, 6, 4, 7, 9, 0, 4 };
	//int a[10] = { 5, 3, 1, 2, 6, 4, 7, 9, 0, 8 };
	Print(a, 10);
	CountSort(a, 10);
	Print(a, 10);
}