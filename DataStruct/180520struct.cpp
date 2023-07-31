#include <stdio.h>

struct point {
	int x;int y;
};

struct point vx(void)
{
	scanf("%d",&vx.x);
	scanf("%d",&vx.y);
	return vx;
}

void output(struct point x)
{
	printf("%d,%d\n",x.x,x.y);
}

int main()
{
	struct point p;
	p=vx();
	ouput(p);
	return 0;
	
}
