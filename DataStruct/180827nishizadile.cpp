#include <iostream>
#include <String>

using namespace std;

int main()
{
	string s="string";
	for(auto &c:s)
	{
		c=toupper(c);
	}
	cout<<s<<endl;
}
