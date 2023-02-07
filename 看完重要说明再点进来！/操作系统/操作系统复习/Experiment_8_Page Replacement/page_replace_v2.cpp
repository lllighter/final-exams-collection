#include<stdio.h>
#include<string.h>

// 内存块数
const int FrameCount = 3;
// 页数
const int PageCount = 20;
// 页面的最大值 + 1
const int PageMax = 8;
// 一个比较大的值
const int INF = 0x3f3f3f3f;
// 是否在内存块内
bool isInframe[PageMax];
// 计算缺页次数
int lost;
// 内存块占用情况
int Frame[FrameCount];

int Page[] = { 1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6 };

// 以下为输出相关
int temp[FrameCount][PageCount + 10];
void Output(int type) {
	if (type == 1)printf("The result of FIFO:\n");
	else if (type == 2)printf("The result of OPT:\n");
	else printf("The result of LRU:\n");
	char s[FrameCount][(PageCount + 10) * 2];
	char p[(PageCount + 10) * 2];
	for (int i = 0; i < PageCount; ++i) 
	{
		for (int j = 0; j < FrameCount; ++j)
		{
			if (i == 0) {
				if (temp[j][i] == 0)s[j][i * 2] = ' ';
				else s[j][i * 2] = temp[j][i] + '0';
				s[j][i * 2 + 1] = '|';
			}
			else {
				if (temp[j][i] == 0 || temp[j][i] == temp[j][i - 1])s[j][i * 2] = ' ';
				else s[j][i * 2] = temp[j][i] + '0';
				s[j][i * 2 + 1] = '|';
			}
		}
		p[i * 2] = Page[i] + '0';
		p[i * 2 + 1] = '|';
	}
	p[PageCount * 2] = '\0';
	for (int i = 0; i < FrameCount; ++i)s[i][PageCount * 2] = '\0';
	printf("P: %s\n", p);
	for (int i = 0; i < FrameCount; ++i) {
		printf("%c: %s\n", i + 'A', s[i]);
	}
	printf("Accessing %d pages, page faults %d times, page-fault rate is %.2f\n\n", PageCount, lost, lost * 1.0 / PageCount * 100);
}

//以下为算法部分
void FIFO() {
	// 初始化
	// Frame	置为0     表示所有内存块都为空
	// isInpage 置为false 表示所有页都未进入内存块
	// lost一开始为0，即缺页次数是0
	lost = 0;
	memset(Frame, 0, sizeof(Frame));
	memset(isInframe, 0, sizeof(isInframe));
	memset(temp, 0, sizeof(temp));
	// 指针, 表示FIFO的指针存到哪了
	int point = 0;
	// 主程序段
	for (int i = 0; i < PageCount; ++i) 
	{
		if (isInframe[Page[i]] == false)
		{
			//***************************在这里补充算法****************************
		}
		/****输出相关****/
		for (int j = 0; j < FrameCount; ++j) 
		{
			temp[j][i] = Frame[j];
		}
		/***************/
	}
	// 输出
	Output(1);
}
void OPT() {
	// 初始化
	// Frame	置为0     表示所有内存块都为空
	// isInpage 置为false 表示所有页都未进入内存块
	lost = 0;
	memset(Frame, 0, sizeof(Frame));
	memset(isInframe, 0, sizeof(isInframe));
	memset(temp, 0, sizeof(temp));

	// 判断内存块是否都存满了
	int isFull = 0;

	// 预处理
	// nxt[i][j] 表示 在 j 位置的页面 i 下一次出现在哪
	// pos[i]    表示 页面 i 下一次出现在哪, 如不出现, 值置成INF
	int nxt[PageMax][PageCount];
	int pos[PageMax];
	memset(pos, INF, sizeof(pos));
	for (int i = PageCount - 1; i >= 0; --i) 
	{
		for (int j = 1; j < PageMax; ++j) 
		{
			nxt[j][i] = pos[j];
		}
		pos[Page[i]] = i;
	}
	// 主程序段
	for (int i = 0; i < PageCount; ++i) 
	{
		// 未在内存块中
		if (isInframe[Page[i]] == false) 
		{
			lost++;
			// 已存满
			if (isFull == FrameCount)
			{
				// max_next 所有页面中, 下一次出现的位置最大的值为多少
				// number	所有页面中, 下一次出现的位置最大的那个页面标号
				int max_next = 0, number;
				//***************************在这里补充算法****************************
				
				
			}
			// 未存满
			else
			{
				isInframe[Page[i]] = true;
				Frame[isFull++] = Page[i];
			}
		}
		/****输出相关****/
		for (int j = 0; j < FrameCount; ++j)
		{
			temp[j][i] = Frame[j];
		}
		/***************/
	}
	// 输出
	Output(2);
}
void LRU() 
{
	// 初始化
	// Frame	置为0     表示所有内存块都为空
	// isInpage 置为false 表示所有页都未进入内存块
	lost = 0;
	memset(Frame, 0, sizeof(Frame));
	memset(isInframe, 0, sizeof(isInframe));
	memset(temp, 0, sizeof(temp));
	// 判断内存块是否都存满了
	int isFull = 0;

	// 预处理
	// pre[i][j] 表示 在 j 位置的页面 i 前一次一次出现在哪
	// pos[i]    表示 页面 i 前一次出现在哪, 如不出现, 值置成INF
	int pre[PageMax][PageCount];
	int pos[PageMax];
	memset(pos, INF, sizeof(pos));
	for (int i = 0; i < PageCount; ++i)
	{
		for (int j = 1; j < PageMax; ++j)
		{
			pre[j][i] = pos[j];
		}
		pos[Page[i]] = i;
	}
	// 主程序段
	for (int i = 0; i < PageCount; ++i)
	{
		// 未在内存块中
		if (isInframe[Page[i]] == false)
		{
			lost++;
			// 已存满
			if (isFull == FrameCount)
			{
				// min_pre 所有页面中, 前一次一次出现的位置最小的值为多少
				// number	所有页面中, 前一次一次出现的位置最小的那个页面标号
				int min_pre = INF + 1, number;
				//***************************在这里补充算法****************************
				
				
			}
			// 未存满
			else
			{
				isInframe[Page[i]] = true;
				Frame[isFull++] = Page[i];
			}
		}
		/****输出相关****/
		for (int j = 0; j < FrameCount; ++j)
		{
			temp[j][i] = Frame[j];
		}
		/***************/
	}
	// 输出
	Output(3);
}

// 主函数部分
int main() {
	int ty;
	printf("1:FIFO\n");
	printf("2:OPT\n");
	printf("3:LRU\n");
	printf("0:Quit\n");
	printf("input the type you choose:\n");
	while (scanf("%d", &ty), ty)
	{
		if(ty == 1)FIFO();
		else if(ty == 2)OPT();
		else LRU();
	}
}