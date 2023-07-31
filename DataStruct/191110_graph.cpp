#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct edge{
	int edgename;
	edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	int head;
	edgenode *firstedge;
}Adjlist[MAX_SIZE];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

graph *buildg()
{
	int queue[]={0,7,1,1,2,2,2,6,1,2,3,1,2,7,2,3,5,3,3,4,2,4,5,1,4,7,3,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	int v1,v2,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=0;
	g->nv=8;
	for(int i=0;i<g->nv;i++)
	{
		g->adjlist[i].firstedge=NULL;
		g->adjlist[i].head=i;
	}
	while(front!=rear)
	{
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->edgename=v2;
		e1->weight=w;
		e1->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e1;
		
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->edgename=v1;
		e2->weight=w;
		e2->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e2;
		g->ne++;
	}
	return g;
	
}
void PrintG(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("Head(%d)->",g->adjlist[i].head);
		for(e=g->adjlist[i].firstedge;e;e=e->next)
		{
			printf("E:%d(W:%d)->",e->edgename,e->weight);
		}
		printf("\n");
	}
}




int main()
{
	graph *g=buildg();
	PrintG(g);
}










