#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 6

typedef struct d{
	int number;
	char info;
}vertextype;

typedef struct {
	int edges[maxsize][maxsize];
	int n,e;
	vertextype vex[maxsize];
}mgraph;

mgraph *build()
{
	mgraph *g=(mgraph *)malloc(sizeof(mgraph));
	int x=0,y=0;
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			g->edges[i][j]=j;
		}
	}
	return g;
}
void print(mgraph *s)
{
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			printf("[%d]\t",s->edges[i][j]);
		}
		printf("\n");
	}
	
}



int main()
{
	mgraph *s=build();
	print(s);
}
