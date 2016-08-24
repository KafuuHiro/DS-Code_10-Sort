#pragma once
//选择排序分为选择排序和堆排序 

//---------------------------选择排序（升序）------------------------//

//空间复杂度：O(1)
//时间复杂度：平均情况：O(N^2)
//			  最好情况：O(N^2)
//			  最坏情况：O(N^2) 
//
//稳定性：【不稳定】
//
//思想：首先在未排序序列中找到最小元素，存放到排序序列的起始位置，然后，
//	再从剩余未排序元素中继续寻找最小元素，然后放到已排序序列末尾。以此
//	类推，直到所有元素均排序完毕。具体做法是：选择最小的元素与未排序部
//	分的首部交换，使得序列的前面为有序。

//思路：1、外层循控制第几层循环
//		2、内层循环控制该层循环的第几次比较
//		3、（升序），若外层循环数据 > 内层循环数据，则交换
//
void SelectSort(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			if (a[i]>a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}


//选择排序的优化，一次选出最大值和最小值
//------------------------方法一----------------------------//
//思路：1、定义left，right控制第几层循环找到的最值的存放位置
//		2、外层循环中，定义两个变量存放该次循环中最值的下标
//		3、内层循环，比较内层循环数据与对应最值下标的数据的大小
//			若大于最大值，就修改最大值下标；
//			若小于最小值，就修改最小值下标；
//		4、交换left与a[minIndex],以及在不是在一次交换两个最值的情况下交换right与a[right].
//			注：当一次交换的值分别为该层的最大值和最小值时，两次交换反而起不到效果，所以要加条件判断
//		5、修改边界值的位置，除去已排序的数据，减小排序范围
void SelectSort_B1(int* a, int size)
{
	int left = 0; 
	int right = size - 1;
	//for (int i = 0; i < size; ++i)
	while (left<right)

	{
		int minIndex = left;
		int maxIndex = right;
		//for (int j = i; j<size-i; ++j)//j<size-i,是防止将已经排好的顺序破坏掉;//注意j=i+1,与下面的B2方法区别开
		for (int j = left; j<=right;++j)
		{
			if (a[j] > a[maxIndex])
			{
				maxIndex = j;//只改变下标，是防止数组中的数据直接被改掉，而导致丢失数据
			}
			else if (a[j] < a[minIndex])
			{
				minIndex = j;
			}
			else
			{
				continue;
			}
		}
		swap(a[left], a[minIndex]);
		if (left != maxIndex || right!=minIndex)//当最值分别位于数组首尾并且反向时，若swap两次，反而会达不到效果，所以加了判断条件
		{
			swap(a[right], a[maxIndex]);
		}
		++left;
		--right;
	}
}

//------------------------方法二----------------------------//
//思路：1、定义left，right控制第几层循环找到的最值的存放位置
//		2、外层循环控制循环的层数
//		3、内层循环，当内层数据a[j]大于右边界值(即最大值位置)，交换两值
//					当a[j]小于左边界值(即最小值位置)，交换两值；否则跳出本次循环
//		4、修改边界值的位置，除去已排序的数据，减小排序范围
//
void SelectSort_B2(int* a, int size)
{
	int left = 0;
	int right = size - 1;
	while (left<right)
	{
		for (int j = left; j < right; ++j)
		{
			if (a[j] > a[right])
			{
				swap(a[j], a[right]);
			}
			else if (a[j] < a[left])
			{
				swap(a[j], a[left]);
			}
			else
			{
				continue;
			}
		}
		++left;
		--right;
	}
}

//--------------------------堆排序---------------------------------//
//
//空间复杂度：O(1)
//时间复杂度：平均情况：O(N*log(N))
//			  最好情况：O(N*log(N))
//			  最坏情况：O(N*log(N)) 
//
//稳定性：【不稳定】
//缺点：不能对链表进行排序
//
//思想：利用完全二叉树中双亲节点和孩子节点之间的内在关系，在当前无序区
//	中选择关键字最大(或者最小)的记录。也就是说，以最小堆为例，根节点为
//	最小元素，较大的节点偏向于分布在堆底附近。在建好小堆以后，还并不是
//	一个已排序数组，只是父节点值小于子节点，左右子节点大小无序，所以还
//	应将每一个结点与根节点互换后，进行一次向下调整，来达到有序。
//
//思路：1、建堆（升序建大堆，降序建小堆）
//		2、循环，每次调整堆最后一个节点
//		3、swap根节点和最后一个节点，这样才能让其完整的向下调整
//		2、调整堆（大堆）
//			(1)、从以根节点的父节点开始向下调整，parent为父节点，child为左孩子结点
//			(2)、判断是否有右孩子结点，若有判断右孩子是否大于左孩子，用child标记孩子中大的一个
//			(3)、判断父节点是否小于child结点，若parent > child，就交换两个结点值
//			(4)、用上一层的孩子节点作为本次的父节点，依次调整，直至全部调整，达到有序
//
//void AdjustDown(int* a, int size, int root)//---------建小堆--》降序-----------//
//{
//	int parent = root;
//	int child = root * 2 + 1;
//	while (child < size)
//	{
//		//判断是否存在右孩子，若存在，并且右孩子 < 小于左孩子，则将child++，使child为孩子中最小的一个
//		if (child + 1 < size && a[child + 1] < a[child])
//		{
//			child++;
//		}
//		if (a[parent]>a[child])
//		{
//			swap(a[parent], a[child]);
//			parent = child;
//			child = 2 * parent + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}


void AdjustDown(int* a, int size, int root)//------------建大堆--》升序--------------//
{
	int parent = root;
	int child = root * 2 + 1;
	while (child < size)
	{
		//判断是否存在右孩子，若存在，并且右孩子 > 小于左孩子，则将child++，使child为孩子中最大的一个
		if (child + 1 < size && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[parent]<a[child])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int size)
{
	//建堆，需要向下调整，（升序建大堆）-->大堆并非有序，只是父节点 > 子节点，左右孩子的
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a,size,i);
	}

	//排序
	for (int i = size - 1; i >= 0; --i)
	{
		swap(a[0], a[i]);
		AdjustDown(a, i, 0);
	}
}





void SelectSortTest()
{
	int a[10] = { 9, 8, 2, 3, 5, 7, 4, 6, 1, 0 };
	Print(a, 10);
	//SelectSort_B1(a, 10);
	SelectSort_B2(a, 10);
	Print(a, 10);
}
void HeapSortTest()
{
	int a[10] = { 1, 8, 9, 3, 5, 7, 4, 6, 2, 0 };
	Print(a, 10);
	HeapSort(a, 10);
	Print(a, 10);
}
