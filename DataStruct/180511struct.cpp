#include <Stdio.h>

struct point
{
	int x;int y;
};
void getstruct (struct point);
void output(struct point);

int main()
{
	struct point y={0,0
	};
	getstruct(y);
	output(y);
}
void getstruct(struct point p)
{
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	printf("%d , %d",p.x,p.y);
}
void output(struct point p)
{
	printf("%d %d",p.x,p.y);
}

