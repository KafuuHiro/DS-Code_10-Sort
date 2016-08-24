#pragma once

//交换排序：交换排序分为冒泡排序和快速排序

//--------------------冒泡排序--------------------//
//
//空间复杂度：O(1)
//时间复杂度：平均情况：O(N^2)
//			  最好情况：O(N)----->正序有序
//			  最坏情况：O(N^2)--->逆序有序
//
//稳定性：【稳定】。排序过程中只交换相邻两个元素的位置。因此，当两个
//	数相等时，是没必要交换两个数的位置的。所以，它们的相对位置并没有
//	改变，冒泡排序算法是稳定的！
//
//
//思路：通过无序区中相邻记录关键字间的比较和位置的交换,使关键字最小
//	的记录如气泡一般逐渐往上“漂浮”直至“水面”。 
void BubbleSort(int* a, int size)
{
	for (int j = 0; j < size;++j)
	{
		for (int i = 0; i < size - 1; ++i)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
			}
		}
	}
	
}

void BubbleSortTest()
{
	int a[10] = { 9, 8, 1, 3, 5, 7, 4, 6, 2, 0 };
	Print(a, 10);
	BubbleSort(a, 10);
	Print(a, 10);
}

//------------------------------------------快速排序-------------------------------------------//
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
//思想：它是由冒泡排序改进而来的。在待排序的n个数据中任取一个作为关键字key(通常
//	取最后一个数据),实现把该数据放入适当位置后,数组序列被划分成两部分。所有比该
//	关键字key小的数据放置在前一部分,所有比它大的数据放置在后一部分,并把该key排在
//	这两部分的中间(称为该记录归位),这个过程称作一趟快速排序。
//
//
//思路：1、主函数以left < right为条件循环,执行排序
//		2、首先，单趟排序该区间，并获取key值所在位置的下标boundary
//		3、以boundary为界，分别以其左、右单独作为区间，再次执行单趟排序
//		4、单趟排序函数：
//			（1）以right位置的数据为关键字key，begin、end为新的边界值[left,right-1]
//			（2）外循环控制循环次数，begin < end为条件
//			（3）内部两个循环，当a[begin]小于key值，begin++；a[end]大于key值，end--；(但因为begin、end一直在改变，所以每个条件前还应该判断begin<end)
//			（4）当在外循环内若执行到begin<end，表示现在a[begin]>key,a[end]<key,那么swap两个值，是两个值到了正确的区间
//			（5）外循环外，如果a[begin]>a[right],swap，帮助key值找到他的位置，使数组以key为分界，左小右大
//
//
//
//******************快速排序1（普通方法）************************//
int PartitionSort_1(int* a, int left, int right)
{
	int key = a[right];
	int begin = left;
	int end = right - 1;
	while (begin < end)//控制循环次数
	{
		while (begin < end && a[begin] <= key)//添加begin < end，是为了确保在修改过begin值后，依旧符合begin < end条件
		{
			++begin;
		}
		while (begin < end && a[end] >= key)//添加begin < end，是为了确保在修改过end值后，依旧符合begin < end条件
		{
			--end;
		}
		if (begin < end)//当begin < end，表示左右分别对应一个比key大，比key小的值，swap，就将两个值放到了正确区域
		{
			swap(a[begin], a[end]);
		}
	}
	if (a[begin]>a[right])
	{
		swap(a[begin], a[right]);
		return begin;
	}
	return right;
}

void QuickSort_1(int* a, int left, int right)
{
	if (left < right)
	{
		int boundary = PartitionSort_1(a, left, right);
		QuickSort_1(a, left, boundary - 1);
		QuickSort_1(a, boundary + 1, right);
	}	
}
void QuickSortTest_1()
{
	int a[10] = { 9, 1, 3, 7, 4, 6, 2, 5, 8, 0 };
	Print(a, 10);
	QuickSort_1(a, 0, 9);
	Print(a, 10);
}  


//***********************快速排序2（调用直接插入排序）*******************************//
//优化方法：当数组right-left<13时，就不用快排了，直接使用插入排序效率相对高一些，

//思路：1、判断right-left<13，执行快速排序算法
//		2、否则调用直接插入排序

