#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define maxsize 100
typedef int vertex;

typedef struct edge{
	struct edge *next;
	int weight;
	vertex Adjvex;
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
	vertex data[maxsize];
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

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}
int push(qnode *q,vertex v)
{
	if(isfull(q))
	{
		printf("the queue is full!");
		return NULL;
	}
	q->data[q->rear]=v;
	q->rear++;
}

void insertq(qnode *q)
{
	vertex a[]={0,3,1,0,1,2,1,4,10,1,3,3,2,0,4,3,2,2,3,4,2,3,5,8,3,6,4,4,6,6,5,2,5,6,5,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		printf("Iam here1");
		push(q,a[i]);
	}
}

int pop(qnode *q)
{
	/*if(isempty(q))
	{
		printf("the queue is empty!");
		return NULL;
	}*/
	printf("\ntttttt");
		int tmp=q->data[q->front];
		q->front++;
		return tmp;
		
}

graph *buildg(qnode*q)
{
	vertex v,w;
	vertex v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=7;
	g->ne=12;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].head=v;
		g->adjlist[v].firstedge=NULL;
	}
	for(w=0;v<g->ne;w++)
	{
		v1=pop(q);
		v2=pop(q);
		v3=pop(q);
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->Adjvex=v2;
		e1->weight=v3;
		e1->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e1;
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
			printf("E:%d(W:%d)",e->Adjvex,e->weight);
			e=e->next;
		}
		printf("\n");
	}
}

int main()
{
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	printg(g);
	
	
}
