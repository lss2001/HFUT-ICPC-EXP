# include <vector>
# include <algorithm>
# include <iostream>

using namespace std;
vector<int> vector2;

void print()
{
	vector<int>::iterator it;
    for (it = vector2.begin(); it != vector2.end(); it++)
	{
        cout << (*it) << ' ';
    }
    cout << "\n";  
} 
    
void vectorTest2()
{
	int max, min;

	vector<int>::iterator it;
    cout << "生成10个随机数存入vector：" << endl;

    for (int i = 0; i < 10; i++){
        vector2.push_back(rand());
    }

	print();

    cout << "\n泛型算法sort升序排序：" << endl;

    sort(vector2.begin(), vector2.end());
    
	print();

    cout << "\n泛型算法sort降序排序：" << endl;

    sort(vector2.begin(), vector2.end(), greater<int>());

	print();

    cout << "\n泛型算法find查找某个随机数：" << endl;

    int x = rand();
    it = find(vector2.begin(), vector2.end(), x);

    if (*it == x)
	{  
        cout << *it << endl;
    }
    else
	{   
        vector2.push_back(x);
    }

	print();
	
    cout << "\n找出容器中的最小元素和最大元素：" << endl;

    max = *max_element(vector2.begin(), vector2.end());

    cout << "\n最大元素：" << max << endl;

    min = *min_element(vector2.begin(), vector2.end());

    cout << "\n最小元素：" << min << endl;
}

int main(){
    vectorTest2();
    return 0;
}
