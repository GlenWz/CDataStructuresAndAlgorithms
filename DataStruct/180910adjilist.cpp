#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define maxsize 100

int visited[maxsize]={};
int dist[maxsize]={};
int path[maxsize]={};
int collected[maxsize]={};
int parent[maxsize]={};
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

void UnweightCS()
{
	for(int i=0;i<maxsize;i++)
	{
		dist[i]=-1;
		path[i]=0;
	}
}


void chushihua()
{
	for(int i=0;i<maxsize;i++)
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
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
		collected[i]=-1;
		parent[i]=-1;
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
	int a[maxsize]={0,3,1,0,1,2,1,4,10,1,3,3,2,0,4,3,2,2,3,4,2,3,5,8,3,6,4,4,6,6,5,2,5,6,5,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}
graph *buildg(qnode *q)
{
	int v1,v2,v3;
	vertex v,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=7;
	g->ne=12;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].firstedge=NULL;
		g->adjlist[v].head=v;
	}
	for(w=0;w<g->ne;w++)
	{
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		v2=pop(q);
		v1=pop(q);
		v3=pop(q);
		e->adjvex=v1;
		e->weight=v3;
		e->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e;
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
		while(e!=NULL)
		{
			printf("E:%d(W:%d)",e->adjvex,e->weight);
			e=e->next;
		}
		printf("\n");
	}
}

void DFS(graph *g,vertex v)
{
	edgenode *e;
	visited[v]=-1;
	printf("%d->",g->adjlist[v].head);
	e=g->adjlist[v].firstedge;
	while(e!=NULL)
	{
		if(visited[e->adjvex]!=-1)
		{
			DFS(g,e->adjvex);
		}
		e=e->next;
	}
}

void BFS(graph *g,qnode *q,vertex v)
{
	edgenode *e;
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]!=1)
			{
				visited[e->adjvex]=1;
				printf("%d->",e->adjvex);
				push(q,e->adjvex);
			}
		}
	}
}

void unweightway(graph *g,vertex v,qnode *q)
{
	dist[v]=0;
	edgenode *e;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
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
void Dijkstra(graph *g,vertex v)
{
	int tmp;
	edgenode *e;
	while(1)
	{
		e=g->adjlist[v].firstedge;
		tmp=e->weight;
		v=e->adjvex;
		for(;e!=NULL;e=e->next)
		{
			if(e->weight<tmp)
			{
				tmp=e->weight;
				v=e->adjvex;
			}
		}
		if(v==NULL)
		{
			break;
		}
		collected[v]=1;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collected[e->adjvex]==-1)
			{
				if(dist[e->adjvex]+e->weight<dist[e->adjvex])
				{
					dist[e->adjvex]=dist[v]+e->weight;
					path[e->adjvex]=v;
				}
			}
		}
	}
}

void printDJ(graph *g)
{
	printf("\nthe Dijkstra:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("PATH:%d\n",path[i]);
	}
}
void Prime(graph *g,vertex v)
{
	int mst=0,tmp;
	int MST[g->nv];
	MST[(mst)++]=v;
	parent[v]=-1;
	edgenode *e;
	while(1)
	{
		e=g->adjlist[v].firstedge;
		tmp=e->weight;
		v=e->adjvex;
		for(;e!=NULL;e=e->next)
		{
			if(e->weight<tmp&&parent[e->adjvex]==-1)
			{
				tmp=e->weight;
				v=e->adjvex;
			}
		}
		if(v==NULL)
		{
			break;
		}
		MST[(mst)++]=v;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(parent[e->adjvex]==-1)
			{
				if(e->weight<dist[e->adjvex])
				{
					dist[e->adjvex]=e->weight;
					parent[e->adjvex]=v;
				}
			}
		}
		
	}
	
}
void printPT(graph *g)
{
	printf("\nTHE Prime:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("FQin:%d\n",parent[i]);
	}
}
void printUnway(graph *g)
{
	printf("\nUnweightWay:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("PATH:%d\n",path[i]);
	}
}

int main()
{
	vertex v=0;
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	printg(g);
	printf("\nDFS:\n");
	DFS(g,v);
	printf("\nBFS:\n");
	BFS(g,q,v);
	UnweightCS();
	unweightway(g,v,q);
	printUnway(g);
	chushihua();
	Dijkstra(g,v);
	printDJ(g);
	chushihua();
	Prime(g,v);
	printPT(g);
}
