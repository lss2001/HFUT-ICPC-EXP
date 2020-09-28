# include <algorithm>
# include <vector>
# include <list>
# include <iostream>

using namespace std;

void vectorTest()
{
    vector<int> vec1;
    cout << "Vector*********************************************" << endl;
    cout << "生成10个随机数存入vector" << endl;

    for (int i = 0; i < 10; ++i)
	{
        vec1.push_back(rand());
    }

    vector<int>::iterator it;
    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n头部插入随机数" << endl;

    vec1.insert(vec1.begin(), rand());

    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\nfind查找某个随机数" << endl;

    int x = rand();
    it = find(vec1.begin(), vec1.end(), x);

    if (*it == x)
	{ 
        cout << *it << endl;
    }
    else
	{   
        vec1.push_back(x);
    }

    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n用sort排序" << endl;

    sort(vec1.begin(), vec1.end());

    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n删除vector尾部元素" << endl;

    vec1.pop_back();

    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n将vector清空" << endl;

    vec1.erase(vec1.begin(), vec1.end());

    for (it = vec1.begin(); it != vec1.end(); ++it)
	{
        cout << *it << ' ';
    }
    cout << "\n";
    
    cout << "Vector*********************************************" << endl;
}

void listTest()
{
    list<int> list1;
    
    cout << "\nList***********************************************" << endl;
    cout << "生成10个随机数存入list" << endl;

    for (int i = 0; i < 10; ++i){
        list1.push_back(rand());
    }

    list<int>::iterator it;
    for (it = list1.begin(); it != list1.end(); ++it){
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n头部插入随机数" << endl;

    list1.push_front(rand());

    for (it = list1.begin(); it != list1.end(); ++it){
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\nfind查找某个随机数" << endl;

    int x = rand();
    it = find(list1.begin(), list1.end(), x);

    if (*it == x)
	{ 
        cout << *it << endl;
    }
    else
	{   
        list1.push_back(x);
    }

    for (it = list1.begin(); it != list1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n用sort排序" << endl;

    list1.sort();
    
    for (it = list1.begin(); it != list1.end(); ++it)
	{
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n删除尾部元素" << endl;

    // 删除list尾部元素
    list1.pop_back();

    for (it = list1.begin(); it != list1.end(); ++it){
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\n将list清空" << endl;

    //清空
    list1.erase(list1.begin(), list1.end());

    for (it = list1.begin(); it != list1.end(); ++it){
        cout << *it << ' ';
    }
	cout << "\n";
	
    cout << "\nList***********************************************" << endl;
}

int main(int argc, char *argv[]){
    //cout << "Vector*********************************************" << endl;
    vectorTest();
    //cout << "Vector*********************************************" << endl;
    //cout << "List*********************************************" << endl;
    listTest();
    //cout << "List*********************************************" << endl;l;

    return 0;
}
