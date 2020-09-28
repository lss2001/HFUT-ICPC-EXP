#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
#include <vector> 
#include <cmath> 
#include <iomanip>
#define eps 1e-8
#define INF 1e40
#define N 100

using namespace std;

struct Point //点或者向量还是混用的 
{
    double x, y;
    Point() {};
    Point(double x, double y) : x(x), y(y) {};
    //运算符重载 
    
    Point operator - (const Point & e) const 
	{
        return Point(x - e.x, y - e.y);
    }
    double operator ^ (const Point & e) const //叉乘
    {
        return x * e.y - y * e.x;
    }
    double operator * (const Point & e) const 
	{
        return x * e.x + y * e.y;
    }
};

struct Line     //直线
{
    Point a, b;
    Line() {};
    Line(Point a, Point b) : a(a), b(b) {}
};

int n, cntEdge, cntPoint;
double path[N][N];
Line line[N];
Point p[N];

double dis(Point a, Point b)//ab的距离 
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int sgn(double x)//符号函数sgn 
{
    if (fabs(x) < eps) 
	{
        return 0;
    }
    else {
        return x < 0 ? - 1 : 1;
    }
}

bool onSeg(Point P, Point A1, Point A2)//p是否在线段a1a2上 
{
    if (sgn((A1 - P) ^ (A2 - P)) == 0 && sgn((A1 - P) * (A2 - P)) < 0) 
	{
        return 1;
    }
    else {
        return 0;
    }
}

bool ifInter(Line L1, Line L2)//判断线段是否相交 
{
    double c1 = (L1.b - L1.a) ^ (L2.a - L1.a);
    double c2 = (L1.b - L1.a) ^ (L2.b - L1.a);
    double c3 = (L2.b - L2.a) ^ (L1.a - L2.a);
    double c4 = (L2.b - L2.a) ^ (L1.b - L2.a);
    return sgn(c1) * sgn(c2) < 0 && sgn(c3) * sgn(c4) < 0;
}

void getEdges()//连接任意两点，没有相交的情况就加入图
{
    for (int i = 1; i <= cntPoint; i++) 
	{
        for (int j = 1; j <= cntPoint; j++) 
		{
            if (i == j) 
			{
                path[i][j] = path[j][i] = 0;
            }
            else 
			{
                path[i][j] = path[j][i] = INF;
            }
        }
    }
    
    bool flag;
    int to, from;
    
    for (int i = 1; i <= cntPoint - 2; i++) 
	{
        for (int j = i + 1; j <= cntPoint - 2; j++) 
		{
            from = (i + 3)  / 4, to = (j + 3)  / 4;
            if (from == to) 
			{
                continue;
            }
            //同一列 跳过 
            flag = true;
            
            for (int k = 3 * from - 2; k <= 3 * to && flag; k++) 
			{
                if (ifInter(Line(p[i], p[j]), line[k]))
			    {
                    flag = false;
                }
                //如果与任意一条线段相交
            }
            
            if (flag) 
			{
                path[j][i] = path[i][j] = dis(p[i], p[j]);
            }
        }
    }
    
    for (int i = 1; i <= cntPoint - 2; i++) 
	{
        //与中间的点连边
        {
            flag = true;
            to = (i + 3)  / 4 - 1;
            
            for (int j = 1; j <= 3 * to && flag; j++) 
			{
                if (ifInter(Line(p[i], p[cntPoint - 1]), line[j])) 
				{
                    flag = false;
                }
            }
            
            if (flag) 
			{
                path[cntPoint - 1][i] = dis(p[i], p[cntPoint - 1]);
                path[i][cntPoint - 1] = dis(p[i], p[cntPoint - 1]); 
            }
            
            to = (i + 3)  / 4 + 1;
            flag = true;
            
            for (int j = 3 * to - 2; j <= cntEdge && flag; j++) 
			{
                if (ifInter(Line(p[i], p[cntPoint]), line[j])) 
				{
                    flag = false;
                }
            }
            
            if (flag) 
			{
                path[cntPoint][i] = dis(p[i], p[cntPoint]);
                path[i][cntPoint] = dis(p[i], p[cntPoint]);
            }
        }
        flag = true;
    }
    
    for (int i = 1; i <= cntEdge; i++) 
	{
        if (ifInter(Line(p[cntPoint], p[cntPoint - 1]), line[i])) 
		{
            flag = false;
        }
    }
    
    if (flag) 
	{
        path[cntPoint][cntPoint - 1] = dis(p[cntPoint - 1], p[cntPoint]);
        path[cntPoint - 1][cntPoint] = dis(p[cntPoint - 1], p[cntPoint]);
    }
    
}
void Floyd()//求最短路 
{
    for (int i = 1; i <= cntPoint; i++) 
	{
        for (int j = 1; j <= cntPoint; j++) 
		{
            for (int k = 1; k <= cntPoint; k++) 
			{
                if (path[i][k] < INF && path[k][j] < INF && path[i][k] + path[k][j] < path[i][j]) 
				{
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
}

int main() 
{
    while ( cin >> n && n != - 1) 
	{
        cntEdge = 0;
		cntPoint = 0;
        
        for (int i = 0; i < n; i++) 
		{
            double x, y1, y2, y3, y4;
            cin >> x >> y1 >> y2 >> y3 >> y4;
            
            line[++cntEdge] = Line(Point(x, 0), p[++cntPoint] = Point(x, y1));
            
            line[++cntEdge] = Line(p[++cntPoint] = Point(x, y2), p[++cntPoint] = Point(x, y3));
            
            line[++cntEdge] = Line(p[++cntPoint] = Point(x, y4), Point(x, 10));
        }
        
        p[++cntPoint] = Point(0, 5);
        p[++cntPoint] = Point(10, 5);
        
        getEdges();
        Floyd();
        cout << path[cntPoint - 1][cntPoint];
    }
    return 0;
}

/*
1
5 4 6 7 8
2
4 2 7 8 9
7 3 4.5 6 7
-1

10
10.06
*/
