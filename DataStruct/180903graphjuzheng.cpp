#include <stdio.h>
#include <Stdlib.h>
#define maxsize 8
#define laozishiweight 8
int visit[maxsize];
typedef int vertex;
typedef struct Graph{
	vertex name[maxsize];
	int G[maxsize][maxsize];
	int ne,nv;
}graph;
typedef struct edge{
	vertex v1,v2;
	int weight;
}edgenode;

graph *build()
{
	vertex v,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=0;
	g->nv=0;
	for(v=0;v<maxsize;v++)
	{
		for(w=0;w<maxsize;w++)
		{
			g->name[w]=v;
			if(v==2&&w!=2||w==2&&v!=2)
			{
				edgenode *e=(edgenode *)malloc(sizeof(edgenode));
				e->v1=v;
				e->v2=w;
				e->weight=laozishiweight;
				g->G[e->v1][e->v2]=e->weight;
				++g->ne;
				edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
				e2->v1=w;
				e2->v2=v;
				e2->weight=laozishiweight;
				g->G[e2->v1][e2->v2]=e2->weight;
				++g->nv;
			}else 
			{
				g->G[v][w]=0;
			}
		}
	}
	return g;
}
void print(graph *g)
{
	int i,j;
	for(i=0;i<maxsize;i++)
	{
		for(j=0;j<maxsize;j++)
		{
			printf("%d  ",g->G[i][j]);
		}
		printf("\n");
	}
}
void DFS(graph *g,int i)
{
	int j;
	printf("%d->",g->name[i]);
	visit[i]=1;
	for(j=0;j<g->nv;j++)
	{
		if(g->G[i][j]!=0&&!visit[j])
		{
			DFS(g,j);
		}
	}
}


void DFSTraversal(graph *g)
{
	int i;
	for(i=0;i<g->nv;i++)
	{
		visit[i]=0;
	}
	for(i=0;i<g->nv;i++)
	{
		if(!visit[i])
		{
			DFS(g,i);
		}
	}
}


int main()
{
	graph *g=build();
	print(g);
	DFSTraversal(g);
}
