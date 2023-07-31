#include <stdio.h>
#include <stdlib.h>

#define maxsize 10

typedef int vertex;

typedef struct {
	int v1,v2;
	int weight;
}edge;

typedef struct d{
	int G[maxsize][maxsize];
	int nv;
	int ne;
}graph;

graph *creat()
{
	graph *s=(graph *)malloc(sizeof(graph));
	vertex v,w;
	s->ne=0;
	s->nv=0;
	for(v=0;v<maxsize;v++)
	{
		for(w=0;w<maxsize;w++)
		{
			if(v==2&&w!=2||w==2&&v!=2)
			{
				s->G[v][w]=1;
				++s->nv;
			}else 
			{
				s->G[v][w]=0;
			}
		}
	}
	return s;
}
void insertedge(graph *g,edge *e)
{
	g->G[e->v1][e->v2]=e->weight;
	g->G[e->v2][e->v1]=e->weight;
	g->ne++;
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


int main()
{
	graph *s=creat();
	edge *e1=(edge *)malloc(sizeof(edge));
	e1->v1=3;e1->v2=6;
	e1->weight=8;
	insertedge(s,e1);
	print(s);
	return 0;
	
}
