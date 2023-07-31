#include <stdio.h>

struct point{
	int x;int y;
};

void getstruct(struct point p)
{
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	printf("%d %d",p.x,p.y);
	
}

void output(struct point p)
{
	printf("\n %d %d",p.x,p.y);
}

int main()
{
	struct point p={1,2
	};
	getstruct(p);
	output(p);
	return 0;
}