void QuickSort_2(int* a, int left, int right)
{	
	//......................代码修改部分.....................//
	
	if (right - left > 13)
	{
	
	//........................................................
		if (left < right)
		{
			int boundary = PartitionSort_1(a, left, right);
			QuickSort_2(a, left, boundary - 1);
			QuickSort_2(a, boundary + 1, right);
		}

	//......................代码修改部分.....................//
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
	//........................................................
}


void QuickSortTest_2()
{
	int a[10] = { 9, 1, 3, 7, 4, 6, 2, 5, 8, 0 };
	Print(a, 10);
	QuickSort_1(a, 0, 9);
	Print(a, 10);
}


//***********************快速排序3（三数取中法）*******************************//
//优化二：三数取中法，选择key值挑选一个较为合适的值，而避开right处为最值的情况

//
//思路：1、主函数以left < right为条件循环,执行排序
//		2、调用GetMidIndex函数取到左、中、右三个数据中中间值的数据下标mid
//		3、交换a[mid]与a[right]，使a[right]为关键字key，这样好处理
//		2、首先，单趟排序该区间，并获取key值所在位置的下标boundary
//		3、以boundary为界，分别以其左、右单独作为区间，再次执行单趟排序
//		4、单趟排序函数：
//			（1）以right位置的数据为关键字key，begin、end为新的边界值[left,right-1]
//			（2）外循环控制循环次数，begin < end为条件
//			（3）内部两个循环，当a[begin]小于key值，begin++；a[end]大于key值，end--；(但因为begin、end一直在改变，所以每个条件前还应该判断begin<end)
//			（4）当在外循环内若执行到begin<end，表示现在a[begin]>key,a[end]<key,那么swap两个值，是两个值到了正确的区间
//			（5）外循环外，如果a[begin]>a[right],swap，帮助key值找到他的位置，使数组以key为分界，左小右大
//
int GetMidIndex(int* a, int left, int right)
{
	int mid = (right - left) / 2 + left;
	if (a[left] > a[right])
	{
		if (a[mid] > a[left])    //a[mid] > a[left] > a[right]
		{
			return left;
		}
		else if (a[mid] < a[right])//a[left] > a[right] > a[mid]
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
	else //a[left] < a[right]
	{
		if (a[mid] < a[left])   //a[mid] < a[left] < a[right]
		{
			return left;
		}
		else if (a[mid] > a[right])   //a[left] < a[right] < a[mid]
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
}
int PartitionSort_3(int* a, int left, int right)
{
	//......................代码修改部分（其余未改变）.....................//
	
	int midIndex = GetMidIndex(a, left, right);//找到合适的数据的下标
	swap(a[right], a[midIndex]);//将该数据换到right的位置
	
	//.....................................................................//
	
	int key = a[right];
	int begin = left;
	int end = right - 1;
	while (begin < end)//控制循环次数
	{
		while (begin < end && a[begin] <= key)//添加begin < end，是为了确保在修改过begin值后，依旧符合begin < end条件
		{
			++begin;
		}
		while (begin < end && a[end] >= key)//添加begin < end，是为了确保在修改过end值后，依旧符合begin < end条件
		{
			--end;
		}
		if (begin < end)//当begin < end，表示左右分别对应一个比key大，比key小的值，swap，就将两个值放到了正确区域
		{
			swap(a[begin], a[end]);
		}
	}
	if (a[begin]>a[right])
	{
		swap(a[begin], a[right]);
		return begin;
	}
	return right;
}


void QuickSort_3(int* a, int left, int right)
{
	if (left < right)
	{
		int boundary = PartitionSort_3(a, left, right);
		QuickSort_3(a, left, boundary - 1);
		QuickSort_3(a, boundary + 1, right);
	}

}

void QuickSortTest_3()
{
	int a[10] = { 9, 1, 3, 7, 4, 6, 2, 5, 8, 0 };
	Print(a, 10);
	QuickSort_3(a, 0, 9);
	Print(a, 10);
}


//***********************快速排序4（挖坑法）*******************************//
//优化三：挖坑法，将a[right]存入key中，begin指针先挑出一个不符合区间范围的数据放到right位置，
//				此时，a[begin]形成一个坑，然后end指针找到下一个不符合的数据，将该数据填入坑a[begin]中，
//				而这时候，a[end]形成坑，继续移动begin指针，直至begin==end，再将key填入最后的坑中

//
//思路：1、主函数以left < right为条件循环,执行排序
//		2、调用GetMidIndex函数取到左、中、右三个数据中中间值的数据下标mid
//		3、交换a[mid]与a[right]，使a[right]为关键字key，这样好处理
//		2、首先，单趟排序该区间，并获取key值所在位置的下标boundary
//		3、以boundary为界，分别以其左、右单独作为区间，再次执行单趟排序
//		4、单趟排序函数：
//			（1）以right位置的数据为关键字key，begin、end为新的边界值[left,right]
//			（2）外循环控制循环次数，begin < end为条件
//			（3）内部两个循环，当a[begin]小于key值，begin++；如果a[begin]>key,将a[begin]填入坑a[end]中
//			（4）a[end]大于key值，end--；如果a[end]<key,将a[end]填入坑a[begin]中
//			（5）执行到begin==end跳出循环，把key填回到a[begin]中，并返回begin
//
int PartitionSort_4(int* a, int left, int right)
{
	int key = a[right];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && a[begin] < key)//begin指针移动，循环至 < key值的数据停止
		{
			begin++;
		}
		if (begin < end)
		{
			a[end] = a[begin];//将数据填到end指针指向的坑里
		}

		while (begin<end&& a[end]>key)//end指针移动，循环至 > key值的数据停止
		{
			end--;
		}
		if (begin < end)
		{
			a[begin] = a[end];//将数据填到begin指针指向的坑里
		}

	}
	a[begin] = key;//将key值移动到最后剩下的坑里，此时begin==end，所以写哪一个都OK
	return begin;
}
void QuickSort_4(int* a, int left, int right)
{
	if (left < right)
	{
		int boundary = PartitionSort_4(a, left, right);
		QuickSort_4(a, left, boundary - 1);
		QuickSort_4(a, boundary + 1, right);
	}

}

void QuickSortTest_4()
{
	int a[10] = { 9, 1, 3, 7, 4, 6, 2, 5, 8, 0 };
	Print(a, 10);
	QuickSort_4(a, 0, 9);
	Print(a, 10);
}



//********************************快速排序5*************************************//
//优化四：cur找小，遇到比key小的才停止，每次停下来后，prev++一次，当cur不等于prev时，prev指
//		向值与cur指向值交换，当cur到key值之前的位置时，prev++，key值与prev交换，递归
//
//思路：1、单趟排序：
//			（1）以a[right]作为key值，cur为当前left，prev为cur的前一个下标值
//			（2）外循环，以left<right为条件
//			（3）内循环，当a[cur]>key时，cur++，当a[cur]<key，跳出循环，++prev，先执行++
//			（4）此时若cur==prev,则表示只走了一步，但当cur!=prev，表示a[cur]<key,并且a[prev]>key,交换两值，使小的在前，大的在后
//			（5）直至跳出外循环，此时a[prev]>key,a[right]==key,交换两值，使key到达合适位置隔开两个区域
//

int PartitionSort_5(int* a, int left, int right)
{
	int key = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
		{
			swap(a[cur], a[prev]);
		}
		++cur;
	}
	swap(a[++prev], a[right]);
	return prev;
}

