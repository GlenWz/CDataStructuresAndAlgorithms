#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAXSIZE 9

typedef struct  G{
	int Data[MAXSIZE][MAXSIZE];
	int nv,ne;
	int Vnode[MAXSIZE];
}graph;

typedef struct qnode{
	int Data[MAXSIZE*MAXSIZE];
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
	return q->front==q->rear;
}
bool isfull(qnode *q)
{
	return q->rear==MAXSIZE*MAXSIZE;
}
int push(qnode *q,int v)
{
	if(isfull(q))
	{
		printf("the queue is full!\n");
		return NULL;
	}
	q->Data[q->rear]=v;
	q->rear++;
}
int pop(qnode *q)
{
	if(isempty(q))
	{
		printf("the queue is empty!");
		return NULL;
	}
	return q->Data[q->front++];
}

void insertq(qnode *q)
{
	int a[]={1,3,1,3,6,2,3,4,3,3,5,4,5,8,5,4,7,6,-1};
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
	g->nv=9;
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			g->Data[i][j]=0;
		}
		g->Vnode[i]=0;
	}
	while(!isempty(q))
	{
		v1=pop(q);
		v2=pop(q);
		w=pop(q);
		g->Data[v1][v2]=w;
		if(g->Vnode[v1]==0)
		{
			g->Vnode[v1]=1;
		}
		if(g->Vnode[v2]==0)
		{
			g->Vnode[v2]=1;
		}
		++g->ne;
	}
	return g;
}
void DFS(graph *g,int v)
{
	printf("%d->",v);
	g->Vnode[v]=-1;
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->Data[v][i]!=0&&g->Vnode[i]==1)
		{
			DFS(g,i);
		}
	}
}

void DFSER(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->Vnode[i]==1)
		{
			DFS(g,i);
		}
	}
}
void BFS(graph *g,int v,qnode *q)
{
	g->Vnode[v]=2;
	printf("%d->",v);
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->Vnode[i]==-1&&g->Data[v][i]!=0)
			{
				push(q,i);
				printf("%d->",i);
				g->Vnode[i]=2;			
			}
		}
	}
}
void CS_WAY(int dist[],int path[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		dist[i]=-1;
		path[i]=-1;
	}
}
void UNWAY(graph *g,qnode *q,int v,int dist[],int path[])
{
	dist[v]=0;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(int i=0;i<MAXSIZE;i++)
		{
			if(dist[i]==-1&&g->Data[v][i]!=0)
			{
				dist[i]=dist[v]+1;
				path[i]=v;
				push(q,i);
			}
		}
	}
}
void printway(int dist[],int path[])
{
	printf("\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("DIST:%d\tPATH:%d\n",dist[i],path[i]);
	}
	
}/*
void CS_DJ(int dist[],int path[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(i==1)
		{
			dist[i]=0;
			path[i]=-1;
		}else if(i==3)
		{
			dist[i]=1;
			path[i]=1;			
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
	}
}*/

void Dijkstra(int dist[],int path[],qnode *q,graph *g,int v)
{
	while(1)
	{
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->Vnode[i]!=0)
			{
				dist[i]=g->Data[v][i];
				path[i]=v;
			}
		}
		g->Vnode[v]=8;
		
	}
	
	
}


int main()
{
	int dist[MAXSIZE];
	int path[MAXSIZE];
	qnode *q=buildq();
	insertq(q);	
	graph *g=buildg(q);
	printf("\nDFS:\n");
	DFSER(g);
	printf("\nBFS:\n");
	BFS(g,1,q);
	CS_WAY(dist,path);
	UNWAY(g,q,1,dist,path);
	printway(dist,path);
//	CS_DJ(dist,path);
	Dijkstra(dist,path,q,g,1);
	
	
	
	
}
