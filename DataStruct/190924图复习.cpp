#include <stdio.h>
#include <stdlib.h>
#define max 100

int visited[max]={0,};
int parent[max];
int dist[max];
int indegree[max];
typedef int vex;
typedef struct edge{
	vex vertex;
	struct edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	edgenode * firstedge;
	vex head;
}Adjlist[max];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

graph *buildg()
{
	int queue[]={0,1,1,1,2,4,1,4,2,2,4,1,2,5,1,1,3,1,1,7,3,3,5,3,3,6,2,6,7,1,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=10;
	g->nv=8;
	int v1,v2,w;
	for(int v=0;v<g->nv;v++)
	{
		g->adjlist[v].firstedge=NULL;
		g->adjlist[v].head=v;
	}
	for(int e=0;e<g->ne;e++)
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
void PrintG(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d",g->adjlist[i].head);
		for(e=g->adjlist[i].firstedge;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)->",e->vertex,e->weight);
		}
		printf("\n");
	}
}

void DFS(graph *g,int v)
{
	edgenode *e;
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->vertex]!=1)
		{
			DFS(g,e->vertex);
		}
	}
}
void BFS(graph *g,int v)
{
	edgenode *e;
	int queue[max];
	int front=0,rear=0;
	visited[v]=8;
	printf("%d->",g->adjlist[v].head);
	queue[rear++]=g->adjlist[v].head;
	while(front!=rear)
	{
		v=queue[front++];
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->vertex]!=8)
			{
				visited[e->vertex]=8;
				printf("%d->",e->vertex);
				queue[rear++]=e->vertex;
			}
		}
	}
}
void CSHUnway(graph *g)
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
	edgenode *e;
	int queue[max];
	int front=0,rear=0;
	queue[rear++]=g->adjlist[v].head;
	visited[v]=5;
	while(front!=rear)
	{
		v=queue[front++];
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->vertex]!=5)
			{
				visited[e->vertex]=5;
				dist[e->vertex]=dist[v]+1;
				parent[e->vertex]=v;
				queue[rear++]=e->vertex;	
			}	
		} 
	}
}
void PrintWay(graph *g)
{
	printf("DIST:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nParT:\n");
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

int FindMinDJ(graph *g)
{
	int Min=INT_MAX,ret=-1;
	for(int i=0;i<g->nv;i++)
	{
		if(visited[i]!=7&&dist[i]<Min)
		{
			Min=dist[i];
			ret=i;
		}
	}
	return ret;
}

void Dijkstra(graph *g,int v)	//Dijkstra算法 
{
	edgenode *e;
	while(1)
	{
		v=FindMinDJ(g);
		if(v==-1)
		{
			break;
		}
		visited[v]=7;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->vertex]!=7)
			{
				if(dist[e->vertex]>dist[v]+e->weight)
				{
					dist[e->vertex]=dist[v]+e->weight;
					parent[e->vertex]=v;
				}
			}
		}
	}
}
void PrintDJ(graph *g)
{
	printf("DIST:\n");
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

void CSHPrim(graph *g)
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
	int Min=INT_MAX,ret=-1;
	for(int i=0;i<g->nv;i++)
	{
		if(dist[i]<Min&&visited[i]!=6)
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
		v=FindMinP(g);
		if(v==-1)
		{
			break;
		}
		visited[v]=6;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->vertex]!=6)
			{
				if(dist[e->vertex]>e->weight)
				{
					dist[e->vertex]=e->weight;
					parent[e->vertex]=v;	
				}
			}
		}
	}
}

void PrintPrim(graph *g)
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








int main()
{
	graph *g=buildg();
	PrintG(g);
	int v=0;
	printf("\n深度优先遍历为:\n");
	DFS(g,v);
	printf("\n广度优先遍历为:\n");
	BFS(g,v);
	printf("\n无权图的最短路:\n");
	CSHUnway(g);
	Unway(g,v);
	PrintWay(g);
	printf("\nDijkstra:\n");
	CSHDJ(g);
	Dijkstra(g,v);
	PrintDJ(g);
	printf("\nPrim:\n");
	CSHPrim(g);
	Prim(g,v);
	PrintPrim(g);
	printf("\n拓扑排序:\n");

	
}















