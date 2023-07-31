#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define MAXSIZE 100

typedef int vertex;
typedef struct q{
	int data[MAXSIZE];
	int front,rear;
}qnode;

typedef struct edge{
	struct edge *next;
	int Adjvex;
	int weight;
}edgenode;
typedef struct vnode{
	vertex head;
	edgenode *firstedge;
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
	int a[]={0,3,1,0,1,2,1,4,10,1,3,3,2,0,4,3,2,2,3,4,2,3,5,8,3,6,4,4,6,6,5,2,5,6,5,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}
graph *buildg(qnode *q)
{
	vertex v;
	int v1,v2,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=7;
	g->ne=0;
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
		edgenode *e=(edgenode *)malloc(sizeof(edgenode ));
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
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		edgenode *e;
		for(e=g->adjlist[i].firstedge;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)",e->Adjvex,e->weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int visited[],vertex v)
{
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->Adjvex]!=1)
		{
			DFS(g,visited,e->Adjvex);
		}
	}
}
void BFS(graph *g,int visited[],vertex v,qnode *q)
{
	visited[v]=-1;
	printf("%d->",g->adjlist[v].head);
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		edgenode *e;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->Adjvex]!=-1)
			{
				visited[e->Adjvex]=-1;
				printf("%d->",g->adjlist[e->Adjvex].head);
				push(q,e->Adjvex);
			}
		}
	}
}
void CS_UWAY(int dist[],int path[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		dist[i]=-1;
		path[i]=-1;
	}
}
void UWAY(graph *g,qnode *q,int dist[],int path[],vertex v)
{
	edgenode *e;
	dist[v]=0;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(dist[e->Adjvex]==-1)
			{
				dist[e->Adjvex]=dist[v]+1;
				path[e->Adjvex]=v;
				push(q,e->Adjvex);
			}
		}
	}
}
void printway(int dist[],int path[],graph *g)
{
	printf("\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("PATH:%d\n",path[i]);
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
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
		collected[i]=-1;
	}
}
void Dijkstra(graph *g,int dist[],int path[],int collected[],vertex v)
{
	edgenode *e;
	int min;
	while(1)
	{
		e=g->adjlist[v].firstedge;
		min=e->weight;
		v=e->Adjvex;
		int j=v;
		for(;e!=NULL;e=e->next)
		{
			if(min>e->weight)
			{
				min=e->weight;
				v=e->Adjvex;
			}
		}
	//	printf("duoshaoci");
		if(v==j)
		{
			break;
		}
		collected[v]=1;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collected[e->Adjvex]==-1)
			{
				if(dist[e->Adjvex]>dist[e->Adjvex]+e->weight)
				{
					dist[e->Adjvex]=dist[v]+e->weight;
					path[e->Adjvex]=v;
				}
			}
		}	
	}
}
void CS_PRIME(int dist[],int path[],int parent[],int collected[])
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
			path[i]==0;
		}else if(i==3)
		{
			dist[i]=1;
			path[i]=0;
		}else{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
		parent[i]=-1;
	}
}
void prime(graph *g,vertex v,int dist[],int parent[])
{
	int mst=0,min;
	int MST[g->nv];
	MST[mst++]=v;
	parent[v]=-1;
	edgenode *e;
	while(1)
	{
		e=g->adjlist[v].firstedge;
		min=e->weight;
		v=e->Adjvex;
		int j=v;
		for(;e!=NULL;e=e->next)
		{
			if(e->weight<min&&parent[e->Adjvex]==-1)
			{
				min=e->weight;
				v=e->Adjvex;
			}
		}
		if(j==v)
		{
			break;
		}
		MST[(mst)++]=v;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(parent[e->Adjvex]==-1)
			{
				if(e->weight<dist[e->Adjvex])
				{
					dist[e->Adjvex]=e->weight;
					parent[e->Adjvex]=v;
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
	int mst[MAXSIZE];
	int parent[MAXSIZE];
	vertex v=0;
	qnode *q=buildq();	
	insertq(q);
	graph *g=buildg(q);
	print(g);
	printf("\nDFS:\n");
	DFS(g,visited,v);
	printf("\nBFS:\n");
	BFS(g,visited,v,q);
	CS_UWAY(dist,path);
	UWAY(g,q,dist,path,v);
	printway(dist,path,g);
	CS_DJ(dist,path,collected);
	Dijkstra(g,dist,path,collected,v);
	printf("\nDijkstra:\n");
	printway(dist,path,g);
	CS_PRIME(dist,path,parent,collected);
	prime(g,v,dist,parent);
	printf("\nthe prime:\n");
	printway(dist,parent,g);
	
}
