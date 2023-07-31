#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	string s="string";
	for(auto &c:s)
	{
		c=toupper(c);
	}
	for(auto c:s)
	{
		cout<<c<<endl;
	}
}
