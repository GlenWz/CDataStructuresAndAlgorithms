#include <Stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct edge{
	int data;
	int weight;
	struct edge *next;
}edgenode;

typedef struct vnode{
	int head;
	edgenode *firstedge;
}Adjlist[MAX];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

graph *buildg()
{
	int queue[]={0,1,2,3,1,4,3,4,3,6,4,5,4,9,5,8,5,7,6,7,};
	int v1,v2,w;
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=10;
	g->nv=10;
	for(int i=0;i<g->nv;i++)
	{
		g->adjlist[i].firstedge=NULL;
		g->adjlist[i].head=i;
	}
	for(int i=0;i<g->ne;i++)
	{
		v1=queue[front++];
		v2=queue[front++];
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		e->data=v2;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
	}
	return g;
}
void TOP_SORT(graph *g)
{
	int indegree[g->nv];
	int queue[MAX];
	int front=0,rear=0,v=0;
	for(int i=0;i<g->nv;i++)
	{
		indegree[i]=0;	
	}	
	for(int i=0;i<g->nv;i++)
	{
		for(edgenode *e=g->adjlist[i].firstedge;e;e=e->next)
		{
			if(indegree[e->data]==0||indegree[e->data]<indegree[g->adjlist[i].head]+1)
			{
				indegree[e->data]++;
			}
		}
	}
	for(int i=0;i<g->nv;i++)
	{
		if(indegree[i]==0)
		{
			queue[rear++]=i;
		}
	}
	for(;front!=rear;)
	{
		v=queue[front++];
		printf("%d->",g->adjlist[v].head);
		for(edgenode *e=g->adjlist[v].firstedge;e;e=e->next)
		{
			if(--indegree[e->data]==0)
			{
				queue[rear++]=e->data;
			}
		}
	}
}
void Printg(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		for(edgenode *e=g->adjlist[i].firstedge;e;e=e->next)
		{
			printf("E:%d->",e->data);
		}
		printf("\n");
	}
}


int main()
{
	graph *g=buildg();
	Printg(g);
	TOP_SORT(g);
}







