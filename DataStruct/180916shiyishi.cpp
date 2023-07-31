#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAXSIZE 100

typedef int vertex;
typedef struct edge{
	vertex adjvex;
	struct edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	vertex head;
}Adjlist[MAXSIZE];

typedef struct {
	Adjlist asjlist;
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
	int a[]={0,1,1,1,2,1,1,3,2,2,4,3,3,5,4,4,5,5,-1};
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
	g->nv=6;
	for(v=0;v<g->nv;v++)
	{
		g->asjlist[v].head=v;
		g->asjlist[v].firstedge=NULL;
	}
	for(w=0;w<g->ne;w++)
	{
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		v1=pop(q);
		v2=pop(q);
		v3=pop(q);
		e->adjvex=v2;
		e->weight=v3;
		e->next=g->asjlist[v1].firstedge;
		g->asjlist[v1].firstedge=e;
	}
	return g;
}
void printg(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->asjlist[i].head);
		e=g->asjlist[i].firstedge;
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
	edgenode *e;
	printf("%d->",g->asjlist[v].head);
	for(e=g->asjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=-1)
		{
			DFS(g,visited,e->adjvex);
		}
	}
}
void BFS(graph *g,int visited[],qnode *q,vertex v)
{
	visited[v]=1;
	edgenode *e;
	printf("%d->",g->asjlist[v].head);
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->asjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]==-1)
			{
				printf("%d->",e->adjvex);
				visited[e->adjvex]=1;
				push(q,e->adjvex);
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
void UNWAY(graph *g,qnode *q,int dist[],int path[],vertex v)
{
	dist[v]=0;
	edgenode *e;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->asjlist[v].firstedge;e!=NULL;e=e->next)
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
void printWAY(int dist[],int path[],graph *g)
{
	printf("\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
		printf("%d\n",path[i]);
	}
}
void CS_DJ(int dist[],int path[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(i==0)
		{
			dist[i]=0;
		}else if(i==1)
		{
			dist[i]=1;
			path[i]=0;
		}else if(i==2)
		{
			dist[i]=1;
			path[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
	}
}

void Dijkstra(int dist[],int path[],graph *g,vertex v,int collected[])
{
	int tmp;
	edgenode *e;
	tmp=e->weight;
	v=e->adjvex;
	while(1)
	{
		
		for(e=g->asjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collected[e->adjvex]==-1)
			{
				if(e->weight<tmp)
				{
					tmp=e->weight;
					v=e->adjvex;
				}
			}
			
		}
		if(v==NULL)
		{
			break;
		}
		collected[v]=1;
		for(e=g->asjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collected[e->adjvex]!=1)
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
	vertex v=0;
	int visited[MAXSIZE];
	int dist[MAXSIZE];
	int path[MAXSIZE];
	int collected[MAXSIZE];
	
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	printg(g);
	printf("\nDFS:\n");
	DFS(g,visited,v);
	printf("\nBFS:\n");
	BFS(g,visited,q,v);
	CS_UNWAY(dist,path);
	UNWAY(g,q,dist,path,v);
	printWAY(dist,path,g);
	CS_DJ(dist,path);
	Dijkstra(dist,path,g,v,collected);
	printWAY(dist,path,g);
	
}
