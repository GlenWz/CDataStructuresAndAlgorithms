#include <Stdio.h>
#include <stdlib.h>
#include <limits.h>
#define maxsize 100
typedef int vertex;
typedef struct edge{
	struct edge *next;
	vertex adjvex;
	int weight;
}edgenode;

typedef struct vnode{
	vertex head;
	edgenode *firstedge;
}Adjlist[maxsize];

typedef struct{
	Adjlist adjlist;
	int nv,ne;
}graph;

typedef struct qnode{
	int data[maxsize];
	int front,rear;
}qnode;

typedef struct heap{
	edgenode *data[maxsize];
	int capacity;
	int size;
}heap;

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
heap *buildh()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->size=0;
	h->data[0]->weight=-999;
	h->capacity=maxsize;
	return h;
}

bool enheap(heap *h,edgenode *e)
{
	int i=++h->size;
	if(h->size==maxsize)
	{
		printf("the heap is full");
		return false;
	}
	for(;h->data[i/2]->weight>e->weight;i/=2)
	{
		h->data[i]=h->data[i/2];
	}
	h->data[i]=e;
	return true;
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
		printf("the queue is full");
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

void insertValue(qnode *q)
{
	int a[maxsize]={0,1,3,0,2,2,2,3,3,1,3,3,1,4,1,3,4,2,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}	
} 

graph *buildg(qnode *q,heap *h)
{
	vertex v,w;
	int v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=6;
	g->nv=5;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].head=v;
		g->adjlist[v].firstedge=NULL;
	}
	for(w=0;w<g->ne;w++)
	{
		v1=pop(q);
		v2=pop(q);
		v3=pop(q);
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		e->adjvex=v2;
		e->weight=v3;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
		enheap(h,e);
	}
	return g;
}
void printg(graph *g)
{
	edgenode  *e;
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
void DFS(graph *g,int v,int visited[])
{
	visited[v]=-1;
	edgenode *e;
	printf("%d->",g->adjlist[v].head);
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=-1)
		{
			DFS(g,e->adjvex,visited);
		}
	}
}

void BFS(graph *g,int v,int visited[])
{
	visited[v]=1;
	edgendoe *e;
	
	
	
}



int main()
{
	int visited[maxsize];
	
	vertex v=0;
	qnode *q=buildq();
	heap *h=buildh();
	insertValue(q);
	graph *g=buildg(q,h);
	printg(g);
	DFS(g,v,visited);
	BFS(g,v,visited);
	//Dijkstra(g,v);
}
