#pragma once

//思想：基数排序是按照低位先排序，然后收集；再按照高位排序，然后再收集;依
//	次类推，直到最高位。有时候有些属性是有优先级顺序的，先按低优先级排序，
//	再按高优先级排序，最后的次序就是高优先级高的在前，高优先级相同的低优
//	先级高的在前。基数排序基于分别排序，分别收集，所以其是稳定的排序算法。


int GetMaxDigit(int* a,int size)
{
	int max = 10;
	int digit = 1;
	for (int i = 0; i < size; ++i)
	{
		while (a[i]>=max)
		{
			digit++;
			max *= 10;
		}
	}
	return digit;
}

void DigitSort(int* a, int size)
{
	int* tmp = new int[size];//存放余数的数组
	int* b = new int[size];//存放除法后的数组
	
	for (int i = 0; i < size; ++i)//深拷贝
	{
		b[i] = a[i];
	}
	
	int digit = GetMaxDigit(a, 10);//获取最大的数据位数
	while (digit--)
	{
		for (int i = 0; i < size; ++i)//对数组b执行除法，结果保存在原数组中，余数保存在tmp数组中
		{
			tmp[i] = b[i] % 10;
			b[i] /= 10;
		}

		//对余数数组执行选择排序，swap的同时，其余两个数组也随之swap，才能达到最后的有序
		for (int i = 0; i < size; ++i)
		{
			for (int j = i; j < size; ++j)
			{
				if (tmp[i]>tmp[j])
				{
					swap(tmp[i], tmp[j]);
					swap(b[i], b[j]);
					swap(a[i], a[j]);
				}
			}
		}
	}
	
	delete[] tmp;
}

void DigitSortTest()
{
	int a[10] = { 10, 64, 27, 899, 5555555, 213, 54, 60, 34, 1 };
	Print(a, 10);
	DigitSort(a, 10);
	Print(a, 10);
}