#include <stdio.h>

struct point {
	int x;int y;
};

struct point getstruct(void)
{
	struct point p;
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	printf("%d %d",p.x,p.y);
	return p;
}

void output(struct point p)
{
	printf("%d %d",p.x,p.y);
}

int main()
{
	struct point y={0,0
	};
	y=getstruct();
	output(y);
	return 0;
}
