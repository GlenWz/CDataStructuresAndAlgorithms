#include <Stdio.h>
#include <stdlib.h>
#define max 100

int visited[max];
int pre[max];
int dist[max];
int parent[max];




typedef int vertex;
typedef struct edge{
	vertex adjvet;
	edge *next;
	int weight;
}edgenode;
typedef struct vnode{
	edgenode *firstedge;
	vertex head;
}Adjlist[max];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

graph *buildg()
{
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=10;
	g->nv=8;
	int v1,v2,w;
	int queue[]={0,1,1,1,2,4,1,3,1,1,4,2,2,5,1,2,4,1,3,5,3,3,6,2,6,7,1,1,7,3,};
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
		w=queue[front++];
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->adjvet=v1;
		e1->weight=w;
		e1->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e1;
		
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->adjvet=v2;
		e2->weight=w;
		e2->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e2;
	}
	return g;
}
void Printg(graph *g)
{
	int i;
	edgenode *e;
	for(i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		for(e=g->adjlist[i].firstedge;e!=NULL;e=e->next)
		{
			printf("E%d(w:%d)->",e->adjvet,e->weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int v)
{
	edgenode *e;
	visited[v]=1;
	printf("%d->",v);
	e=g->adjlist[v].firstedge;
	for(;e;e=e->next)
	{
		if(visited[e->adjvet]!=1)
		{
			DFS(g,e->adjvet);
		}
	}
}
void BFS(graph *g,int v)
{
	printf("\n The BFS is :\n");
	edgenode *e;
	int queue[max];
	int front=0,rear=0;
	visited[v]=5;
	printf("%d->",v);
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->adjvet]!=5)
			{
				visited[e->adjvet]=5;
				printf("%d->",e->adjvet);
				queue[rear++]=e->adjvet;
			}
		}
	}
	printf("\n");
}
void CSHway(graph *g)
{
	int i;
	for(i=0;i<g->nv;i++)
	{
		if(i==0)
		{
			pre[i]=-1;
			dist[i]=0;
		}else 
		{
			pre[i]=-1;
			dist[i]=INT_MAX;
		}
	}
}

void Unway(graph *g,int v)
{
	int queue[max];
	int front=0,rear=0;
	edgenode *e;
	visited[v]=8;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->adjvet]!=8)
			{
				visited[e->adjvet]=8;
				pre[e->adjvet]=v;
				dist[e->adjvet]=dist[v]+1;
				queue[rear++]=e->adjvet;
			}
		}
	}
}
void PrintWay(graph *g)
{
	printf("\npre:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",pre[i]);
	}
	printf("\ndist:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
}
void CSHDJ(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		if(i==0)
		{
			parent[i]=-1;
			dist[i]=0;
		}else if(i==1)
		{
			parent[i]=0;
			dist[i]=1;
		}else 
		{
			parent[i]=-1;
			dist[i]=INT_MAX;
		}
	}
}
int FindMin(graph *g)
{
	int ret,distmin=INT_MAX;
	for(int i=0;i<g->nv;i++)
	{
		if(dist[i]<distmin&&visited[i]!=9)
		{
			distmin=dist[i];
			ret=i;
		}
	}
	if(distmin==INT_MAX)
	{
		return -1;
	}else 
	{
		return ret;
	}
}


void Dijkstra(graph *g,int v)
{
	edgenode *e;
	while(1)
	{
		v=FindMin(g);
		if(v==-1)
		{
			break;
		}
		visited[v]=9;
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(visited[e->adjvet]!=9)
			{
				if(dist[e->adjvet]>dist[v]+e->weight)
				{
					dist[e->adjvet]=dist[v]+e->weight;
					parent[e->adjvet]=v;
				}
			}
		}
	}
}
void PrintDJ(graph *g)
{
	int i;
	printf("Dijkstra:\n");
	for(i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nparent:\n");
	for(int j=0;j<g->nv;j++)
	{
		printf("%d\t",parent[j]);
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

int FindMinP(graph *g)
{
	int distmin=INT_MAX,ret;
	for(int i=0;i<g->nv;i++)
	{
		if(visited[i]!=11&&dist[i]<distmin)
		{
			distmin=dist[i];
			ret=i;		
		}
	}	
	if(distmin==INT_MAX)
	{
		return -1;
	}else 
	{
		return ret;
	}
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
		visited[v]=11;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->adjvet]!=11)
			{
				if(dist[e->adjvet]>dist[v]+e->weight)
				{
					dist[e->adjvet]=e->weight;
					parent[e->adjvet]=v;
				}
			}
		}	
	}
}

void PrintP(graph *g)
{
	printf("\nPrim:\n");
	int i;
	printf("\ndist[i]:\n");
	for(i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nparent:\n");
	for(i=0;i<g->nv;i++)
	{
		printf("%d\t",parent[i]);
	}
	
}



int main()
{
	int v=0;
	graph *g=buildg();
	Printg(g);
	printf("\nthe DFS is :\n");
	DFS(g,v);
	BFS(g,v); 
	CSHway(g);
	Unway(g,v);
	PrintWay(g);
	CSHDJ(g);
	Dijkstra(g,v);
	printf("\n");
	PrintDJ(g);
	CSHprim(g);
	Prim(g,v);
	PrintP(g);
}












