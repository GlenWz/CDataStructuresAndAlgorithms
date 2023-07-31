#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
using std::vector;

int main()
{
	vector<string> vs;
	string str,adj;
	for(int i=0;i<3;i++)
	{
		cin>>str;
		vs.push_back(str);
	}
	for(int i=0;i<3;i++)
	{
		adj=vs[i];
		for(auto &c:adj)
		{
			c=toupper(c);
		}
		cout<<adj<<endl;
	}
}
