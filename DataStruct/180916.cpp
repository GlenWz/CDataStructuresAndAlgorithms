#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class automobile{
	private:
		char name[20];
		char color[20];
		int num;
		int carry_weight;
		int carry_customer;
	public:
		automobile()
		{
			strcpy(name,"bmw");
			strcpy(color,"black");
			num=5000;
			carry_weight=1000;
			carry_customer=2000;
		}
		void moveline(int i,int l);
		void play_mp3(char *ps);
		void movedown(int num);
		void horming(int num);
};
void automobile::moveline(int l,int k)
{
	cout<<" "<<name<<"直线运动："<<endl;
	for(int i=0;i<l;i++)
	{
		cout<<" "<<"(*_-)!";
		cout<<"\b\b\b\b\b\b";
		Sleep(1000/k);	
	} 
}
void automobile::horming(int num)
{
	for(int i=0;i<num;i++)
	{
		cout<<'\007'<<endl;
		cout<<"di...di..di."<<endl;
		Sleep(1000);
	}
	
}
void automobile::play_mp3(char *ps)
{
	char str[100]="play ";
	strcat(str,ps);
	cout<<str;
	mciSendString(str,NULL,0,NULL);
	char a;
	cin>>a;
}

int main()
{
	automobile c1;
	char ps[]="D:\\TOOL\\网易云音乐\\新建文件夹\\LOSER.mp3";
	while(1)
	{
		c1.horming(3);
		c1.moveline(10,3);
		c1.play_mp3(ps);
	}
}
