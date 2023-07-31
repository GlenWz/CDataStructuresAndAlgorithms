#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define MAXSIZE 9

typedef struct qnode{
	int data[MAXSIZE*MAXSIZE];
	int front,rear;
}qnode;

typedef struct g{
	int data[MAXSIZE][MAXSIZE];
	int nv,ne;
	int HEAD[MAXSIZE];
}graph;

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}
bool isfull(qnode *q)
{
	return q->rear==MAXSIZE*MAXSIZE;
}
bool isempty(qnode *q)
{
	return q->front==q->rear;
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
	int a[]={0,1,2,1,5,1,1,3,2,1,2,3,3,4,1,3,6,5,5,4,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}
graph *buildg(qnode *q)
{
	int v1,v2,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=0;
	g->nv=0;
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			g->data[i][j]=0;
		}
		g->HEAD[i]=0;
	}
	while(!isempty(q))
	{
		v1=pop(q);
		v2=pop(q);
		w=pop(q);
		if(g->HEAD[v1]==0)
		{
			g->HEAD[v1]=1;
			++g->nv;
		}
		if(g->HEAD[v2]==0)
		{
			g->HEAD[v2]=1;
			++g->nv;
		}
		g->data[v1][v2]=w;
		++g->ne;
	}
	return g;
}
void DFS(graph *g,int v)
{
	g->HEAD[v]=-1;
	printf("%d->",v);
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->data[v][i]!=0&&g->HEAD[i]==1)
		{
			DFS(g,i);
		}
	}
}

void DFSER(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->HEAD[i]==1)
		{
			DFS(g,i);
		}
	}
}
void BFS(graph *g,qnode *q,int v)
{
	g->HEAD[v]=2;
	printf("%d->",v);
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->HEAD[i]==-1&&g->data[v][i]!=0)
			{
				printf("%d->",i);
				g->HEAD[i]==2;
				push(q,i);
			}
		}
	}
}



int main()
{
	
	
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	DFSER(g);
	BFS(g,q,0);
	
	
}

