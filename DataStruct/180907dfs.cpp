#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxsize 100
#define laozishiweight 8
int visit[maxsize]={0,};
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
	edgenode *data[maxsize]; 
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
graph *buildg()
{
	vertex v,w;
	int v1,v2;
	graph *lg=(graph *)malloc(sizeof(graph));
	lg->ne=14;
	lg->nv=9;
	for(v=0;v<lg->nv;v++)
	{
		lg->adjlist[v].head=v;
		lg->adjlist[v].firstedge=NULL;
	}
	for(w=0;w<lg->ne;w++)
	{
		printf("please input the v1 and v2:\n");
		scanf("%d %d",&v1,&v2);
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->adjvex=v1;
		e1->next=lg->adjlist[v2].firstedge;
		e1->weight=laozishiweight+w;
		lg->adjlist[v2].firstedge=e1;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->adjvex=v2;
		e2->weight=laozishiweight+w;
		e2->next=lg->adjlist[v1].firstedge;
		lg->adjlist[v1].firstedge=e2;
	}
	return lg;
}
void print(graph *lg)
{
	int i;
	edgenode *e;
	printf("the graph is :\n");
	for(i=0;i<lg->nv;i++)
	{
		printf("HEAD:%d->",lg->adjlist[i].head);
		e=lg->adjlist[i].firstedge;
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
	visit[v]=1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visit[e->adjvex]!=1)
		{
			DFS(g,e->adjvex);
		}
	}
}
edgenode *popedge(qnode *q)
{
	edgenode *ret;
	if(isempty(q))
	{
		printf("the queue is empty!");
		return NULL;
	}
	ret=q->data[q->front];
	q->data[q->front]=NULL;
	q->front++;
	return ret;
}

int pushedge(edgenode *e,qnode *q)
{
	if(isfull(q))
	{
		printf("the queue is full!");
		return NULL;
	}
	q->data[q->rear]=e;
	q->rear++;
}
void BFS(graph *lg,int v,qnode *q)
{
	visit[v]=0;
	printf("%d->",lg->adjlist[v].head);
	edgenode *e;
	if(lg!=NULL)
	{
		pushedge(lg->adjlist[v].firstedge,q);
	}
	
	while(isempty(q))
	{
		e=popedge(q);
		if(visit[e->adjvex]!=0)
		{
			visit[e->adjvex]=0;
			printf("%d->",e->adjvex);
			pushedge(e->next,q);
		}
	}
}
void BFSS(graph *g,int v,qnode *q)
{
	for(int i=0;i<g->nv;i++)
	{
		if(visit[i]==1)
		{
			BFS(g,i,q);
		}
	}
}







int main()
{
	graph *g=buildg();
	print(g);
	DFS(g,5);
	printf("\n");
	qnode *q=buildq();
	BFSS(g,5,q);
}
