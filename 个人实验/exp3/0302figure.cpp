#include <iostream> 
#include <utility> 
#include <vector> 
#include <algorithm> 
#include<bits/stdc++.h>

using namespace std;

const int maxn = 1010;
int n;
double esp = 1e-8;

template<class Ty1, class Ty2> //减号重载，变成求向量AB 
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2)
{
    pair<Ty1, Ty2> ret;
    ret.first = p1.first - p2.first;
    ret.second = p1.second - p2.second;
    return ret;
}

typedef pair<double, double> POINT;
 
POINT p[maxn];

int sgn(double x)//判定符号 
{
    if (fabs(x) < esp) 
	{
        return 0;
    }
    else {
        return x > 0 ? 1 :- 1;
    }
}

double CP(POINT A, POINT B) //叉积（这里指的其实是向量。
							   //这个问题中点和向量形式是一样的，用的时候要注意） 
{
    return A.first * B.second - A.second * B.first;
}

bool intersec(POINT A1, POINT B1, POINT A2 , POINT B2)//判断两次跨立相交
{
	//判定向量A1B1,A2B2是否相交 
	double C1, C2, C3, C4;
	 
    C1 = CP(A2 - A1, B1 - A1);
	C2 = CP(B1 - A1, B2 - A1);
	 
    C3 = CP(A1 - A2, B2 - A2);
	C4 = CP(B2 - A2, B1 - A2);
    
    if (sgn(C1 * C2) >= 0 && sgn(C3 * C4) >= 0)//互相跨立 
	{
        return true;
    }
    return false;
}

bool segInter() //判定有无非法交点 
{
    //对于每一条线段
	//除了与它直接相连的两条
	//检查它是否与剩下的其他线段有交点
	 
    for (int i = 2; i < n - 1; i++) 
	{
        for (int j = 1; j < i; j++)
        {
            if (intersec(p[i], p[i + 1], p[j - 1], p[j])) 
			{
                return true;
            }
        }
    }
    
    //最后一根单独比较
	 
    for (int i = 1; i < n - 2; i++) 
	{
        if (intersec(p[n - 1], p[0], p[i], p[i + 1])) 
		{
            return true;
        }
    }
    return false;
}

double Area() 
{
    double S = 0;
    for (int i = 1; i < n - 1; i++) 
	{
        S += CP(p[i] - p[0], p[i + 1] - p[0]);
    }
    return fabs(S) * 0.5;
}

void sleep1(int k)
{
	for(int i = 0; i < k; i++)
	{
		
	}
}
int main() 
{
    int num = 0;
    int flag[400] = {0};
	double area[400] = {0};
	
    while((cin >> n) && (n != 0)) 
	{
        double a, b;
        for (int i = 0; i < n; i++) 
		{
            cin >> a >> b;
            p[i] = POINT(a, b);
        }
        if (n < 3) 
		{
			flag[num] = -1;
			num++;
            continue;
        }
        if(segInter()) 
		{
			flag[num] = -1;
			num++;
            continue;
        }
        else 
		{
			flag[num] = 1;
		    area[num] = Area();
		    num++;
        }
    }
    
    for(int i = 0 ; i < 400 ; i++)
    {
    	if(flag[i] == -1)
    		cout << "Figure " << i + 1 << ": Impossible" << "\n";
    	if(flag[i] == 1)
    	    cout << "Figure " << i + 1 << ": " << setprecision(2) << area[i] << "\n";
	}
	
    return 0;
}
/*
5 
0 0.6 
0 1 
0.5 0.5 
1 1 
1 0 
4 
0 0 
0 1 
1 0 
1 3
5 
0 0 
0 1 
0.5 0.5 
1 1 
1 0
0 
*/



