#include <stdio.h>
#include <Stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXSIZE 100
typedef int vertex;
typedef struct edge{
	vertex adjcex;
	struct edge *next;
	int  weight;
}edgenode;

typedef struct vnode{
	vertex head;
	edgenode *firstedge;
}Adjlist[MAXSIZE];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

typedef struct qnode{
	int data[MAXSIZE];
	int front,rear;
}qnode;

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}
bool isfull(qnode *q)
{
	return q->front==MAXSIZE;
}
bool isempty(qnode *q)
{
	return q->rear==q->front;
}

void push(qnode *q,int v)
{
	if(isfull(q))
	{
		printf("the queue is full!\n");
		system("PAUSE");
	}
	q->data[q->rear]=v;
	q->rear++;
}
int pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is empty!");
		return NULL;
	}else 
	{
		return q->data[(q->front)++];
	}
}

void insertV(qnode *q)
{
	int a[]={0,1,3,0,2,2,1,4,1,1,3,3,2,3,3,3,4,2,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}

graph *buildg(qnode *q)
{
	vertex v,w;
	int v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=6;
	g->nv=5;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].firstedge=NULL;
		g->adjlist[v].head=v;
	}
	for(w=0;w<g->ne;w++)
	{
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		v1=pop(q);
		v2=pop(q);
		v3=pop(q);
		e->adjcex=v2;
		e->weight=v3;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
	}
	return g;
}
void printg(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		e=g->adjlist[i].firstedge;
		for(;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)",e->adjcex,e->weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int visited[],vertex v)
{
	visited[v]=-1;
	edgenode *e;
	printf("%d->",g->adjlist[v].head);
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjcex]!=-1)
		{
			DFS(g,visited,e->adjcex);
		}
	}
}
void BFS(graph *g,int visited[],vertex v,qnode *q)
{
	visited[v]=1;
	edgenode *e;
	printf("%d->",g->adjlist[v].head);
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->adjcex]==-1)
			{
				printf("%d->",e->adjcex);
				visited[e->adjcex]=1;
				push(q,e->adjcex);
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
void Unweight(graph *g,int dist[],int path[],vertex v,qnode *q)
{
	dist[v]=0;
	edgenode *e;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(dist[e->adjcex]==-1)
			{
				dist[e->adjcex]=dist[v]+1;
				path[e->adjcex]=v;
				push(q,e->adjcex);
			}
		}
	}
}
void printunway(int dist[],int path[],graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("PATH:%d\n",path[i]);
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
	insertV(q);
	graph *g=buildg(q);
	printg(g);
	printf("\nDFS:\n");
	DFS(g,visited,v);
	printf("\nBFS:\n");
	BFS(g,visited,v,q);
	CS_UNWAY(dist,path);
	Unweight(g,dist,path,v,q);
	printf("\n");
	printunway(dist,path,g);
	
 } 
