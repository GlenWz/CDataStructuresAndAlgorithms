#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 9
typedef int vertex;
typedef struct g{
	int data[MAXSIZE][MAXSIZE];
	int nv,ne;
}graph;

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
		printf("the queue  is full!\n");
		return NULL;
	}
	q->data[q->rear]=v;
	q->rear++;
}
int pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue  is empty!");
		return NULL;
	}
	return q->data[q->front++];
}

void insertq(qnode *q)
{
	int a[]={1,2,1,1,3,3,2,4,2,2,5,5,4,8,3,5,8,2,3,6,4,3,7,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}

graph *buildg(qnode *q)
{
	int v1,v2,w;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=8;
	g->nv=MAXSIZE;
	for(int i=0;i<g->nv;i++)
	{
		for(int j=0;j<g->nv;j++)
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
	}
	return g;
}
void DFSER(int visited[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		visited[i]=0;
	}
}
/*int find(graph *g,int v)
{
	int ret=-1;
	for(int i=0;i<g->nv;i++)
	{
		if(g->data[v][i]!=0)
		{
			ret=i;
			return ret;
		}
	}
}*/


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


int main()
{
	int visited[MAXSIZE];	
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	print(g);
	DFSER(visited);
	DFS(g,visited,1);
}
