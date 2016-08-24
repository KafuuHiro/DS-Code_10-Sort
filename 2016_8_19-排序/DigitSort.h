#pragma once

//˼�룺���������ǰ��յ�λ������Ȼ���ռ����ٰ��ո�λ����Ȼ�����ռ�;��
//	�����ƣ�ֱ�����λ����ʱ����Щ�����������ȼ�˳��ģ��Ȱ������ȼ�����
//	�ٰ������ȼ��������Ĵ�����Ǹ����ȼ��ߵ���ǰ�������ȼ���ͬ�ĵ���
//	�ȼ��ߵ���ǰ������������ڷֱ����򣬷ֱ��ռ������������ȶ��������㷨��


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
	int* tmp = new int[size];//�������������
	int* b = new int[size];//��ų����������
	
	for (int i = 0; i < size; ++i)//���
	{
		b[i] = a[i];
	}
	
	int digit = GetMaxDigit(a, 10);//��ȡ��������λ��
	while (digit--)
	{
		for (int i = 0; i < size; ++i)//������bִ�г��������������ԭ�����У�����������tmp������
		{
			tmp[i] = b[i] % 10;
			b[i] /= 10;
		}

		//����������ִ��ѡ������swap��ͬʱ��������������Ҳ��֮swap�����ܴﵽ��������
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