#pragma once

//�������򣺽��������Ϊð������Ϳ�������

//--------------------ð������--------------------//
//
//�ռ临�Ӷȣ�O(1)
//ʱ�临�Ӷȣ�ƽ�������O(N^2)
//			  ��������O(N)----->��������
//			  ������O(N^2)--->��������
//
//�ȶ��ԣ����ȶ��������������ֻ������������Ԫ�ص�λ�á���ˣ�������
//	�����ʱ����û��Ҫ������������λ�õġ����ԣ����ǵ����λ�ò�û��
//	�ı䣬ð�������㷨���ȶ��ģ�
//
//
//˼·��ͨ�������������ڼ�¼�ؼ��ּ�ıȽϺ�λ�õĽ���,ʹ�ؼ�����С
//	�ļ�¼������һ�������ϡ�Ư����ֱ����ˮ�桱�� 
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

//------------------------------------------��������-------------------------------------------//
//
//�ռ临�Ӷȣ���O(log(N))��
//		�Ϳռ临�Ӷ���˵����Ҫ�ǵݹ���ɵ�ջ�ռ��ʹ�ã�����ݹ�����������������һ��б�������������ݹ�����
//		���Ϊlog2n����ռ临�Ӷ�Ҳ��ΪO(logn)����������Ҫ����n�\1�ݹ���ã���ռ临�Ӷ�ΪO(n)��ƽ�������
//		�ռ临�Ӷ�ҲΪO(logn)��
//
//ʱ�临�Ӷȣ�ƽ�������O(N*log(N))
//			  ��������O(N*log(N))----->��Ϊÿ�ζ������з�Ϊ��������(һ����ֶ����Ӷȶ���logN���)����Ϊ O(N*logN)
//			  ������O(N^2)--->��������ʱ���˻�Ϊð�����򣬼���Ҫ�Ƚ�N*N�Σ���ΪO(N*N)
//
//�ȶ��ԣ������ȶ���
//
//˼�룺������ð������Ľ������ġ��ڴ������n����������ȡһ����Ϊ�ؼ���key(ͨ��
//	ȡ���һ������),ʵ�ְѸ����ݷ����ʵ�λ�ú�,�������б����ֳ������֡����бȸ�
//	�ؼ���keyС�����ݷ�����ǰһ����,���б���������ݷ����ں�һ����,���Ѹ�key����
//	�������ֵ��м�(��Ϊ�ü�¼��λ),������̳���һ�˿�������
//
//
//˼·��1����������left < rightΪ����ѭ��,ִ������
//		2�����ȣ�������������䣬����ȡkeyֵ����λ�õ��±�boundary
//		3����boundaryΪ�磬�ֱ��������ҵ�����Ϊ���䣬�ٴ�ִ�е�������
//		4��������������
//			��1����rightλ�õ�����Ϊ�ؼ���key��begin��endΪ�µı߽�ֵ[left,right-1]
//			��2����ѭ������ѭ��������begin < endΪ����
//			��3���ڲ�����ѭ������a[begin]С��keyֵ��begin++��a[end]����keyֵ��end--��(����Ϊbegin��endһֱ�ڸı䣬����ÿ������ǰ��Ӧ���ж�begin<end)
//			��4��������ѭ������ִ�е�begin<end����ʾ����a[begin]>key,a[end]<key,��ôswap����ֵ��������ֵ������ȷ������
//			��5����ѭ���⣬���a[begin]>a[right],swap������keyֵ�ҵ�����λ�ã�ʹ������keyΪ�ֽ磬��С�Ҵ�
//
//
//
//******************��������1����ͨ������************************//
int PartitionSort_1(int* a, int left, int right)
{
	int key = a[right];
	int begin = left;
	int end = right - 1;
	while (begin < end)//����ѭ������
	{
		while (begin < end && a[begin] <= key)//���begin < end����Ϊ��ȷ�����޸Ĺ�beginֵ�����ɷ���begin < end����
		{
			++begin;
		}
		while (begin < end && a[end] >= key)//���begin < end����Ϊ��ȷ�����޸Ĺ�endֵ�����ɷ���begin < end����
		{
			--end;
		}
		if (begin < end)//��begin < end����ʾ���ҷֱ��Ӧһ����key�󣬱�keyС��ֵ��swap���ͽ�����ֵ�ŵ�����ȷ����
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


//***********************��������2������ֱ�Ӳ�������*******************************//
//�Ż�������������right-left<13ʱ���Ͳ��ÿ����ˣ�ֱ��ʹ�ò�������Ч����Ը�һЩ��

//˼·��1���ж�right-left<13��ִ�п��������㷨
//		2���������ֱ�Ӳ�������

void QuickSort_2(int* a, int left, int right)
{	
	//......................�����޸Ĳ���.....................//
	
	if (right - left > 13)
	{
	
	//........................................................
		if (left < right)
		{
			int boundary = PartitionSort_1(a, left, right);
			QuickSort_2(a, left, boundary - 1);
			QuickSort_2(a, boundary + 1, right);
		}

	//......................�����޸Ĳ���.....................//
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


//***********************��������3������ȡ�з���*******************************//
//�Ż���������ȡ�з���ѡ��keyֵ��ѡһ����Ϊ���ʵ�ֵ�����ܿ�right��Ϊ��ֵ�����

//
//˼·��1����������left < rightΪ����ѭ��,ִ������
//		2������GetMidIndex����ȡ�����С��������������м�ֵ�������±�mid
//		3������a[mid]��a[right]��ʹa[right]Ϊ�ؼ���key�������ô���
//		2�����ȣ�������������䣬����ȡkeyֵ����λ�õ��±�boundary
//		3����boundaryΪ�磬�ֱ��������ҵ�����Ϊ���䣬�ٴ�ִ�е�������
//		4��������������
//			��1����rightλ�õ�����Ϊ�ؼ���key��begin��endΪ�µı߽�ֵ[left,right-1]
//			��2����ѭ������ѭ��������begin < endΪ����
//			��3���ڲ�����ѭ������a[begin]С��keyֵ��begin++��a[end]����keyֵ��end--��(����Ϊbegin��endһֱ�ڸı䣬����ÿ������ǰ��Ӧ���ж�begin<end)
//			��4��������ѭ������ִ�е�begin<end����ʾ����a[begin]>key,a[end]<key,��ôswap����ֵ��������ֵ������ȷ������
//			��5����ѭ���⣬���a[begin]>a[right],swap������keyֵ�ҵ�����λ�ã�ʹ������keyΪ�ֽ磬��С�Ҵ�
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
	//......................�����޸Ĳ��֣�����δ�ı䣩.....................//
	
	int midIndex = GetMidIndex(a, left, right);//�ҵ����ʵ����ݵ��±�
	swap(a[right], a[midIndex]);//�������ݻ���right��λ��
	
	//.....................................................................//
	
	int key = a[right];
	int begin = left;
	int end = right - 1;
	while (begin < end)//����ѭ������
	{
		while (begin < end && a[begin] <= key)//���begin < end����Ϊ��ȷ�����޸Ĺ�beginֵ�����ɷ���begin < end����
		{
			++begin;
		}
		while (begin < end && a[end] >= key)//���begin < end����Ϊ��ȷ�����޸Ĺ�endֵ�����ɷ���begin < end����
		{
			--end;
		}
		if (begin < end)//��begin < end����ʾ���ҷֱ��Ӧһ����key�󣬱�keyС��ֵ��swap���ͽ�����ֵ�ŵ�����ȷ����
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


//***********************��������4���ڿӷ���*******************************//
//�Ż������ڿӷ�����a[right]����key�У�beginָ��������һ�����������䷶Χ�����ݷŵ�rightλ�ã�
//				��ʱ��a[begin]�γ�һ���ӣ�Ȼ��endָ���ҵ���һ�������ϵ����ݣ��������������a[begin]�У�
//				����ʱ��a[end]�γɿӣ������ƶ�beginָ�룬ֱ��begin==end���ٽ�key�������Ŀ���

//
//˼·��1����������left < rightΪ����ѭ��,ִ������
//		2������GetMidIndex����ȡ�����С��������������м�ֵ�������±�mid
//		3������a[mid]��a[right]��ʹa[right]Ϊ�ؼ���key�������ô���
//		2�����ȣ�������������䣬����ȡkeyֵ����λ�õ��±�boundary
//		3����boundaryΪ�磬�ֱ��������ҵ�����Ϊ���䣬�ٴ�ִ�е�������
//		4��������������
//			��1����rightλ�õ�����Ϊ�ؼ���key��begin��endΪ�µı߽�ֵ[left,right]
//			��2����ѭ������ѭ��������begin < endΪ����
//			��3���ڲ�����ѭ������a[begin]С��keyֵ��begin++�����a[begin]>key,��a[begin]�����a[end]��
//			��4��a[end]����keyֵ��end--�����a[end]<key,��a[end]�����a[begin]��
//			��5��ִ�е�begin==end����ѭ������key��ص�a[begin]�У�������begin
//
int PartitionSort_4(int* a, int left, int right)
{
	int key = a[right];
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while (begin < end && a[begin] < key)//beginָ���ƶ���ѭ���� < keyֵ������ֹͣ
		{
			begin++;
		}
		if (begin < end)
		{
			a[end] = a[begin];//�������endָ��ָ��Ŀ���
		}

		while (begin<end&& a[end]>key)//endָ���ƶ���ѭ���� > keyֵ������ֹͣ
		{
			end--;
		}
		if (begin < end)
		{
			a[begin] = a[end];//�������beginָ��ָ��Ŀ���
		}

	}
	a[begin] = key;//��keyֵ�ƶ������ʣ�µĿ����ʱbegin==end������д��һ����OK
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



//********************************��������5*************************************//
//�Ż��ģ�cur��С��������keyС�Ĳ�ֹͣ��ÿ��ͣ������prev++һ�Σ���cur������prevʱ��prevָ
//		��ֵ��curָ��ֵ��������cur��keyֵ֮ǰ��λ��ʱ��prev++��keyֵ��prev�������ݹ�
//
//˼·��1����������
//			��1����a[right]��Ϊkeyֵ��curΪ��ǰleft��prevΪcur��ǰһ���±�ֵ
//			��2����ѭ������left<rightΪ����
//			��3����ѭ������a[cur]>keyʱ��cur++����a[cur]<key������ѭ����++prev����ִ��++
//			��4����ʱ��cur==prev,���ʾֻ����һ��������cur!=prev����ʾa[cur]<key,����a[prev]>key,������ֵ��ʹС����ǰ������ں�
//			��5��ֱ��������ѭ������ʱa[prev]>key,a[right]==key,������ֵ��ʹkey�������λ�ø�����������
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

//********************************��������6*************************************//
//�Ż��壺���Ż�4ת����һ������
//˼·�����Ż�4�����������ϲ�Ϊһ������
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

//***********************��������7�����ǵݹ顿��*******************************//
//����������ջ

//˼·��1������һ��ջ������������������±���ջ�������ң�������
//		2����ջ��Ϊ�գ����¶��������߽�ֵ��¼�߽�
//		3������PartitionSort��������ֽ�ֵ�±�
//		4����_left < boundary - 1ʱ�����ñ߽���ջ
//		5��boundary + 1 < _rightʱ�����߽���ջ���Դ�ʵ������Ĳ��ϻ���
//
//
//
#include<stack>

void QuickSort_7(int* a, int left, int right)
{
	stack<int> s;
	s.push(right);//������ı߽��±���ջ
	s.push(left);
	while (!s.empty())
	{
		int _left = s.top();
		s.pop();
		int _right = s.top();
		s.pop();
		int boundary = PartitionSort_3(a, _left, _right);//�µ�����߽�ֽ�ֵ
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