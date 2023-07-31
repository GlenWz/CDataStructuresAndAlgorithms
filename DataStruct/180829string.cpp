#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
using std::vector;

int main()
{
	vector<string> v;
	string str="stingkj";
	for(auto it=str.begin();it!=str.end();++it)
	{
		*it=toupper(*it);
		cout<<*it<<endl;
	}
}
