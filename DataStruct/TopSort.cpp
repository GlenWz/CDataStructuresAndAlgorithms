#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

int indegree[MAXSIZE];

typedef struct edge{
	int head;
	struct edge *next;
}edgenode;

typedef struct vnode{
	int Adjvet;
	edgenode *firstedge;
}Adjlist[MAXSIZE];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

graph *buildG()
{
	int queue[MAXSIZE]={1,3,2,3,2,13,8,9,4,5,3,7,9,10,9,11,5,6,7,10,7,11,6,15,10,14,7,12};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	int v1,v2;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=16;
	for(int i=0;i<g->nv;i++)
	{
		g->adjlist[i].Adjvet=i;
		g->adjlist[i].firstedge=NULL;
	}
	while(front!=rear)
	{
		v1=queue[front++];
		v2=queue[front++];
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		e->head=v2;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
	}
	return g;
}
void PrintG(graph *g)
{
	edgenode *e;
	for(int i=1;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].Adjvet);
		for(e=g->adjlist[i].firstedge;e!=NULL;e=e->next)
		{
			printf("E:%d->",e->head);
		}
		printf("\n");
	}
}

void PrintW(graph *g)
{
	for(int i=1;i<g->nv;i++)
	{
		printf("%d\t",indegree[i]);
	}
}
void TopSort(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		indegree[i]=0;
	}
	for(int i=1;i<g->nv;i++)
	{
		for(edgenode *w=g->adjlist[i].firstedge;w;w=w->next)
		{
			indegree[w->head]++;
		}
	}
	int v;
	edgenode *e;
	int queue[MAXSIZE];
	int front=0,rear=0;
	for(int i=1;i<g->nv;i++)
	{
		if(indegree[i]==0)
		{
			queue[rear++]=i;
		}
	}
	while(front!=rear)
	{
		v=queue[front++];
		printf("%d->",g->adjlist[v].Adjvet);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(--indegree[e->head]==0)
			{
				queue[rear++]=e->head;
			}	
		}	
	}
}


int main()
{
	graph *g=buildG();
	PrintG(g);
	PrintW(g);
	TopSort(g);
	
	
}















