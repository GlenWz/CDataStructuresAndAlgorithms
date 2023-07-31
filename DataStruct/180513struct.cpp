#include <Stdio.h>

struct point {
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
