#include <Stdio.h>

struct point{
	int x;int y;
};

void getstruct(struct point p)
{
	scanf("%d %d",&p.x,&p.y);
	printf("%d %d",p.x,p.y);
}

void output(struct point p)
{
	printf("%d %d",p.x,p.y);
}

int main()
{
	struct point p={0,0
	};
	getstruct(p);
	output(p);
	return 0;
	
	
	
	
}
