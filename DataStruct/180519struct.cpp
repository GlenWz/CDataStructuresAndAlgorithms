#include <stdio.h>

struct point {
	int x;int y;
};

struct point vstruct(void)
{
	struct point p;
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	printf("%d %d\n",p.x,p.y);
	return p;
}
void output(struct point y)
{
	printf("%d %d\n",y.x,y.y);
}
int main()
{
	struct point y;
	y=vstruct();
	output(y);
	printf("%d %d",y.x,y.y);
	return 0;
}
