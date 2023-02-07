#include<iostream>
#include<stdlib.h>
using namespace std;

int counter = 0;
/***************** Parameter Setting *****************/
int const InsideCount = 3;//frames
int Inside[InsideCount];
int const PageCount = 20;//总的页面数
int Page[PageCount] = { 1, 2, 3, 4, 2, 1, 5, 6, 2, 1, 2, 3, 7, 6, 3, 2, 1, 2, 3, 6 };

int insert = 0;//先used in FIFO
double lost = 0.0;

bool isInside(int num)//check whether the page is in memory or not
{
	for (int i = 0; i < InsideCount; i++)
	{
		if (Inside[i] == Page[num])
		{
			return true;
		}
	}
	return false;
}

void LRU(int num)
{
	int max = 0;   //表示内存中的页号，下一次出现的距离
	int maxchange; //表示内存中下次出现距离最大的页号在内存中的位置
	int k;
	if (isInside(num))
	{
		cout << "It is already in memory!" << endl;
		for (int i = 0; i <InsideCount; i++)
			cout << "Inside[" << i << "]:" << Inside[i] << endl;
	}
	else
		if (counter == InsideCount)
		{
			lost++;
			for (int j = 0; j < InsideCount; j++)
			{
				//从当前的页号向前看，发现页号与内存中的页号相同，break ；比较内存中三个页号，看哪一个走的远，用max记录
				//*****************************在这里补充算法*****************************************
				
				
				
			}
			Inside[maxchange] = Page[num];
			for (int i = 0; i <InsideCount; i++)
				cout << "Inside[" << i << "]:" << Inside[i] << endl;
		}
		else
		{
			Inside[counter] = Page[num];
			counter++;

			for (int i = 0; i <InsideCount; i++)
				cout << "Inside[" << i << "]:" << Inside[i] << endl;
		}
}

void FIFO(int num)
{
	if (isInside(num))
	{
		cout << "It is already in memory!" << endl;
		for (int i = 0; i <InsideCount; i++)
			cout << "Inside[" << i << "]:" << Inside[i] << endl;
	}
	else
		if (counter == InsideCount)
		{
		   //*****************************在这里补充算法*****************************************
			
			for (int i = 0; i <InsideCount; i++)
				cout << "Inside[" << i << "]:" << Inside[i] << endl;
		}
		else
		{
			Inside[counter] = Page[num];
			counter++;
			for (int i = 0; i <InsideCount; i++)
				cout << "Inside[" << i << "]:" << Inside[i] << endl;
		}
}

void MIN(int num)
{
	int max = 0; // 表示内存中的页号，下一次出现的距离
	int maxchange; //表示内存中下次出现距离最大的页号在内存中的位置
	int k;
	if (isInside(num))
	{
		cout << "It is already in memory!" << endl;
		for (int i = 0; i <InsideCount; i++)
			cout << "Inside[" << i << "]:" << Inside[i] << endl;
	}
	else
		if (counter == InsideCount)
		{
			lost++;
			for (int j = 0; j < InsideCount; j++)
			{
				//*****************************在这里补充算法*****************************************
				
				
				
			}
			
			
			for (int i = 0; i <InsideCount; i++)
				cout << "Inside[" << i << "]:" << Inside[i] << endl;
		}
		else
		{
			Inside[counter] = Page[num];
			counter++;
			for (int i = 0; i <InsideCount; i++)
				cout << "Inside[" << i << "]:" << Inside[i] << endl;
		}
}

int main()
{
	char ch;
	while (1)
	{
		cout << "M: MIN" << "\n" << endl;
		cout << "F: FIFO" << "\n" << endl;
		cout << "L: LRU" << "\n" << endl;
		cin >> ch;
		switch (ch)
		{
		case 'M':
		{
			lost = 0;
			counter = 0;
			for (int j = 0; j < InsideCount; j++)
			{
				Inside[j] = 0;
			}
			for (int i = 0; i < PageCount; i++)
			{
				cout << "Accessing Page[" << i << "]=" << Page[i] << endl;
				MIN(i);
			}
			cout << "Accessing " << PageCount << " pages, " << "page faults " << lost << " times, page-fault rate is " << lost / (PageCount) << "\n\n" << endl;
		}
		break;
		case 'F':
		{
			lost = 0;
			counter = 0;
			for (int j = 0; j < InsideCount; j++)
			{
				Inside[j] = 0;
			}
			for (int i = 0; i < PageCount; i++)
			{
				cout << "Accessing Page[" << i << "]=" << Page[i] << endl;
				FIFO(i);
			}
			cout << "Accessing " << PageCount << " pages, " << "page faults " << lost << " times, page-fault rate is " << lost / (PageCount) << "\n\n" << endl;
		}
		break;
		case 'L':
		{
			lost = 0;
			counter = 0;
			for (int j = 0; j < InsideCount; j++)
			{
				Inside[j] = 0;
			}
			for (int i = 0; i < PageCount; i++)
			{
				cout << "Accessing Page[" << i << "]=" << Page[i] << endl;
				LRU(i);
			}
			cout << "Accessing " << PageCount << " pages, " << "page faults " << lost << " times, page-fault rate is " << lost / (PageCount) << "\n\n" << endl;
		}
		break;
		}
	}
	return 0;
}
