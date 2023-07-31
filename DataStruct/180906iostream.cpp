#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;
using std::vector;
int main()
{
	vector<int> v2(3,1);
	vector<int> v1(4,0);
	v1.insert(v1.begin(),888);
	v2.insert(v2.end(),999);
	for(auto c:v1)
	{
		cout<<c<<"->";
	}
	cout<<endl;
	for(auto c:v2)
	{
		cout<<c<<"->";
	}
	cout<<endl;
//	vector<int>::iterator it=v1.begin()+8;   //开始的第八个位置插入，报错 
	vector<int>::iterator it=v2.begin()+4;   //下标为4 
	v2.insert(it,555);
	for(auto c:v2)
	{
		cout<<c<<"->";
	}
	vector<int>::iterator iy=v2.begin()+4;
	for(iy;iy!=v2.begin()+2;iy--)
	{
		v2.erase(iy);
	}
	cout<<endl;
	for(auto c:v2)
	{
		cout<<c<<"->";
	}
	cout<<endl;
	
}
