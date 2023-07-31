#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAXSIZE 100

typedef int vertex;
typedef struct qnode{
	int data[MAXSIZE];
	int front,rear;
}qnode;

typedef struct edge{
	vertex Adjvex;
	int weight;
	struct edge *next;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	vertex head;
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
bool isfull(qnode *q)
{
	return q->rear==MAXSIZE;
}
bool isempty(qnode *q)
{
	return q->front==q->rear;
}

int push(qnode *q,int a)
{
	if(isfull(q))
	{
		printf("the queue is full!");
		return NULL;
	}
	q->data[q->rear]=a;
	q->rear++;
}
int pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is empty!");
		return NULL;
	}
	return q->data[(q->front)++];
}


void insertq(qnode *q)
{
	int a[]={0,1,2,1,5,1,1,2,3,1,3,2,3,6,5,3,4,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}

graph *build(qnode *q)
{
	vertex v,w;
	int v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=6;
	g->nv=7;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].firstedge=NULL;
		g->adjlist[v].head=v;
	}
	for(w=0;w<g->ne;w++)
	{
		edgenode *e=(edgenode *)malloc(sizeof(edgenode ));
		v1=pop(q);
		v2=pop(q);
		v3=pop(q);
		e->Adjvex=v2;
		e->weight=v3;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
	}
	return g;
}
void print(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		for(e=g->adjlist[i].firstedge;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)",e->Adjvex,e->weight);
		}
		printf("\n");
	}
	printf("\n");
}
void DFS(graph *g,int visited[],vertex v)
{
	visited[v]=-1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->Adjvex]!=-1)
		{
			DFS(g,visited,e->Adjvex);
		}
	}
}
void BFS(graph *g,qnode *q,int visited[],vertex v)
{
	visited[v]==1;
	push(q,v);
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->Adjvex]==-1)
			{
				visited[e->Adjvex]=1;
				printf("%d->",e->Adjvex);
				push(q,e->Adjvex);
			}
		}
	}
}
void CS_UNWAY(int dist[],int path[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		dist[i]=-1;
		path[i]=-1;
	}
}
void UNWAY(int dist[],int path[],graph *g,qnode *q,vertex v)
{
	edgenode *e;
	dist[v]=0;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(dist[e->Adjvex]==-1)
			{
				dist[e->Adjvex]=dist[v]+1;
				path[e->Adjvex]=v;
				push(q,e->Adjvex);
			}
		}
	}
}
void printway(int dist[],int path[],graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("PATH:%d\n",path[i]);
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
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
		collected[i]=-1;
	}
}
void Dijkstra(int dist[],int path[],int collected[],graph *g,vertex v)
{
	int min;
	edgenode *e;
	int i=0;
	while(1)
	{
		e=g->adjlist[v].firstedge;
		min=e->weight;
		for(;e!=NULL;e=e->next)
		{
			if(e->weight<min)
			{
				min=e->weight;
				v=e->Adjvex;
			}
		}
		collected[v]=1;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collected[e->Adjvex]==-1)
			{
				if(dist[v]+e->weight<dist[e->Adjvex])
				{
					dist[e->Adjvex]=dist[v]+e->weight;
					path[e->Adjvex]=v;
				}
			}
		}
	}
}
int main()
{
	int visited[MAXSIZE];
	int dist[MAXSIZE];
	int path[MAXSIZE];
	int collected[MAXSIZE];
	vertex v=0;
	qnode *q=buildq();
	insertq(q);
	graph *g=build(q);	
	print(g);
	printf("\nDFS:\n");
	DFS(g,visited,v);
	printf("\nBFS:\n");
	BFS(g,q,visited,v);
	CS_UNWAY(dist,path);
	UNWAY(dist,path,g,q,v);
	printf("\nUNWAY:\n");
	printway(dist,path,g);
	CS_DJ(dist,path,collected);
	Dijkstra(dist,path,collected,g,v);
	printf("\nDijkstra:\n");
	printway(dist,path,g);
	
	
	
}
