#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 100 

typedef int vertex;
typedef struct edge{
	vertex Adjvex;
	int weight;
	struct edge *next;
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
	int  data[MAXSIZE];
	int front,rear;
}qnode;

qnode*buildq()
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

int push(int a,qnode *q)
{
	if(isfull(q))
	{
		printf("the queue  is full!");
		return NULL;
	}
	q->rear=a;
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
	int a[]={0,1,3,3,2,3,3,4,2,4,5,2,5,2,2,2,1,3,3,5,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(a[i],q);
	}
}
graph *buildg(qnode *q)
{
	vertex v,w;
	int v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=6;
	g->ne=7;
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
}

int main()
{
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	print(g);
	
	
}
