#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 9
typedef int vertex;
typedef struct d{
	int GG[maxsize][maxsize];
	int nv,ne;
}Graph;

typedef struct edge{
	int v1;
	int v2;
	int weight;
}edgenode;

Graph *build()
{
	vertex v,w;
	Graph *g=(Graph *)malloc(sizeof(Graph));
	g->ne=0;
	g->nv=0;
	for(v=0;v<maxsize;v++)
	{
		for(w=0;w<maxsize;w++)
		{
			if(v+1==w&&w!=v||w+1==v&&v!=w)
			{
				g->GG[v][w]=1;
				g->nv++;
			}else 
			{
				g->GG[v][w]=0;
			}
		}
	}
	return g;
}
void print(Graph *g)
{
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			printf("%d  ",g->GG[i][j]);
		}
		printf("\n");
	}
}

void insertedgenode(edgenode *e,Graph *g)
{
	g->GG[e->v1][e->v2]=e->weight;
	g->GG[e->v2][e->v1]=e->weight;
	g->ne++;
}






int main()
{
	Graph *G=build();
	edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
	e1->v1=5;e1->v2=8;e1->weight=88;
	insertedgenode(e1,G);
	print(G);
}
