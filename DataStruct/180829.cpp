#include <iostream>

using namespace std;
int main()
{
	int a[10]={1};
	int b[10]={1};
	int ret=0;
	int *p=&a[0];
	int *q=&b[0];
	int *e=&a[11];
	for(;q!=e;++q,++p)
	{
		ret=q-p;
		cout<<ret<<endl;
		if(ret!=0)
		{
			cout<<"buxiangdeng"<<endl;
			return 0;
		}
	}
	cout<<"xaingdeng"<<endl;
}
