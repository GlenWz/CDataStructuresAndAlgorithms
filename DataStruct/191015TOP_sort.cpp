#include <Stdio.h>
#include <Stdlib.h>
#define MAX 100

typedef struct edge{
	int vertex;
	int weight;
	struct edge *next;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	int head;
}Adjlist[MAX];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

int dist[MAX];
int parent[MAX];


graph *buildg()
{
	int queue[]={0,1,1,4,2,3,3,4,3,6,4,9,4,5,5,7,5,8,6,7,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	int v1,v2;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=10;
	g->ne=10;
	for(int i=0;i<g->nv;i++)
	{
		g->adjlist[i].firstedge=NULL;
		g->adjlist[i].head=i;
	}
	for(int i=0;i<g->ne;i++)
	{
		v1=queue[front++];
		v2=queue[front++];
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->vertex=v2;
		e2->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e2;
	}
	return g;
}
void CSHUnway(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		if(i==0)
		{
			dist[i]=0;
			parent[i]=-1;
		}else if(i==2)
		{
			dist[i]=0;
			parent[i]=-1;
		}else 
		{
			dist[i]=INT_MAX;
			parent[i]=-1;
		}
	}
}
void Unway(graph *g,int v)
{
	edgenode *e;
	int queue[MAX];
	int front=0,rear=0;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		for(e=g->adjlist[v].firstedge;e;e=e->next)
		{
			if(dist[e->vertex]==INT_MAX||dist[e->vertex]>dist[v]+1)
			{
				dist[e->vertex]=dist[v]+1;
				parent[e->vertex]=v;
				queue[rear++]=e->vertex;
			}
		}
	}
}
void PrintWay(graph *g)
{
	printf("\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
}


void TopSort(graph *g)
{
	int indegree[MAX];
	for(int i=0;i<g->nv;i++)
	{
		indegree[i]=0;
	}
	for(int i=1;i<g->nv;i++)
	{
		for(edgenode *e=g->adjlist[i].firstedge;e;e=e->next)
		{
			indegree[e->vertex]++;
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
		printf("%d->",v);
		for(e=g->adjlist[v].firstedge;e;e=e->next)
		{
			if(--indegree[e->vertex]==0)
			{
				queue[rear++]=e->vertex;
			}
		}		
	}
}



int main()
{
	graph *g=buildg();
/*	int v=0;
	int v2=2;
	CSHUnway(g);
	Unway(g,v);
	Unway(g,v2);
	PrintWay(g);*/
	TopSort(g);
}









