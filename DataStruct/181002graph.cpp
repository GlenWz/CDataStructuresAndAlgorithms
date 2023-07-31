#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXSIZE 8
typedef int vertex;
typedef struct {
	int data[MAXSIZE][MAXSIZE];
	int weight;
	int nv,ne;
}graph;
typedef struct edge{
	
	int weight;
};

typedef struct qnode{
	int data[MAXSIZE*MAXSIZE];
	int front,rear;
}qnode;

bool isfull(qnode *q)
{
	return q->rear==MAXSIZE*MAXSIZE;
}
bool isempty(qnode *q)
{
	return q->front==q->rear;
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
		printf("the queue is empty!\n");
		return NULL;
	}
	return q->data[q->front++];
}
void insertq(qnode *q)
{
	int a[]={0,7,1,0,1,2,1,3,5,1,4,4,3,2,3,4,2,4,2,5,2,-1};
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
	g->nv=8;
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			g->data[i][j]=0;
		}
	}
	while(!isempty(q))
	{
		v1=pop(q);
		v2=pop(q);
		w=pop(q);
		g->data[v1][v2]=w;
		++g->ne;
	}
	return g;
}
void print(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			printf("%d\t",g->data[i][j]);
		}
		printf("\n");
	}
}


void DFS(graph *g,int visited[],int v)
{
	visited[v]=1;
	printf("%d->",v);
	for(int i=0;i<g->nv;i++)
	{
		if(visited[i]!=1&&g->data[v][i]!=0)
		{
			DFS(g,visited,i);
		}
	}
}
void DFSer(graph *g,int visited[])
{
	vertex v;
	for(v=0;v<g->nv;v++)
	{
		visited[v]=0;
	}
	
}


int main()
{
	vertex v=0;
	int visited[MAXSIZE];
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	print(g);
	DFSer(g,visited);
	DFS(g,visited,v);
}

