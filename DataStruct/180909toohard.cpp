#include <Stdio.h>
#include <stdlib.h>
#include <Stdbool.h>
#include <limits.h>
#define maxsize 100

int visited[maxsize];
int dist[maxsize];
int path[maxsize];
int collected[maxsize];
typedef int vertex;
typedef struct edge{
	struct edge *next;
	vertex adjvex;
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

qnode *buildqueue()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}
void chushi()
{
	for(int i=0;i<maxsize;i++)
	{
		dist[i]=-1;
		path[i]=-1;
	}
}
void chushiDJ()
{
	for(int i=0;i<maxsize;i++)
	{
		if(i==0)
		{
			dist[i]=0;
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
vertex pushv(qnode *q,vertex v)
{
	if(isfull(q))
	{
		printf("the queue is full");
		return NULL;
	}
	q->data[q->rear]=v;
	q->rear++;
}
vertex popv(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is empty!");
		return NULL;
	}
	return q->data[(q->front)++];
}

graph *buildgraph()
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
		printf("please input the v1 and v2 and weight:\n");
		scanf("%d%d%d",&v1,&v2,&v3);
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->adjvex=v2;
		e1->weight=v3;
		e1->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e1;
		/*
		edgenode *e2=(edgenod *)malloc(sizeof(edgenode));
		e2->weight=v3;
		e2->adjvex=v1;
		e2->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e2;*/      //·ÇÎÞÏòÍ¼ 
	}
	return g;
}

void printgraph(graph *g)
{
	edgenode *e;
	for(int i=0;i<0;i++)
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

void DFS_G(graph *g,vertex v)
{
	edgenode *e;
	visited[v]=-1;
	printf("%d->",g->adjlist[v].head);
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=-1)
		{
			DFS_G(g,e->adjvex);
		}
	}
}
void BFS_G(graph *g,vertex v,qnode *q)
{
	edgenode *e;
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	pushv(q,v);
	while(!isempty(q))
	{
		v=popv(q);
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]!=1)
			{
				printf("%d->",e->adjvex);
				visited[e->adjvex]=1;
				pushv(q,e->adjvex);
			}
		}
	}
}
void unweightway(graph *g,vertex v,qnode *q)
{
	dist[v]=0;
	edgenode *e;
	pushv(q,v);
	while(!isempty(q))
	{
		v=popv(q);
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(dist[e->adjvex]==-1)
			{
				dist[e->adjvex]=dist[v]+1;
				path[e->adjvex]=v;
				pushv(q,e->adjvex);
			}
			
		}
	}	
}
void printway(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("PATH:%d\n",path[i]);
	}
}
void Dijkstra(vertex v,graph *g)
{
	edgenode *e;
	int tmp;
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
				if((dist[e->adjvex]+e->weight)<dist[e->adjvex])
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
	for(int i=0;i<g->nv;i++)
	{
		printf("Dist:%d\t",dist[i]);
		printf("Path:%d\n",path[i]);
		
	}
}


int main()
{
	graph *g=buildgraph();
	printgraph(g);
	vertex v=0;
	printf("DFS:\n");
	DFS_G(g,v);
	qnode *q=buildqueue();
	printf("\nBFS:\n");
	BFS_G(g,v,q);
	chushi();
	printf("\nUNWAY:\n");
	unweightway(g,v,q);
	printway(g);
	chushiDJ();
	printf("\nDijkstra:\n");
	Dijkstra(v,g);
	printDJ(g);
//	printf("%d \n%d",sizeof(vertex),sizeof(int));
}

