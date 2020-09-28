#include<algorithm>
#include<vector>
#include<list>
#include<iostream>
#include<vector>

using namespace std;
 
int maze[4][6] = { {1, 1, 0, 0, 0, 0},
                   {0, 1, 1, 1, 0, 0},
                   {1, 1, 0, 1, 0, 0},
                   {0, 1, 1, 1, 0, 0} };
vector<pair<int, int> > path;
 
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};//下 右 上 左
 
void printvector(vector<pair<int, int> > path)
{
    vector<pair<int , int > >::iterator it;
    for(it = path.begin();it != path.end(); it++)
    {
        cout << "("<< it->first << "," << it->second << ")" << " -> ";
    }
    cout << "(3,3)" << endl;
}
 
void search(vector<pair<int, int> > tpath, int x, int y)
{
    if(x < 0 || y < 0 || x > 5 || y > 3)//越界返回
        return;
 
    if(x == 3 && y == 3)
    {
        path = tpath; //如果找到了出口,则记录下路径
        printvector(path);//每个路径都打印 
        return;
    }
 
    for(int ix = 0; ix < 4; ix++)//四个方向搜索
    {
        if(maze[x+dir[ix][0]][ y+dir[ix][1]] == 1)
        {
            tpath.push_back(make_pair(x, y));
            
            maze[x][y] = -1;//走过的标志 
            
            search(tpath, x+dir[ix][0], y+dir[ix][1]);
            tpath.pop_back();//删除最后一个元素
        }
    }
}
int main()
{
    vector<pair<int, int> > tpath;
    search(tpath, 0, 0);//从开始点找起
}

