#include <Stdio.h>

struct point
{
	int x;int y;
};

struct point getstruct(void);
void output(struct point);

int main()
{
	struct point y={0,0};
	y =getstruct();
	output(y);
}
void getstruct(void)
{
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	printf("get=%d,%d\n",p.x,p.y);
}
void output(struct point p)
{
	printf("out=%d %d \n",p.x,p.y);
}
