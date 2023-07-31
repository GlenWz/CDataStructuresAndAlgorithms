#include <Stdio.h>
#include <Stdlib.h>
#define max 100

int visited[max]={0,};
int dist[max]={0};
int path[max]={0};
int collect[max]={0,};
int parent[max]={0,};
typedef int vertex;
typedef struct edge{
	vertex adjvex;
	struct edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	vertex head;
}Adjlist[max];

typedef struct {
	Adjlist adjlist;
	vertex nv,ne;
}graph;

graph *buildg()
{
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=10;
	g->nv=6;
	int queue[max]={1,2,6,1,3,1,1,4,5,2,3,5,2,5,3,3,4,5,3,5,6,3,6,4,4,6,2,5,6,6,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0])-1;
	int v1,v2,w;
	for(int i=1;i<=g->nv;i++)
	{
		g->adjlist[i].head=i;
		g->adjlist[i].firstedge=NULL;
	}
	for(int i=1;i<g->ne;i++)
	{
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->adjvex=v1;
		e1->weight=w;
		e1->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e1;
		
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->adjvex=v2;
		e2->weight=w;
		e2->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e2;
	}
	return g;
}
void PrintG(graph *g)
{
	edgenode *e;
	for(int i=1;i<g->nv;i++)
	{
		printf("Head:%d->",g->adjlist[i].head);
		for(e=g->adjlist[i].firstedge;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)->",e->adjvex,e->weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int v)
{
	edgenode *e;
	visited[v]=1;
	printf("%d->",v);
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=1)
		{
			DFS(g,e->adjvex);
		}
	}
}
void BFS(graph *g,int v)
{
	edgenode *e;
	visited[v]=8;
	printf("%d->",v);
	int queue[max];
	int front=0,rear=0;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]!=8)
			{
				visited[e->adjvex]=8;
				printf("%d->",e->adjvex);
				queue[rear++]=e->adjvex;
			}
		}
	}
}
void Unway(graph *g,int v)
{
	edgenode *e;
	dist[v]=0;
	path[v]=-1;
	visited[v]=5;
	int queue[max];
	int front=0,rear=0;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]!=5)
			{
				visited[e->adjvex]=5;
				dist[e->adjvex]=dist[v]+1;
				path[e->adjvex]=v;
				queue[rear++]=e->adjvex;
			}
		}
	}
}
void PrintWay(graph *g)
{
	printf("Dist:\n");
	for(int i=1;i<=g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nPath:\n");
	for(int i=1;i<=g->nv;i++)
	{
		printf("%d\t",path[i]);
	}
	printf("\n");
}
void CSHdj(graph *g)
{
	for(int i=0;i<=g->nv;i++)
	{
		if(i==1)
		{
			dist[i]=0;
			path[i]=-1;
		}else if(i==2)
		{
			dist[i]=6;
			path[i]=1;
		}else if(i==3)
		{
			dist[i]=1;
			path[i]=1;
		}else if(i==4)
		{
			dist[i]=5;
			path[i]=1;
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
	}
	dist[0]=-1;
}
void Dijkstra(graph *g,int v)
{
	edgenode *e;
	int min;
	while(1)
	{
		min=INT_MAX;
		v=1;
		int i;
		for(int i=1;i<=g->nv;i++)
		{
			if(collect[i]!=1&&dist[i]<min)
			{
				min=dist[i];
				v=i;
			}
		}
	//	printf("%d->",v);
		if(collect[v]==1)
		{
			break;
		}
		collect[v]=1;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collect[e->adjvex]!=1)
			{
				if(dist[e->adjvex]>dist[v]+e->weight)
				{
					dist[e->adjvex]=dist[v]+e->weight;
					path[e->adjvex]=v;
				}
			}
		}
	}
}
void PrintDJ(graph *g)
{
	printf("The Dist:\n");
	for(int i=0;i<=g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nThe Path:\n");
	for(int i=0;i<=g->nv;i++)
	{
		printf("%d\t",path[i]);
	}
}
void CSHPrim(graph *g)
{
	for(int i=1;i<=g->nv;i++)
	{
		if(i==1)
		{
			dist[i]=-1;
			parent[i]=-1;		
		}else if(i==2)
		{
			dist[i]=6;
			parent[i]=1;
		}else if(i==4)
		{
			dist[i]=5;
			parent[i]=1;
		}else if(i==3)
		{
			dist[i]=1;
			parent[i]=1;
		}else 
		{
			dist[i]=INT_MAX;
			parent[i]=INT_MAX;
		}
	}
}

int FindMin(graph *g)
{
	vertex Minv,v;
	int Mindist=INT_MAX;
	for(v=1;v<=g->nv;v++)
	{
		if(dist[v]!=0&&dist[v]<Mindist)
		{
			Mindist=dist[v];
			Minv=v;
		}
	}
	if(Mindist<INT_MAX)
	{
		return Minv;
	}else 
	{
		return -1;
	}
}

void Prim(graph *g,int v)
{
	int Vcount=0;
	edgenode *e;
	dist[v]=0;
	parent[v]=-1;
	Vcount++;
	while(1)
	{
		v=FindMin(g);
		if(v==-1)
		{
			break;
		}
		dist[v]=0;
		Vcount++;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(dist[e->adjvex]!=0&&(dist[v]+e->weight)<dist[e->adjvex])
			{
				
					dist[e->adjvex]=dist[v]+e->weight;
					parent[e->adjvex]=v;
				
			}
		}
		
	}
	
}
void PrintMST(graph *g)
{
	printf("Dist:\n");
	for(int i=1;i<=g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nParent:\n");
	for(int i=1;i<=g->nv;i++)
	{
		printf("%d\t",parent[i]);
	}
	
}

int main()
{
	graph *g=buildg();
	PrintG(g);
	int v=1;
	DFS(g,v);
	printf("\n");
	BFS(g,v);
	printf("\n");
	Unway(g,v);
	PrintWay(g);
	CSHdj(g);
	Dijkstra(g,v);
	PrintDJ(g);
	CSHPrim(g);
	Prim(g,v);
	printf("\nMST:\n");
	PrintMST(g);
}










