#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int x[9] = {-1, -1, -1, -1, -1, -1, -1, -1, -1}, sum = 0;//x[i]的下标表示queen所在行数，i表示queen所在列数 
 
int count;

void printMethod()//图形化打印方法 
{
	cout << "\n这是第" << sum << "种方法!\n" ;
	for(int i = 1; i < 9; i++)
	{
		for(int j = 1; j < 9; j++)
		{
			if(j == x[i])
			{
				cout << "Q" << "  ";
			}
			else 
			{
				cout << "x" << "  ";
			}
			//cout << "\n";
		}
		cout << "\n";
	}
	cout << "\n" << "------------------------" << "\n";
}
 
void dfs(int num)
{
	if(num >= 8)//检查完了 
	{
		sum++;
		printMethod();
		return;
	} 
	else
	{
		for(int j = 1;j <= 8; j++)
		{
			x[num + 1] = j;//每一列都放一放看，找出成立的位置 
			
			bool flag = true;

			for(int g = num;g > 0; g--)//检查前面已经布好的i-1行
			{
				if( x[g] == x[num + 1] 
				|| (abs(x[num + 1] - x[g]) == abs(num + 1 - g)) )  //在同一列/在对角线上 
				flag = false; 
			} 
			
			if( flag )//判断是否符合条件 
				dfs(num + 1);  
		} 
	} 
} 

int main()
{
	dfs(0);
	cout << sum;
	//printMethod();
}


