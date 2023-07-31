#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 100
#define wsweight 8

int visited[max]={0,};

typedef int vertex;
typedef struct edge{
	vertex adjvex;
	vertex weight;
	struct edge *next;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	vertex head;
}Adjlist[max];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

graph *buildG()
{
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=10;
	g->nv=8;
	int queue[max]={0,1,1,2,1,6,2,3,3,4,4,5,1,5,1,7,5,6,0,2,};
	int v1,v2;
	int front=0,rear=sizeof(queue)/sizeof(queue[0])-1;
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
		e1->weight=wsweight+i;
		e1->adjvex=v1;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->weight=wsweight+i;
		e2->adjvex=v2;
		e2->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e2;
		
		edgenode *e3=(edgenode *)malloc(sizeof(edgenode));
		e3->adjvex=v1;
		e3->weight=e1->weight;
		edgenode *e4=(edgenode *)malloc(sizeof(edgenode));
		e4->adjvex=v2;
		e4->weight=e2->weight;
		e4->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e4;
	}
	return g;
}
void Printg(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		e=g->adjlist[i].firstedge;
		for(;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)",e->adjvex,e->weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int v)
{
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e=g->adjlist[v].firstedge;
	for(;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=1)
		{
			DFS(g,e->adjvex);
		}
	}
}

void BFS(graph *g,int v)
{
	int queue[max];
	int front=0,rear=0;
	edgenode *e;
	printf("%d->",g->adjlist[v].head);
	visited[g->adjlist[v].head]=-1;
	queue[rear++]=g->adjlist[v].head;
	while(front!=rear)
	{
		v=queue[front++];
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]!=-1)
			{
				printf("%d->",e->adjvex);
				visited[e->adjvex]=-1;
				queue[rear++]=e->adjvex;
			}
		}
	}
}

int main()
{
	graph *g=buildG();
	Printg(g);
	int v=0;
	DFS(g,v);
	printf("\n");
	BFS(g,v);
}
















