#include <iostream>
#include <cstring>

using namespace std;
int mat[1000][1000];

int maxSubSeq(int a[],int n)//求一维数组最大子序列 
{
	int sum = 0;
	int b = 0;
	
	for(int i = 0;i < n;i++)
	{
		if(b < 0)
			b = a[i];
		else
			b += a[i];
		if(b > sum)
			sum = b;
	}
	return sum;
}

int main()
{
	int m,n;
	cout << "输入矩阵的行列数m, n:";
	cin >> m;
	cin >> n;
	
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}
	
	int maxSubArr = 0;
	int temp[n];
	
	for(int i = 0;i < m; i++)
	{
		for(int j = 0;j < n; j++)
		{
			temp[j] = 0;
		}
		for(int j = i; j < m; j++)
		{
			for(int k = 0; k < n; k++)
				temp[k] += mat[j][k];
				
			int sum = maxSubSeq(temp, n);
			
			if(sum > maxSubArr)
				maxSubArr = sum;
		}
	}

	cout << maxSubArr;
	system("pause");
}


/*
4 3
1 2 3
4 5 6
7 8 9
10 11 12
 
4 3
1 1 1
1 1 1
1 1 1
1 1 1
*/ 
 
