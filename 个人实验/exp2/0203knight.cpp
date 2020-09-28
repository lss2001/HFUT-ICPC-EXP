#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
#include<vector>
#include<iostream>
#include<cstring>
#include<stack>

# define MAXROW 8
# define MAXCOL 8

using namespace std;

stack<pair<int, int> > route;//用栈存储 
bool board[MAXROW][MAXCOL];//棋盘标记 
pair<int, int>dir[9];

void initdir()
{
	dir[1] = make_pair(-2, -1);
	dir[2] = make_pair(-2, 1);
	dir[3] = make_pair(2, -1);
	dir[4] = make_pair(2, 1);
	dir[5] = make_pair(-1, -2);
	dir[6] = make_pair(-1, 2);
	dir[7] = make_pair(1, -2);
	dir[8] = make_pair(1, 2);					
}

bool inBound(int x, int y)
{
    if((0 <= x && x < MAXROW) && (0 <= y && y < MAXCOL))
        return true;
    return false;
}

bool check()//检查是否每一点都走过 
{
	for(int i = 0; i < MAXROW; i++)
	{
		for(int j = 0; j < MAXCOL; j++)
		{
			if(!board[i][j])
				return false;
		}
	}
	return true;
}


void printRoute()
{
	stack<pair<int, int> > stackR;//倒置 
	int flag = 0;
	
	while(!route.empty())//整理栈内元素顺序 
	{
		pair<int, int> p = route.top();
		stackR.push(p);
		route.pop();
	}
	
	while(!stackR.empty())//输出 
	{
		pair<int, int> p = stackR.top();
		cout << "(" << p.first << ", " << p.second << ") ";
		stackR.pop();
		if(!stackR.empty())
			cout << " -> ";
		else 
			cout << "（结束）"; 
			
		flag++;
		if(flag % MAXCOL == 0)
            cout << "\n";
	}
}

void findRoute(int x, int y)
{
	board[x][y] = true;
	route.push(make_pair(x, y));
	
	if(check())//都走完了 
	{
        printRoute();
        exit(0); //只要一条，直接结束 
	}
	
	for(int i = 1; i < 9; ++i)
	{

		pair<int, int> p1;
		p1 = make_pair(x + dir[i].first, y + dir[i].second) ;
		
		if( !board[p1.first][p1.second] && inBound(p1.first, p1.second) )
		{
			findRoute(p1.first, p1.second);
			
			board[p1.first][p1.second] = false;//如果走不通返回，会把放进去的全部弹出
										//恢复访问标志，回到上一次 
            route.pop();
		}
	}
}

int main()
{
	int x, y;
	x = 5;
	y = 5;
	cout << "起始点坐标为：(" << x << ", " << y << ")" << endl;
	
	initdir(); 
    findRoute(x, y);
	return 0;
}

