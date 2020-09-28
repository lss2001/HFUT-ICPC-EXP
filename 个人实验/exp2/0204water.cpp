//倒水问题 
#include<iostream>
#include<queue>
using namespace std;

struct node//状态节点，储存A、B水量和操作 
{
	int a;
	int b;
	int step;
};

int a,b,c;

int vis[200][200];
node path[200][200];

void judge_step(int a,int b);

int bfs()
{
	queue<node>q;//使用队列实现的BFS 
	node now, next;
	
	now.a = 0;
	now.b = 0;
	now.step = 0;
	
	q.push(now);//入队 
	
	while(q.size())
	{
		now = q.front();
		q.pop();
		
		if(now.a == c || now.b == c)//说明找到了方案 
		{
			cout << now.step << "\n";
			judge_step(now.a,now.b);
			return 1;
		}
		
		node pre;                   //记录路径 
	 	pre.a = now.a,pre.b = now.b;
		
		if(now.a < a && !vis[a][now.b])//可以倒满A 
		{             
			next.a = a;
			next.b = now.b;
			next.step = now.step + 1;
			
			q.push(next);
			vis[next.a][next.b] = 1;
			pre.step = 1;                         
			path[next.a][next.b] = pre;
		}
		
		if(now.b < b && !vis[now.a][b])//可以倒满B 
		{               
			next.a = now.a;
			next.b = b;
			next.step = now.step + 1;
			
			q.push(next);
			vis[next.a][next.b] = 1;
			pre.step = 2;                            
			path[next.a][next.b] = pre;
		}
		
		if(now.a > 0 && !vis[0][now.b])
		{
			next.a = 0;
			next.b = now.b;
			next.step = now.step + 1;
			
			q.push(next);
			vis[next.a][next.b] = 1;
			pre.step = 3;
			path[next.a][next.b] = pre;
		}
		
		if(now.b > 0 && !vis[now.a][0])
		{
			next.a = now.a;
			next.b = 0;
			next.step = now.step + 1;
			
			q.push(next);
			vis[next.a][next.b] = 1;
			pre.step = 4;
			path[next.a][next.b] = pre;
		} 
		
		//A往B倒 
		if(now.a && now.b < b)
		{        
			pre.step = 5;     
			
			if(now.a >= b - now.b && !vis[now.a - (b - now.b)][b])//能倒满 
			{   
				next.a = now.a - (b - now.b);
				next.b = b;
				next.step = now.step + 1;
				
				q.push(next);
				vis[next.a][next.b] = 1;
				path[next.a][next.b] = pre;
			} 
			else if(!vis[0][now.b + now.a])//不能倒满 
			{                     
				next.a = 0;
				next.b = now.b + now.a;
				next.step = now.step + 1;
				
				q.push(next);
				vis[next.a][next.b] = 1;
				path[next.a][next.b] = pre;
			}
		}
		
		//B往A倒 
		if(now.b && now.a < a)
		{       
			pre.step = 6;       
			
			if(now.b >= a - now.a && !vis[a][now.b - (a - now.a)])//能倒满 
			{   
				next.a = a;
				next.b = now.b - (a - now.a);
				next.step = now.step + 1;
				
				q.push(next);
				vis[next.a][next.b] = 1;
				path[next.a][next.b] = pre;
			} 
			
			else if(!vis[now.a + now.b][0])//不能倒满 
			{                     
				next.a = now.a + now.b;
				next.b = 0;
				next.step = now.step + 1;
				
				q.push(next);
				vis[next.a][next.b] = 1;
				path[next.a][next.b] = pre;
			}
		}
	}
	return 0;
}

void judge_step(int a,int b)
{
	if(a == 0 && b == 0)
	{
		return;
	}
	
	judge_step(path[a][b].a,path[a][b].b);
	
	if(path[a][b].step == 1)//这代表了BFS的六个方向 
	{
		cout << "FILL(A)" << "\n";
	}
	if(path[a][b].step == 2)
	{
		cout << "FILL(B)" << "\n";
	}
	if(path[a][b].step == 3)
	{
		cout << "EMPTY(A)" << "\n";
	}
	if(path[a][b].step == 4)
	{
		cout << "EMPTY(B)" << "\n";
	}
	if(path[a][b].step == 5)
	{
		cout << "POUR(A, B)" << endl;
	}
	if(path[a][b].step == 6)
	{
		cout << "POUR(B, A)"<< "\n";
	}
}

int main()
{
	cout << "请输入A、B杯容量和目标水量："; 
	cin >> a >> b >> c;
	cout << "\n";

	if(!bfs()) 
		cout << "impossible" << "\n";
		
	return 0;
}

/*
3 5 4
2 8 5
4 9 6
 
*/ 

