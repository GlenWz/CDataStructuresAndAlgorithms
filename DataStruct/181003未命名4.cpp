#include <Stdio.h>
#include <stdlib.h>
#include <Stdbool.h>
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

typedef struct a{
	edgenode *firstedge;
	vertex head;
}Adjlist[MAXSIZE];

typedef struct {
	
	Adjlist adjlist;
	int nv,ne;
}Graph;

bool isempty(qnode *q)
{
	return q->front==q->rear;
}
bool isfull(qnode *q)
{
	return q->rear==MAXSIZE;
}



qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=NULL;
	return q;
}
int push(qnode *q,int v)
{
	if(isfull(q))
	{
		printf("the queue is full!");
		return NULL;
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
	}
	return q->data[q->front++];
}

void insertq(qnode *q)
{
	int a[]={1,2,1,1,3,3,2,4,2,2,5,5,4,8,3,5,8,2,3,6,4,3,7,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}

Graph *buildg(qnode *q)
{
	int v1,v2,w;
	Graph *gl=(Graph *)malloc(sizeof(Graph));
	gl->ne=0;
	gl->nv=9;
	while(!isempty(q))
	{
		v1=pop(q);
		v2=pop(q);
		w=pop(q);
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		e->Adjvex=v2;
		e->weight=w;
		e->next=gl->adjlist[v1].firstedge;
		gl->adjlist[v1].firstedge=e;
	}
	return gl;
}
void DFS_G(Graph *gl,int visited[],int v)
{
	visited[v]=1;
	printf("%d->",gl->adjlist[v].head);
	edgenode *e;
	for(e=gl->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->Adjvex]!=1)
		{
			DFS_G(gl,visited,e->Adjvex);
		}
	}
}


int main()
{
	int visited[MAXSIZE];
	int dist[MAXSIZE];
	int path[MAXSIZE];
	vertex v=0;
	qnode *q=buildq();
	insertq(q);
	Graph *g=buildg(q);
	DFS_G(g,visited,1);
}

