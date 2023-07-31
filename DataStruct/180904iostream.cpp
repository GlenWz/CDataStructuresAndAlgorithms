#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
using std::vector;

int main()
{
	vector<string> v;
	string s;
	for(int i=0;i<3;i++)
	{
		cin>>s;
		v.push_back(s);
	}
	for(auto c:v)
	{
		cout<<c<<endl;
	}
	for(auto a:v)
	{
		s=a;
		for(auto &a:s)
		{
			a=toupper(a);
			cout<<a;
		}
		cout<<endl;
	}
}
