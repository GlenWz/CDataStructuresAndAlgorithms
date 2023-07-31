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
	vertex adjvex;
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

typedef struct heap{
	edgenode *data[MAXSIZE];
	int capacity;
	int size;
}heap;

bool isfull(qnode *q)
{
	return q->rear==MAXSIZE;
}
bool isempty(qnode *q)
{
	return q->front==q->rear;
}
bool heapisfull(heap *h)
{
	return h->size==MAXSIZE;
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
		printf("the queue is enpty!");
		return NULL;
	}
	return q->data[(q->front)++];
}

void insertq(qnode *q)
{
	int a[]={0,3,1,0,1,2,1,4,10,1,3,3,2,0,4,3,2,2,3,4,2,3,5,8,3,6,4,4,6,6,5,2,5,6,5,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}
/*heap *buildh()
{
	heap *h=(heap *)malloc(sizeof(heap));
	h->capacity=MAXSIZE;
	h->size=0;
	h->data[h->size]->weight=INT_MAX;
	return h;
} */
/*
int enheap(heap *h,edgenode *e)
{
	if(heapisfull(h))
	{
		printf("the heap is full!");
		return NULL;
	}
	int i=++h->size;
	for(;h->data[i/2]->weight<e->weight;i/=2)
	{
		h->data[i]=h->data[i/2];
	}
	h->data[i]=e;
}
*/
graph *buildg(qnode *q)
{
	vertex v,w;
	int v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=12;
	g->nv=7;
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
	//	enheap(h,e);
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
void DFS(graph *g,int visited[],vertex v)
{
	visited[v]=-1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=-1)
		{
			DFS(g,visited,e->adjvex);
		}
	}
}
qnode *qnodeempty(qnode *q)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		q->data[i]=NULL;
	}
	q->rear=q->front=0;
	return q;
}


void BFS(graph *g,int visited[],vertex v,qnode *q)
{
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	push(q,v);
	edgenode *e;
	while(!isempty(q))
	{
		v=pop(q);
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]==-1)
			{
				visited[e->adjvex]=1;
				printf("%d->",e->adjvex);	
				push(q,e->adjvex);
			}	
		}
	}	
}
void CS_WAY(int dist[],int path[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		dist[i]=-1;
		path[i]=-1;
	}
}


void UNWAY(graph *g,int dist[],int path[],vertex v,qnode *q)
{
	dist[v]=0;
	push(q,v);
	edgenode *e;
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(dist[e->adjvex]==-1)
			{
				dist[e->adjvex]=dist[v]+1;
				path[e->adjvex]=v;
				push(q,e->adjvex);
			}
		}
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
		}else {
			dist[i]=INT_MAX;
			path[i]=-1;
		}
		collected[i]=-1;
	}
}


void printWay(int dist[],int path[],graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("PATH:%d\n",path[i]);
	}
}
void Dijkstra(int dist[],int path[],graph *g,vertex v,int collected[])
{
	int min;
	edgenode *e;
	while(1)
	{
		e=g->adjlist[v].firstedge;
		if(e->next==NULL)
		{
			e=g->adjlist[e->adjvex].firstedge;
		}
		min=e->weight;
		for(;e!=NULL;e=e->next)
		{
			if(e->weight<min)
			{
				min=e->weight;
				v=e->adjvex;
			}
		}
		if(v==NULL)
		{
			break;
		}
		collected[v];
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collected[e->adjvex]==-1)
			{
				if(dist[v]+e->weight<dist[e->adjvex])
				{
					dist[e->adjvex]=dist[v]+e->weight;
					path[e->adjvex]=v;
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
//	heap *h=buildh();
	graph *g=buildg(q);
	printg(g);
	printf("\nDFS:\n");
	DFS(g,visited,v);
	printf("\nBFS:\n");
	qnode *kq=qnodeempty(q);
	BFS(g,visited,v,kq);
	CS_WAY(dist,path);
	UNWAY(g,dist,path,v,kq);
	printf("\nUNweightWAY:\n");
	printWay(dist,path,g);
	CS_DJ(dist,path,collected);
	printf("\nDijkstra:\n");
	Dijkstra(dist,path,g,v,collected);
	printWay(dist,path,g);
	
	return 0;
	
}
