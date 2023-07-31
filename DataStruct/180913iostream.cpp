#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;
using std::vector;

int main()
{
	vector<string> v;
	string s,s1;
	vector<string>:: iterator it;
	it=v.begin();
	while(1)
	{
		cin>>s;
		for(auto c:v)
		{
			v.push_back(s);
			*it=s;
		}
	}
}
