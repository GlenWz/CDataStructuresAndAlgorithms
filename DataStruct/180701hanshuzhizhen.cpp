#include <Stdio.h>

void f(int i)
{
	printf("in f\n");
}
void g(int i)
{
	printf("in g\n");
}

void h(int i)
{
	printf("in h\n");
}

int main()
{
	int i;
	void(*fa[])(int)={f,g,h};
	scanf("%d",&i);
	if(i>=0&&i<sizeof(fa)/sizeof(fa[0]))
	{
		(*fa[i])(i);
	}
		return 0;	
}
