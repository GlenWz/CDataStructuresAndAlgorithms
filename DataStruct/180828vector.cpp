#include <iostream>
#include <String>
#include <vector>

using namespace std;
using std::vector;

int main()
{
	vector<int> v;
	int CIN,j,sum;
	for(int i=0;i<6;i++)
	{
		cin>>CIN;
		v.push_back(CIN);
	}
	cout<<endl;
	for(int i=0;i<6;i++)
	{
		cout<<v[i]<<endl;
	}
/*	j=v.size();
	j--;
	cout<<j<<endl;*/
	for(int i=0,j=v.size()-1;i<=j;i++,j--)
	{
		
		cout<<v[i]+v[j]<<endl;
	}
}
