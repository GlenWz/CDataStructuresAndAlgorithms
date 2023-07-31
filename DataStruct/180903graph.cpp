#include <Stdio.h>
#include <stdlib.h>
#define maxsize 6
#define laozishiweight 8
typedef int vertex;
typedef struct d{
	vertex visited[maxsize]={};
	int G[maxsize][maxsize];
	int nv,ne;
}graph;
typedef struct edgenode{
	int weight;
	vertex v1,v2;
}edgenode;

graph *build()
{
	graph *g=(graph *)malloc(sizeof(graph));
	edgenode *e;
	g->ne=0;
	g->nv=0;
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			if(i==2&&j!=2||j==2&i!=2)
			{
				e=(edgenode *)malloc(sizeof(edgenode));
				e->weight=laozishiweight;
				e->v1=i;
				e->v2=j;
				g->G[e->v1][e->v2]=e->weight;
				g->ne++;
				g->nv++;
				g->visited[i]=1;
				
			}else 
			{
				g->G[i][j]=0;
			}
		}
	}
	return g;
}

void print(graph *g)
{
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			printf("%d  ",g->G[i][j]);
		}
		printf("\n");
	}
}

void DFS_G(graph *g,int v)
{
	int i;
	for(i=0;i<g->nv;++i)
	{
		if(g->visited[i]!=0)
		{
			DFS_G(g,i);
		}
		printf("%d",v);
	}
}


int main()
{
	graph *g=build();
	print(g);
	DFS_G(g,0);
} 
