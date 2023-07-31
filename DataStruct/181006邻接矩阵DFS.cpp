#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define MAXSIZE 9

typedef struct j{
	int data[MAXSIZE][MAXSIZE];
	int NV,NE;
	int head[MAXSIZE];
}graph;

typedef struct qnode{
	int data[MAXSIZE*MAXSIZE];
	int front,rear;
}qnode;
void DFSer(graph *g);
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
	return q->rear==MAXSIZE*MAXSIZE;
}

int push(qnode *q ,int v)
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
		printf("the queue is empty!\n");
		return NULL;
	}
	return q->data[q->front++];
}
void insertq(qnode *q)
{
	int a[]={1,3,1,3,6,2,3,4,3,3,5,4,5,8,5,4,7,6,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}

graph *buildgraph(qnode *q)
{
	int v1,v2,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->NV=0;
	g->NE=0;
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			g->data[i][j]=0;
		}
		g->head[i]=0;
	}
	while(!isempty(q))
	{
		v1=pop(q);
		v2=pop(q);
		w=pop(q);
		g->data[v1][v2]=w;
		if(g->head[v1]==0)
		{
			++g->NV;
			g->head[v1]=1;
		}else if(g->head[v2]==0)
		{
			g->head[v2]=1;
			++g->NV;	
		}
		++g->NE;
	}
	return g;
}




void DFS(graph *g,int v)
{
	int j;
	g->head[v]=0;
	printf("%d->",v);
	for(j=0;j<MAXSIZE;j++)
	{
		if(g->data[v][j]!=0&&g->head[j]!=0)
		{
			DFS(g,j);
			DFSer(g);
		}
	}
}

void DFSer(graph *g)
{
	
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->head[i]==1)
		{
			DFS(g,i);
		}
	}
}
void print(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			printf("%d  ",g->data[i][j]);
		}
		printf("\n");
	}
}



int main()
{
	qnode *q=buildq();
	insertq(q);	
	graph *g=buildgraph(q);
	print(g);
	DFSer(g);
	
}

