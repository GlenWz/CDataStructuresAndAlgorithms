#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;
using std::vector;

int main()
{
	vector <int>v1;
	for(int i=0;i<10;i++)
	{
		v1.push_back(i);
	}
	vector<int>::iterator it;
	for(it=v1.begin();it!=v1.end();++it)
	{
		if(*it%2==1)
		{
			cout<<*it<<endl;
		}
	}
}
