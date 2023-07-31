#include <Stdio.h>
#include <stdlib.h>
#include <Stdbool.h>
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
	vertex data[maxsize];
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

void insertVtoQ(qnode  *q)
{
	int a[]={0,1,1,0,2,2,1,2,4,2,3,3,3,5,4,4,5,3,5,6,5,5,7,7,-1};
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
	g->nv=8;
	g->ne=8;
	for(v=0;v<g->nv;g++)
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
		e->weight=v3;
		e->adjvex=v1;
		e->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e;
	}
	return g;
}

void DFS(graph *g,vertex v,int visit[])
{
	edgenode *e;
	printf("%d->",g->adjlist[v].head);
	visit[v]=1;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visit[e->adjvex]!=1)
		{
			DFS(g,e->adjvex,visit);
		}
	}
	
}
void BFS_V(int visit[])
{
	for(int i=0;i<maxsize;i++)
	{
		visit[i]==-1;
	}
}
void BFS(graph *g,qnode *q,int visit[],vertex v)
{
	visit[v]=1;
	push(q,v);
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visit[e->adjvex]!=1)
			{
				printf("%d->",g->adjlist[e->adjvex].head);
				visit[e->adjvex]=1;
				push(q,e->adjvex);
			}
		}
	}
}
void chushi_UNW(int dist[],int path[])
{
	for(int i=0;i<maxsize;i++)
	{
		dist[i]=-1;
		path[i]=-1;
	}
}
void UNway(graph *g,qnode *q,int dist[],int path[],vertex v)
{
	edgenode *e;
	dist[v]=0;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(dist[v]==-1)
			{
				dist[e->adjvex]=dist[v]+1;
				path[e->adjvex]=v;
				push(q,e->adjvex);
			}
		}
	}
}
void printway(graph *g,int dist[],int path[])
{
	for(int i=0;i<g->nv;i++)
	{
		printf("dist:%d\t",dist[i]);
		printf("path:%d\n",path[i]);
	}
}
void printg(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d",g->adjlist[i].head);
		e=g->adjlist[i].firstedge;
		for(;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)",e->adjvex,e->weight);
		}
		printf("\n");
	}
}



int main()
{
	int visit[maxsize];
	int dist[maxsize];
	int path[maxsize];
	int parent[maxsize];
	int collected[maxsize];
	
	vertex v=0;
	qnode *q=buildq();
	insertVtoQ(q);
	graph *g=buildg(q);
	printg(g);
	printf("\nDFS:\n");
	DFS(g,v,visit);
	printf("\nBFS:\n");
	BFS_V(visit);
	BFS(g,q,visit,v);
	chushi_UNW(dist,path);
	UNway(g,q,dist,path,v);
	printway(g,dist,path);
	
}