void QuickSort_5(int* a, int left, int right)
{
	if (left < right)
	{
		int boundary = PartitionSort_5(a, left, right);
		QuickSort_5(a, left, boundary - 1);
		QuickSort_5(a, boundary + 1, right);
	}

}

void QuickSortTest_5()
{
	int a[10] = { 9, 1, 3, 7, 4, 6, 2, 5, 8, 0 };
	Print(a, 10);
	QuickSort_5(a, 0, 9);
	Print(a, 10);
}

//********************************快速排序6*************************************//
//优化五：将优化4转换成一个函数
//思路：将优化4的两个函数合并为一个函数
void QuickSort_6(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = a[right];
	int cur = left;
	int prev = left - 1;
	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
		{
			swap(a[cur], a[prev]);
		}
		cur++;
	}
	swap(a[++prev], a[right]);
	
	QuickSort_6(a, left, prev - 1);
	QuickSort_6(a, prev + 1, right);


}

void QuickSortTest_6()
{
	int a[10] = { 9, 1, 3, 7, 4, 6, 2, 5, 8, 0 };
	Print(a, 10);
	QuickSort_6(a, 0, 9);
	Print(a, 10);
}

//***********************快速排序7（【非递归】）*******************************//
//方法：借助栈

//思路：1、定义一个栈，将数组的左右区间下标入栈（先入右，再入左）
//		2、当栈不为空，重新定义两个边界值记录边界
//		3、调用PartitionSort函数求出分界值下标
//		4、当_left < boundary - 1时，将该边界入栈
//		5、boundary + 1 < _right时，将边界入栈，以此实现区间的不断划分
//
//
//
#include<stack>

void QuickSort_7(int* a, int left, int right)
{
	stack<int> s;
	s.push(right);//将数组的边界下标入栈
	s.push(left);
	while (!s.empty())
	{
		int _left = s.top();
		s.pop();
		int _right = s.top();
		s.pop();
		int boundary = PartitionSort_3(a, _left, _right);//新的区域边界分界值
		if (_left < boundary - 1)
		{
			s.push(boundary - 1);
			s.push(left);
		}
		if (boundary + 1 < _right)
		{
			s.push(right);
			s.push(boundary + 1);
		}
	}
}


void QuickSortTest_7()
{
	int a[10] = { 9, 1, 3, 7, 4, 6, 2, 8, 0, 5 };
	Print(a, 10);
	QuickSort_7(a, 0, 9);
	Print(a, 10);
}