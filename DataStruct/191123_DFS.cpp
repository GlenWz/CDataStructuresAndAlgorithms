#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int Visited[MAXSIZE]={0};

typedef struct edge{
	int vertex;
	int weight;
	struct edge *next;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	int head;
}Adjlist[MAXSIZE];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

graph *buildg()
{
	int v1,v2,w;
	int queue[]={0,1,1,1,2,1,1,3,1,1,5,2,3,4,1,3,6,3,2,6,2,2,7,1,4,5,1,6,7,1,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=10;
	g->nv=8;
	for(int i=0;i<g->nv;i++)
	{
		g->adjlist[i].firstedge=NULL;
		g->adjlist[i].head=i;
	}
	for(int j=0;j<g->ne;j++)
	{
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->vertex=v1;
		e1->weight=w;
		
		e1->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e1;
		
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->vertex=v2;
		e2->weight=w;
		e2->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e2;
	}
	return g;
}
void Print(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("Head:%d->",g->adjlist[i].head);
		for(e=g->adjlist[i].firstedge;e;e=e->next)
		{
			printf("E:%d(w:%d)->",e->vertex,e->weight);
		}
		printf("\n");
	}
}
void BFS(graph *g,int v)
{
	edgenode *e;
	int queue[MAXSIZE];
	int front=0,rear=0;
	queue[rear++]=v;
	Visited[v]=1;
	while(front!=rear)
	{
		v=queue[front++];
		printf("%d->",v);
		for(e=g->adjlist[v].firstedge;e;e=e->next)
		{
			if(Visited[e->vertex]!=1)
			{
				queue[rear++]=e->vertex;
				Visited[e->vertex]=1;
			}
		}
	}
}


int main()
{
	graph *g=buildg();	
	Print(g);
	int v=0;
	BFS(g,v);
}
