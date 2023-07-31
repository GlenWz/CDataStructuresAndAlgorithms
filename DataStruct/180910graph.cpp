#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define maxsize 100
typedef int vertex;
typedef struct edge{
	vertex adjvex;
	struct edge *next;
	int weight;
}edgenode;
typedef struct vnode{
	vertex head;
	edgenode *firstedge;
}Adjlist[maxsize];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;



graph *buildg()
{
	vertex v,w;
	int v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=10;
	g->ne=11;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].head=v;
		g->adjlist[v].firstedge=NULL;
	}
	for(w=0;w<g->ne;w++)
	{
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		printf("please input the v1 and v2 v3:\n");
		scanf("%d%d%d",&v1,&v2,&v);
		e->adjvex=v2;
		e->weight=v3;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
	}
	return g;
}
void printg(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		e=g->adjlist[i].firstedge;
		for(;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)->",e->adjvex,e->weight);	
		}
		printf("\n");	
	}
}
int main()
{
	graph *g=buildg();
	printg(g);
}
