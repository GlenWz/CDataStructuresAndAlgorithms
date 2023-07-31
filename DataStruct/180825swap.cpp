#include <iostream>
#include <string>

using namespace std;

void swap(int &x,int &y)
{
	int tmp=x;
	x=y;
	y=tmp;	
}

int main()
{
	int x=10,y=5;
	swap(x,y);
	cout<<x<<endl<<y<<endl;
	return 0;
}
