#include <stdio.h>
#include <Stdlib.h>
#define MAX 100

typedef struct edge{
	int adjvex;
	edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	int head;
	edgenode *firstedge;
}Adjlist[MAX];

typedef struct {
	Adjlist adjlist;
	int nv,ne;	
}graph;

graph *Buildg()
{	
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=11;
	g->nv=10;
	int v1,v2;
	int queue[]={0,2,1,3,2,4,3,4,4,5,4,6,5,7,5,8,6,9,8,9,7,9,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	for(int i=0;i<g->nv;i++)
	{
		g->adjlist[i].head=i;
		g->adjlist[i].firstedge=NULL;
	}
	for(int i=0;i<g->ne;i++)
	{
		v1=queue[front++];
		v2=queue[front++];
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->adjvex=v2;
		e1->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e1;
	}
	return g;
}

void TopSort(graph *g)
{
	int indegree[g->nv];
	for(int i=0;i<g->nv;i++)
	{
		indegree[i]=0;
	}
	for(int i=0;i<g->nv;i++)
	{
		for(edgenode *e=g->adjlist[i].firstedge;e;e=e->next)
		{
			indegree[e->adjvex]++;
		}
	}
	int v;
	edgenode *e;
	int queue[MAX];
	int front=0,rear=0;
	for(int i=0;i<g->nv;i++)
	{
		if(indegree[i]==0)
		{
			queue[rear++]=i;	
		}	
	}
	while(front!=rear)
	{
		v=queue[front++];
		printf("%d->",g->adjlist[v].head);
		for(e=g->adjlist[v].firstedge;e;e=e->next)
		{
			if(--indegree[e->adjvex]==0)
			{
				queue[rear++]=e->adjvex;
			}
		}
	}	
}



int main()
{
	graph *g=Buildg();
	int v=0;
	TopSort(g);
	
}





