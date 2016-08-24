#pragma once
#include<string>


//--------------------�鲢����--------------------//
//
//�ռ临�Ӷȣ�O(N)
//ʱ�临�Ӷȣ�ƽ�������O(N*log(N))
//			  ��������O(N*log(N))----->һ�˹鲢��Ҫn�Σ��ܹ���ҪlogN�Σ����ΪO(N*logN) 
//			  ������O(N*log(N))--->�ӽ���ƽ������£�ΪO(N*logN) 
//	˵�����Գ���Ϊn���ļ��������logN �˶�·�鲢��ÿ�˹鲢��ʱ��ΪO(n)������ʱ�临�Ӷ���
//		�������������»����������¾���O(nlgn)��
//
//�ȶ���:���ȶ���
//	�鲢����������ɫ��������һ���ȶ��������㷨���鲢�������ǲ���ı�Ԫ�ص����λ�õġ�
//
//ȱ���ǣ�����ҪO(n)�Ķ���ռ䡣
//�ŵ��ǣ����ʺ��ڶ���������
//
//
//
//˼�룺�Ƚ������ָ��Ϊ����ֻ��һ�����ݵ������򵥸�����������
//		Ȼ���ν�����С����������ϲ���һ���µĴ����䡣 
//
//
//˼·��1���������п�������ռ䣬��������ָ�� _MergeSort������ͷſռ�
//		2������ָ�� _MergeSort�У�
//			��1����������±��м�ֵmid
//			��2���ֱ��ԡ�left,mid���͡�mid+1,right��Ϊ��������ݹ�
//			��3��ֱ���ݹ鵽ÿ������ֻ��һ�����ݣ��������������������
//			��4��Ȼ���������ϲ�����MergeSection��������С����ϲ���һ��������
//			��5������ϲ�����MergeSection��
//					1����index���tmp�д�����ݵ��±�
//					2����ѭ������begin1 <= end1 && begin2 <= end2ʱ��ѡС��һ�δ���tmp
//					3������ѭ����ʾ����һ�������������꣬�Ǿͽ�ʣ���������δ洢��tmp
//			��6����tmp�е����ݿ�����a��
//
void MergeSection(int*a, int* tmp, int begin1, int end1, int begin2, int end2)
{
	int index = begin1;//����д��0����Ϊ�ݹ���ã�����������λ�ò�һ����0������Ӧ��д��ǰ��������׵�ַ
	while (begin1 <= end1 && begin2 <= end2)//���������ڲ���������ʱ
	{
		if (a[begin1] < a[begin2])//�ҵ������������Сֵ��Ϊ���������
		{
			tmp[index++] = a[begin1++];
		}
		else //a[begin1] > a[begin2]
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)//������2������ʱ��ֱ�ӽ�����1����������ݷŵ�tmp��
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)//������1������ʱ��ֱ�ӽ�����2����������ݷŵ�tmp��
	{
		tmp[index++] = a[begin2++];
	}
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;//���������±��м�ֵ
		
		_MergeSort(a, tmp, left, mid);//�ֱ��������䡢������ݹ飬ֱ���������Ϊ1����Ϊ����������Ҫ����
		_MergeSort(a, tmp, mid + 1, right);

		MergeSection(a, tmp, left, mid, mid + 1, right);//�������������С������кϲ����ϲ��ɴ����������
		
		memcpy(a + left, tmp + left, (right - left + 1)*sizeof(int));//��tmp�����ݿ���a
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