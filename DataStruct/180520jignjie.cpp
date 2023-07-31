#include <Stdio.h>

struct point {
	int x;int y;
};
struct rectangle{
	struct point p;
	struct point q;
};

struct rectangle input(struct rectangle a)
{
	scanf("%d",&a.p.x);
	scanf("%d",&a.p.y);
	scanf("%d",&a.q.x);
	scanf("%d",&a.q.y);
	//scanf("%d %d",&a.q.x,&a.q.y);
	return a;
}
void output(struct rectangle a)
{
	printf("\n<%d %d>  <%d %d>",a.p.x,a.p.y,a.q.x,a.q.y);
}

int main()
{
	struct rectangle r1,r2;
	input(r1);
	printf("<%d %d> <%d %d>",r1.p.x,r1.p.y,r1.q.x,r1.q.y);
	output(r1);
	return 0;
	
}
