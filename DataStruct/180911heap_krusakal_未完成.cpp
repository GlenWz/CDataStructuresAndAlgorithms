#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define maxsize 100
typedef int vertex;
typedef struct edge{
	vertex adjvex;
	struct edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	vertex head;
}Adjlist[maxsize];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

typedef struct qnode{
	int data[maxsize];
	int front,rear;
}qnode;

typedef struct heap{
	edgenode *ele[maxsize];
	int size,capacity;
}heap;

bool isempty(qnode *q)
{
	if(q->front==q->rear)
	{
		return 1;
	}else 
	{
		return 0;
	}
}
bool isfull(qnode *q)
{
	if(q->rear==maxsize)
	{
		return 1;
	}else 
	{
		return 0;
	}
}

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
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
	return q->data[(q->front)++];
}

void insertq(qnode *q)
{
	int a[maxsize]={0,1,1,0,2,2,1,4,2,2,3,3,3,5,4,4,5,3,5,6,5,5,7,7,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}

heap *buildheap()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->capacity=maxsize;
	h->size=0;
//	h->ele=(edgenode *)malloc(sizeof(edgenode)*(maxsize+1));
	h->ele[0]->weight=INT_MIN;
	return h;
}
void pusheap(edgenode *e,heap *h)
{
	int i=++h->size;
	for(;h->ele[i/2]->weight>e->weight;i/=2)
	{
		h->ele[i]=h->ele[i/2];
	}
	h->ele[i]=e;
}

graph *buildg(qnode *q,heap *h)
{
	vertex v,w;
	int v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=8;
	g->nv=8;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].head=v;
		g->adjlist[v].firstedge=NULL;
	}
	for(w=0;w<g->ne;w++)
	{
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		v1=pop(q);
		v2=pop(q);
		v3=pop(q);
		e->adjvex=v2;
		e->weight=v3;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
		pusheap(e,h);
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
			printf("E:%d(W:%d)",e->adjvex,e->weight);
		}
		printf("\n");
	}
}
void Krusal(graph *g,vertex v,heap *h)
{
	edgenode *e;
	edgenode MST[g->nv-1];
	while()
}

int main()
{
	vertex v=0;
	heap *h=buildheap();
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q,h);
	printg(g);
	Krusal(g,v,h);
}
