#include <stdio.h>

struct point{
	int x;int y;
};
struct rectangle{
	struct point p1;
	struct point p2;
};

void print(struct rectangle r)
{
	printf("<%d,%d> to <%d,%d>\n",
	r.p1.x,r.p1.y,r.p2.x,r.p2.y);
}
int main()
{
	int i;
	struct rectangle rects[]={{{1,2},{3,4}},{{5,6},{7,8}}};
	for(i=0;i<2;i++)
	{
		print(rects[i]);
	}	
	return 0;
}
//目前我能想到最好的路就是继续下去，我是高中就想当程序员的，但是我又选了文科没办法
//不能选CS专业，所以选了GIS专业 ，不过一进校大一大二玩疯了，目前大三，准备考的院校初试是C语言和数据结构，还有GIS，努力努力吧，最后二百多天也算是为了高中时的梦想。也只能这样了 
