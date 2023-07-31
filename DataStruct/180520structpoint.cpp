#include <stdio.h>

struct point {
	int x;int y;
};

struct point getstruct(void)
{
	struct point a;
    scanf("%d",&a.x);
    scanf("%d",&a.y);
    printf("%d %d",a.x,a.y);
    return a;
}

void output(struct point p)
{
	printf("\n%d %d",p.x,p.y);
}



int main()
{
	struct point y;
	y=getstruct();
	output(y);
}
