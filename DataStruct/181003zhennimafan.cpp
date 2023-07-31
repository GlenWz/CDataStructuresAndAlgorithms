#include <Stdio.h>
#include <Stdlib.h>
#include <Stdbool.h>
#include <limits.h>
#define MAXSIZE 100

typedef int vertex;

typedef struct qnode{
	int Data[MAXSIZE];
	int front,rear;
}qnode;

typedef struct edge{
	vertex Adjvex;
	struct edge *next;
	int weight;
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

bool isempty(qnode *q)
{
	return q->front==q->rear;
}
bool isfull(qnode *q)
{
	return q->rear==MAXSIZE;
}
int push(qnode *q,int v)
{
	if(isfull(q))
	{
		printf("the queue is full!\n");
		return NULL;
	}
	q->Data[q->rear]=v;
	q->rear++;
}
int pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is fulll:\n");
		return NULL;
	}
	return q->Data[q->front++];
}


void insertq(qnode *q)
{
	int a[]={1,2,1,1,3,3,2,4,2,2,5,5,4,8,3,5,8,2,3,6,4,3,7,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}
graph *build(qnode *q)
{
	int v1,v2,w;
	vertex v;
	graph *g=(graph *)malloc(sizeof(graph));
	
	g->ne=0;
	g->nv=9;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].firstedge=NULL;
		g->adjlist[v].head=v;
	}
	while(!isempty(q))
	{
		v1=pop(q);
		v2=pop(q);
		w=pop(q);
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		e->Adjvex=v2;
		e->weight=w;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
		++g->ne;
	}
	return g;
}
void print(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		e=g->adjlist[i].firstedge;
		for(;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)",e->Adjvex,e->weight);
		}
		printf("\n");
	}
}

void DFS(graph *g,vertex v,int visited[])
{
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->Adjvex]!=1)
		{
			DFS(g,e->Adjvex,visited);
		}
	}
}
void BFS(graph *g,int visited[],qnode *q,vertex v)
{
	visited[v]=-1;
	printf("%d->",g->adjlist[v].head);
	push(q,v);
	edgenode *e;
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->Adjvex]!=-1)
			{	
				visited[e->Adjvex]=-1;
				printf("%d->",e->Adjvex);
				push(q,e->Adjvex);
			}
		}
	}
}

int main()
{
	int visited[MAXSIZE];
	qnode *q=buildq();
	insertq(q);
	graph *g=build(q);
	print(g);
	printf("DFS:\n");
	DFS(g,1,visited);
	printf("\n");
	BFS(g,visited,q,1);
}
