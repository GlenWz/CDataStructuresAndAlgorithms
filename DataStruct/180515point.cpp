#include <stdio.h>

struct point {
	int x;int y;
};

void getstruct (struct point p);
void output(struct point p);
int main()
{
	struct point p={0,0
	};
	getstruct(p);
	output(p);
	return 0;
}
void getstruct(struct point p)
{
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	printf("%d %d \n",p.x,p.y);
}
void output(struct point p)
{
	printf("%d %d",p.x,p.y);
}
