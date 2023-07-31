#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct edge{
	int Vertex;
	edge *next;
	int Weight;
}edgenode;

typedef struct vnode{
	int head;
	edgenode *firstedge;
}Adjlist[MAXSIZE];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

int visited[MAXSIZE];
int parent[MAXSIZE];
int dist[MAXSIZE];




graph *buildg()
{
	int queue[]={0,1,1,1,2,4,1,4,2,1,7,3,1,3,1,2,4,1,2,5,1,3,5,3,3,6,2,6,7,1,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	int v1,v2,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=10;
	g->nv=8;
	for(int i=0;i<MAXSIZE;i++)
	{
		g->adjlist[i].head=i;
		g->adjlist[i].firstedge=NULL;
	}
	while(front!=rear)
	{
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->Vertex=v2;
		e1->Weight=w;
		e1->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e1;
		g->ne++;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->Vertex=v1;
		e2->Weight=w;
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
		printf("H:%d->",g->adjlist[i].head);
		for(e=g->adjlist[i].firstedge;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)->",e->Vertex,e->Weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int v)
{
	printf("%d->",v);
	edgenode *e;
	visited[v]=-1;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->Vertex]!=-1)
		{
			DFS(g,e->Vertex);
		}
	}
}

void BFS(graph *g,int v)
{
	edgenode *e;
	visited[v]=1;
	printf("%d->",v);
	int queue[MAXSIZE];
	int front=0,rear=0;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		for(e=g->adjlist[v].firstedge;e;e=e->next)
		{
			if(visited[e->Vertex]!=1)
			{
				printf("%d->",e->Vertex);
				visited[e->Vertex]=1;
				queue[rear++]=e->Vertex;
			}
		}
	}
}

void CSHway(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		if(i==0)
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
	int queue[MAXSIZE];
	int front=0,rear=0;
	visited[v]=2;
	edgenode *e;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		for(e=g->adjlist[v].firstedge;e;e=e->next)
		{
			if(visited[e->Vertex]!=2)
			{
				visited[e->Vertex]=2;
				dist[e->Vertex]=dist[v]+1;
				parent[e->Vertex]=v;
				queue[rear++]=e->Vertex;
			}
		}
	}
}
int FindMindj(graph *g)
{
	int Min=INT_MAX,ret=-1;
	for(int i=0;i<g->nv;i++)
	{
		if(dist[i]<Min&&visited[i]!=3)
		{
			Min=dist[i];
			ret=i;
		}
	}
	return ret;
}
void PrintWay(graph *g)
{
	printf("\nDIST:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nParent:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",parent[i]);
	}
}
void CSHDJ(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		if(i==0)
		{
			dist[i]=0;
			parent[i]=-1;
		}else if(i==1)
		{
			dist[i]=1;
			parent[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			parent[i]=-1;
		}
	}
}


void Dijkstra(graph *g,int v)
{
	edgenode *e;
	while(1)
	{
		v=FindMindj(g);
		if(v==-1)
		{
			break;
		}
		visited[v]=3;
		for(e=g->adjlist[v].firstedge;e;e=e->next)
		{
			if(visited[e->Vertex]!=3)
			{
				if(dist[e->Vertex]>dist[v]+e->Weight)
				{
					dist[e->Vertex]=dist[v]+e->Weight;
					parent[e->Vertex]=v;
				}
			}
		}
	}
}
void CSHprim(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		if(i==0)
		{
			dist[i]=0;
			parent[i]=-1;
		}else if(i==1)
		{
			dist[i]=1;
			parent[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			parent[i]=-1;
		}
	}	
}
int FindMinp(graph *g)
{
	int Min=INT_MAX,ret=-1;
	for(int i=0;i<g->nv;i++)
	{
		if(visited[i]!=4&&dist[i]<Min)
		{
			Min=dist[i];
			ret=i;
		}
	}
	return ret;
}


void Prim(graph *g,int v)
{
	edgenode *e;
	while(1)
	{
		v=FindMinp(g);
		if(v==-1)
		{
			break;
		}
		visited[v]=4;
		for(e=g->adjlist[v].firstedge;e;e=e->next)
		{
			if(visited[e->Vertex]!=4)
			{
				if(dist[e->Vertex]>e->Weight)
				{
					dist[e->Vertex]=e->Weight;
					parent[e->Vertex]=v;
				}
			}
		}
	}
}


int main()
{
	graph *g=buildg();
	PrintG(g);
	int v=0;
	printf("BFS:\n");
	DFS(g,v);
	printf("\nDFS:\n");
	BFS(g,v);
	printf("\nUNWAY:\n");
	CSHway(g);
	Unway(g,v);
	PrintWay(g);
	printf("\nDijkstra:\n");
	CSHDJ(g);
	Dijkstra(g,v);
	PrintWay(g);
	printf("\nPrim:\n");
	CSHprim(g);
	Prim(g,v);
	PrintWay(g);
	
	
}






