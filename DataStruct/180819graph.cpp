#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 4

typedef struct d{
	int n,e;
	int vert[maxsize][maxsize];
}mgraph;

mgraph *build()
{
	mgraph *g=(mgraph *)malloc(sizeof(mgraph));
	g->e=0;        //meiyoubian ding yi wei 0
	g->n=4;
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			g->vert[i][j]=0;
		}
	}
	return g;
}
void print(mgraph *g)
{
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			printf("[%d]\t",g->vert[i][j]);
		}
		printf("\n");
	}
}



int main()
{
	mgraph *G=build();
	print(G);
}
