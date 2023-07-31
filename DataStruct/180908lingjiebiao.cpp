#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 100 
int visited[maxsize]={};
int dist[30]={-1};
int path[30]={-1};

typedef int vertex;
typedef struct edge {
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

typedef struct qndoe{
	int data[maxsize];
	int front,rear;
}qnode;

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

void chushihua()
{
	for(int i=0;i<30;i++)
	{
		dist[i]=-1;
		path[i]=-1;
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

graph *buildg()
{
	int v1,v2;
	vertex v,w;
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
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		printf("please input v1->v2:\n");
		scanf("%d%d",&v1,&v2);
		e1->adjvex=v2;
		e1->next=g->adjlist[v1].firstedge;
		e1->weight=maxsize-99+w;
		g->adjlist[v1].firstedge=e1;
	}
	return g;
}
void print(graph *g)
{
	int i;
	edgenode *e;
	for(i=0;i<g->nv;i++)
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
void DFS(graph *g,int v)
{
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=1)
		{
			DFS(g,e->adjvex);
		}
	}
}
void BFS(graph *g,int v,qnode *q)
{
	visited[v]=-1;
	printf("%d->",g->adjlist[v].head);
	push(q,v);
	edgenode *e;
	while(!isempty(q))
	{
		v=pop(q);
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]==1)
			{
				printf("%d->",e->adjvex);
				visited[e->adjvex]=-1;
				push(q,e->adjvex);
			}
		}
	}
}
void unweight(int s,graph *g,qnode *q)
{
	dist[s]=0;
	push(q,s);
	edgenode *v;
	while(!isempty(q))
	{
		s=pop(q);
		v=g->adjlist[s].firstedge;
		for(;v!=NULL;v=v->next)
		{
			if(dist[v->adjvex]==-1)
			{
				dist[v->adjvex]=dist[s]+1;
				path[v->adjvex]=s;
				push(q,v->adjvex);
			}
		}
	}
}
void printway(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("dist:%d->",dist[i]);
	}
	printf("\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("path:%d->",path[i]);
	}
}
int main()
{
	graph *g=buildg();
	print(g);
	printf("DFS:");
	DFS(g,0);
	printf("\n");
	qnode *q=buildq();
	printf("BFS:");
	BFS(g,0,q);
	printf("\n");
	chushihua();
	unweight(0,g,q);
	printway(g);
}
