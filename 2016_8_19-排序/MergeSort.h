#pragma once
#include<string>


//--------------------归并排序--------------------//
//
//空间复杂度：O(N)
//时间复杂度：平均情况：O(N*log(N))
//			  最好情况：O(N*log(N))----->一趟归并需要n次，总共需要logN次，因此为O(N*logN) 
//			  最坏情况：O(N*log(N))--->接近于平均情况下，为O(N*logN) 
//	说明：对长度为n的文件，需进行logN 趟二路归并，每趟归并的时间为O(n)，故其时间复杂度无
//		论是在最好情况下还是在最坏情况下均是O(nlgn)。
//
//稳定性:【稳定】
//	归并排序最大的特色就是它是一种稳定的排序算法。归并过程中是不会改变元素的相对位置的。
//
//缺点是，它需要O(n)的额外空间。
//优点是，很适合于多链表排序。
//
//
//
//思想：先将无序表分割成为单个只有一个数据的区间则单个区间内有序，
//		然后多次将两个小的有序区间合并成一个新的大区间。 
//
//
//思路：1、主函数中开辟数组空间，调用区间分割函数 _MergeSort，最后释放空间
//		2、区间分割函数 _MergeSort中：
//			（1）求出区间下标中间值mid
//			（2）分别以【left,mid】和【mid+1,right】为区间继续递归
//			（3）直至递归到每个区间只有一个数据，则该区间在区间内有序
//			（4）然后调用区间合并函数MergeSection，将两个小区间合并成一个大区间
//			（5）区间合并函数MergeSection：
//					1）用index标记tmp中存放数据的下标
//					2）外循环，当begin1 <= end1 && begin2 <= end2时，选小的一次存入tmp
//					3）跳出循环表示其中一个区间数据用完，那就将剩余数据依次存储至tmp
//			（6）将tmp中的内容拷贝到a中
//
void MergeSection(int*a, int* tmp, int begin1, int end1, int begin2, int end2)
{
	int index = begin1;//不能写成0，因为递归调用，它的首数据位置不一定是0，所以应该写成前面区间的首地址
	while (begin1 <= end1 && begin2 <= end2)//两个区间内部均有数据时
	{
		if (a[begin1] < a[begin2])//找到两个区间的最小值作为新区间的首
		{
			tmp[index++] = a[begin1++];
		}
		else //a[begin1] > a[begin2]
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)//当区间2无数据时，直接将区间1已排序的数据放到tmp中
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)//当区间1无数据时，直接将区间2已排序的数据放到tmp中
	{
		tmp[index++] = a[begin2++];
	}
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;//求出区间的下标中间值
		
		_MergeSort(a, tmp, left, mid);//分别以左区间、右区间递归，直至区间个数为1，成为有序区域不需要排序
		_MergeSort(a, tmp, mid + 1, right);

		MergeSection(a, tmp, left, mid, mid + 1, right);//对已排序的两个小区间进行合并，合并成大的有序序列
		
		memcpy(a + left, tmp + left, (right - left + 1)*sizeof(int));//将tmp的内容拷给a
	}
}

void MergeSort(int* a, int left, int right)
{
	int* tmp = new int[right - left + 1];
	memset(tmp, 0, sizeof(int)*(right - left + 1));
	_MergeSort(a, tmp, left, right);
	delete[] tmp;
}

void MergeSortTest()
{
	int a[10] = { 5, 3, 1, 8, 6, 2, 7, 9, 0, 4 };
	Print(a, 10);
	MergeSort(a, 0, 9);
	Print(a, 10);
}