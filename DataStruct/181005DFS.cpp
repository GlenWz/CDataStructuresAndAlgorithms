#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 9
typedef struct j{
	int data[MAXSIZE][MAXSIZE];
	int nv,ne;
	int head[MAXSIZE];
}graph;

typedef struct qnode{
	int data[MAXSIZE*MAXSIZE];
	int front,rear;
}qnode;

void DFS(graph *g,int visited[],int v);

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
	//int a[]={0,1,2,1,2,2,1,3,1,2,3,3,3,4,2,3,5,1,2,0,3,-1};
//	int a[]={0,3,1,0,2,1,3,2,4,3,7,3,7,0,2,3,4,2,3,5,1,5,6,5,-1};
	int a[]={1,2,2,1,3,3,2,5,4,3,5,2,5,7,2,5,4,3,-1};
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
	g->nv=6;
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
		if(g->head[v1]==0)
		{
			g->head[v1]=1;
		}else if(g->head[v2]==0)
		{
			g->head[v2]=1;
		}
		g->data[v1][v2]=w;
		++g->nv;
	}
	return g;
}
void CS_vi(int visited[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		visited[i]=0;
	}
}/*
void DFSer(graph *g,int visited[])
{
	int v;
	for(v=0;v<MAXSIZE;++v)
	{
		if(v==0)
		{
			DFS(g,visited,v);
		}
	}
}
int Firstadj(graph *g,int v)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->data[v][i]!=0&&i!=v)
		{
			return i;
		}
	}
	return -1;
}
int Nextad(graph *g,int v,int visited[],int w)
{
	int i;
	for(i=w+1;i<MAXSIZE;i++)
	{
		if(g->data[v][i]!=0&&i!=v)
		{
			return i;
		}
	}
	return -1;
}

void DFS(graph *g,int visited[],int v)
{
	int w;
	visited[v]=1;
	printf("%d->",v);
	for(w=Firstadj(g,v);v>=0;w=Nextad(g,v,visited,w))
	{
		if(visited[w]==0)
		{
			DFS(g,visited,w);
		}
	}
}*/
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

void DFS(graph *g,int visited[],int v)
{
	int j;
	visited[v]=1;
	if(g->head[v]!=0)
	{
		printf("%d->",v);
		g->head[v]=0;
	}
	for(int j=0;j<MAXSIZE;j++)
	{
		if(g->data[v][j]!=0&&visited[j]==0)
		{
			DFS(g,visited,j);
		}
	}
}
void DFSer(graph *g,int visited[])
{
	int i;
	for(i=0;i<MAXSIZE;i++)
	{
		if(visited[i]==0)
		{
			DFS(g,visited,i);
		}
	}
}

int main()
{
	int visited[MAXSIZE];
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	CS_vi(visited);
	print(g);
	DFSer(g,visited);
}
