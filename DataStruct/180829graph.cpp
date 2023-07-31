#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 10
typedef int vertex;
typedef struct d{
	vertex G[maxsize][maxsize];
	int nv,ne;
}Graph;
typedef struct edge{
	int v1,v2;
	int weight;
}edge;

Graph *build()
{
	Graph *g=(Graph *)malloc(sizeof(Graph));
	vertex v,w;
	g->ne=0;
	g->nv=0;
	for(v=0;v<maxsize;v++)
	{
		for(w=0;w<maxsize;w++)
		{
			if(v==5&&v!=w||w==5&&v!=w)
			{
				g->G[v][w]=1;
				g->nv++;
			}else 
			{
				g->G[v][w]=0;
			}
		}
	}
	return g;
}
void insertedge(edge *e,Graph *g)
{
	g->G[e->v1][e->v2]=e->weight;
	g->G[e->v2][e->v1]=e->weight;
	g->ne++;
}
void printg(Graph *s)
{
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			printf("%d  ",s->G[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	Graph *G=build();
	edge *e1=(edge *)malloc(sizeof(edge));
	e1->v1=5;e1->v2=8;e1->weight=8;
	insertedge(e1,G);
	printg(G);
	return 0;
}
