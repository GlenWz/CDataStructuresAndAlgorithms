#include <stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAXSIZE 100

typedef int vertex;
typedef struct qnode{
	int data[MAXSIZE];
	int front,rear;
}qnode;

typedef struct edge{
	struct edge *next;
	int weight;
	int Adjvex;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	int head;
}Adjlist[MAXSIZE];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}

bool Isempty(qnode *q)
{
	return q->front==q->rear;
}
bool Isfull(qnode *q)
{
	return q->rear==MAXSIZE;
}
int pushV(qnode *q,int v)
{
	if(Isfull(q))
	{
		printf("the queue is full\n");
		return NULL;
	}
	q->data[q->rear]=v;
	q->rear++;
}
int popV(qnode *q)
{
	if(Isempty(q))
	{
		printf("the queue is empty!\n");
		return NULL;
	}
	return q->data[q->front++];
}


void insertoq(qnode *q)
{
	int a[MAXSIZE]={0,3,1,0,1,2,1,4,10,1,3,3,2,0,4,3,2,2,3,4,2,3,5,8,3,6,4,4,6,6,5,2,5,6,5,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		pushV(q,a[i]);
	}
}
graph *buildG(qnode *q)
{
	vertex v;
	int v1,v2,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=7;
	g->ne=0;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].firstedge=NULL;
		g->adjlist[v].head=v;
	}
	while(!Isempty(q))
	{
		v1=popV(q);
		v2=popV(q);
		w=popV(q);
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		e->Adjvex=v2;
		e->weight=w;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
		++g->ne;
	}
	return g;
}
void printg(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		edgenode *e;
		for(e=g->adjlist[i].firstedge;e!=NULL;e=e->next)
		{
			printf("E:%d(w)",e->Adjvex,e->weight);
		}
		printf("\n");
	}
}
void CS_DFS(int visited[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		visited[i]=0;
	}
}
void DFS(graph *g,int visited[],vertex v)
{
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->Adjvex]==0)
		{
			DFS(g,visited,e->Adjvex);
		}
	}
}
void BFS(graph *g,int visited[],qnode *q,vertex v)
{
	visited[v]=-1;
	printf("%d->",g->adjlist[v].head);
	pushV(q,v);
	while(!Isempty(q))
	{
		v=popV(q);
		edgenode *e;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->Adjvex]==1)
			{
				printf("%d->",g->adjlist[e->Adjvex].head);
				visited[e->Adjvex]=-1;
				pushV(q,e->Adjvex);
			}
		}
	}
}
void CS_UNWAY(int dist[],int path[],graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		dist[i]=-1;
		path[i]=-1;
	}
}
void UNway(graph *g,int dist[],int path[],qnode *q,vertex v)
{
	dist[v]=0;
	pushV(q,v);
	edgenode *e;
	while(!Isempty(q))
	{
		v=popV(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(dist[e->Adjvex]==-1)
			{
				dist[e->Adjvex]=dist[v]+1;
				path[e->Adjvex]=v;
				pushV(q,e->Adjvex);
			}
		}
	}
}
void printway(int dist[],int path[],graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\tPATH:%d\n",dist[i],path[i]);
	}
	
}
void CS_DJ(int dist[],int path[],int collected[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(i==0)
		{
			dist[i]=0;
			path[i]=-1;
		}else if(i==1)
		{
			dist[i]=2;
			path[i]=0;
		}else if(i==3)
		{
			dist[i]=1;
			path[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
		collected[i]=-1;
	}
}
void Dijkstra(int dist[],int path[],int collected[],graph *g,qnode *q,vertex v)
{
	int min;
	while(1)
	{
		edgenode *e;
		e=g->adjlist[v].firstedge;
		min=e->weight;
		int j=v;
		for(;e!=NULL;e=e->next)
		{
			if(e->weight<min)
			{
				min=e->weight;
				v=e->Adjvex;
			}
		}
		if(j==v)
		{
			break;
		}
		collected[v]=1;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collected[e->Adjvex]==-1)
			{
				if(dist[e->Adjvex]>dist[v]+e->weight)
				{
					dist[e->Adjvex]=e->weight+dist[v];
					path[e->Adjvex]=v;
				}
			}
		}
	}
}


int main()
{
	int visited[MAXSIZE];
	int path[MAXSIZE];
	int dist[MAXSIZE];
	int collected[MAXSIZE];
	vertex v=0;
	
	qnode *q=buildq();
	insertoq(q);
	graph *g=buildG(q);
	printg(g);
	CS_DFS(visited);
	printf("\nDFS:\n");
	DFS(g,visited,v);
	printf("\nBFS:\n");
	BFS(g,visited,q,v);
	CS_UNWAY(dist,path,g);
	printf("\nUNwweightWAY:\n");
	UNway(g,dist,path,q,v);
	printway(dist,path,g);
	CS_DJ(dist,path,collected);
	Dijkstra(dist,path,collected,g,q,v);
	printf("\nDijkstra:\n");
	printway(dist,path,g);
}
