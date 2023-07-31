#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define laozishiweight 8
#define maxsize 100
int visit[maxsize]={0,};
int visited[maxsize];
typedef int vertex;
typedef struct edge{
	vertex adjvex;
	struct edge *next;
	int weight;
}edgenode;
typedef struct vnode{
	vertex name;
	edgenode *firstedge;
}Adjlist[maxsize];

typedef struct{
	Adjlist adjlist;
	int nv,ne;
}graph;

typedef struct qnode{
	edgenode *data[maxsize];
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
graph *build()
{
	vertex v,w;
	int v1,v2;
	graph *lg=(graph *)malloc(sizeof(graph));
	lg->ne=5;
	lg->nv=6;
	for(v=0;v<lg->nv;v++)
	{
		lg->adjlist[v].firstedge=NULL;
		lg->adjlist[v].name=v;
	}
	for(w=0;w<lg->ne;w++)
	{
		printf("please input the v1 and v2:\n");
		scanf("%d %d",&v1,&v2);
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->adjvex=v1;
		e1->weight=laozishiweight;
		e1->next=lg->adjlist[v2].firstedge;
		lg->adjlist[v2].firstedge=e1;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->weight=laozishiweight;
		e2->adjvex=v2;
		e2->next=lg->adjlist[v1].firstedge;
		lg->adjlist[v1].firstedge=e2;
	}
	return lg;
}
qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}
void print(graph *lg)
{
	int i,j,k;
	edgenode *e;
	for(i=0;i<lg->nv;i++)
	{
		printf("H:%d->",lg->adjlist[i].name);
		e=lg->adjlist[i].firstedge;
		while(e!=NULL)
		{
			printf("E:%d(W:%d)",e->adjvex,e->weight);
			e=e->next;	
		}
		printf("\n");
	}
}
void Visit(int v)
{
	visit[v]=1;
}
void DFS(graph *lg,int v)
{
	Visit(v);
	edgenode *e;
	printf("DFS:%d->",lg->adjlist[v].name);
	for(e=lg->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visit[e->adjvex]!=1)
		{
			DFS(lg,e->adjvex);
		}
	}
}
void Visit2(int v)
{
	visit[v]=0;
}
void pushtree(qnode *q,edgenode *v)
{
	if(isfull(q))
	{
		printf("the queue is full;");
	}else 
	{
		q->data[q->rear]=v;
		q->rear++;
	}
}
void pop(qnode *q)
{
	q->data[q->front]=NULL;
	q->front++;
}

void BFS(graph *lg,int v,qnode *q)
{
	printf("%d->",lg->adjlist[v].name);
	visited[v]=1;
	edgenode *e;
	pushtree(q,lg->adjlist[v].firstedge);
	while(!isempty(q))
	{
		pop(q);
		e=lg->adjlist[v].firstedge;
		while(e)
		{
			if(!visited[e->adjvex])
			{
				printf("%d->",lg->adjlist[e->adjvex].name);
				visited[e->adjvex]=1;
				pushtree(q,e->next);
			}
			e=e->next;
		}
	}
}
void BFStraversal(graph *lg,qnode *q)
{
	for(int i=0;i<lg->nv;i++)
	{
		visited[i]=0;
	}
	for(int i=0;i<lg->nv;i++)
	{
		if(!visited[i])
		{
			BFS(lg,i,q);
		}
	}
}

int main()
{
	graph *lg=build();
	print(lg);
	DFS(lg,0);
	printf("\n------------------------------------------\n");
	qnode *q=buildq();
	BFStraversal(lg,q);
}
