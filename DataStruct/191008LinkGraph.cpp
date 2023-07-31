#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct edge{
	int Vertex;
	int Weight;
	struct edge *next;
}edgenode;

typedef struct vnode{
	int Head;
	edgenode *Firstedge;
}Adjlist[MAXSIZE];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

int visited[MAXSIZE]={0,};
int dist[MAXSIZE]={0,};
int parent[MAXSIZE]={0,};

graph *Buildg()
{
	int queue[]={0,1,1,1,2,4,1,4,2,2,4,1,2,5,1,1,3,1,1,7,3,3,5,3,3,6,2,6,7,1,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	int v1,v2,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=8;
	g->ne=10;
	for(int i=0;i<g->nv;i++)
	{
		g->adjlist[i].Head=i;
		g->adjlist[i].Firstedge=NULL;
	}
	for(int i=0;i<g->ne;i++)
	{
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->Vertex=v1;
		e1->Weight=w;
		e1->next=g->adjlist[v2].Firstedge;
		g->adjlist[v2].Firstedge=e1;
		
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->Vertex=v2;
		e2->Weight=w;
		e2->next=g->adjlist[v1].Firstedge;
		g->adjlist[v1].Firstedge=e2;
	}
	return g;
}
void PrintG(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("Head:%d->",g->adjlist[i].Head);
		for(e=g->adjlist[i].Firstedge;e;e=e->next)
		{
			printf("E:%d(W:%d)->",e->Vertex,e->Weight);
		}
		printf("\n");
	}
}

void DFS(graph *g,int v)
{
	visited[v]=1;
	printf("%d->",v);
	edgenode *e;
	for(e=g->adjlist[v].Firstedge;e;e=e->next)
	{
		if(visited[e->Vertex]!=1)
		{
			DFS(g,e->Vertex);
		}
	}
}
void BFS(graph *g,int v)
{
	edgenode *e;
	int queue[MAXSIZE];
	int front=0,rear=0;
	printf("%d->",v);
	visited[v]=2;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		for(e=g->adjlist[v].Firstedge;e;e=e->next)
		{
			if(visited[e->Vertex]!=2)
			{
				visited[e->Vertex]=2;
				printf("%d->",e->Vertex);
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
void UnWay(graph *g,int v)
{
	int queue[MAXSIZE];
	int front=0,rear=0;
	visited[v]=3;
	queue[rear++]=v;
	edgenode *e;
	while(front!=rear)
	{
		v=queue[front++];
		for(e=g->adjlist[v].Firstedge;e;e=e->next)
		{
			if(visited[e->Vertex]!=3)
			{
				dist[e->Vertex]=dist[v]+1;
				parent[e->Vertex]=v;
				visited[e->Vertex]=3;
				queue[rear++]=e->Vertex;
			}
		}
	}
}

void PrintWay(graph *g)
{
	printf("\nDist:\n");
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
int FindMinDj(graph *g)	 //这个地方优化可以利用最小堆进行，过于复杂利用顺序查找就行了 
{
	int Min=INT_MAX,ret=-1;
	for(int i=0;i<g->nv;i++)
	{
		if(Min>dist[i]&&visited[i]!=4)
		{
			Min=dist[i];
			ret=i;
		}
	}
	return ret;
}

void Dijkstra(graph *g,int v)
{
	edgenode *e;
	while(1)
	{
		v=FindMinDj(g);	
		if(v==-1)
		{
			break;
		}
		visited[v]=4;
		for(e=g->adjlist[v].Firstedge;e;e=e->next)
		{
			if(visited[e->Vertex]!=4)
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
void CSHP(graph *g)
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
int FindMinP(graph *g)
{
	int Min=INT_MAX,RET=-1;
	for(int i=0;i<g->nv;i++)
	{
		if(dist[i]<Min&&visited[i]!=5)
		{
			Min=dist[i];
			RET=i;
		}
	}
	return RET;
}



void Prim(graph *g,int v)
{
	edgenode *e;
	while(1)
	{
		v=FindMinP(g);
		if(v==-1)
		{
			break;
		}
		visited[v]=5;
		for(e=g->adjlist[v].Firstedge;e;e=e->next)
		{
			if(visited[e->Vertex]!=5&&dist[e->Vertex]>e->Weight)
			{
				dist[e->Vertex]=e->Weight;
				parent[e->Vertex]=v;
			}
		}	
	}
}

int main()
{
	graph *g=Buildg();
	PrintG(g);
	int v=0;
	printf("DFS:\n");
	DFS(g,v);
	printf("\nBFS:\n");
	BFS(g,v);
	printf("\nUnweightWay:\n");
	CSHway(g);
	UnWay(g,v);
	PrintWay(g);
	printf("\nDijkstra:\n");
	CSHDJ(g);
	Dijkstra(g,v);
	PrintWay(g);
	printf("\nPrim:\n");
	CSHP(g);
	Prim(g,v);
	PrintWay(g);
}












