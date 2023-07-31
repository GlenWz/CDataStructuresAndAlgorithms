#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define MAXSIZE 9
typedef struct qnode{
	int data[MAXSIZE*MAXSIZE];
	int front,rear;
}qnode;

typedef struct j{
	int data[MAXSIZE][MAXSIZE];
	int nv,ne;
	int head[MAXSIZE];
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
		printf("the queue is empty");
		return NULL;
	}
	return q->data[q->front++];
}

void insertq(qnode *q)
{
	int a[]={0,1,2,1,2,1,1,3,3,2,4,2,2,5,5,4,8,3,5,8,2,1,6,4,1,7,1,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}
graph *buildg(qnode *q)
{
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=0;
	g->nv=0;
	int v1,v2,w;
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
			++g->nv;
		}
		if(g->head[v2]==0)
		{
			g->head[v2]=1;
			++g->nv;
		}
		g->data[v1][v2]=w;
		++g->ne;
	}
	return g;
}
void DFS(graph *g,int v)
{
	printf("%d->",v);
	g->head[v]=-1;
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->head[i]==1&&g->data[v][i]!=0)
		{
			DFS(g,i);
		}
	}
}

void DFSER(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->head[i]==1)
		{
			DFS(g,i);
		}
	}
}
void BFS(graph *g,qnode *q,int v)
{
	printf("%d->",v);
	g->head[v]=2;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->head[i]==-1&&g->data[v][i]!=0)
			{
				printf("%d->",i);
				push(q,i);
				g->head[i]=2;	
			}
		}
	}
}
void CS_unway(int dist[],int path[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		dist[i]=-1;
		path[i]=-1;
	}
}
void UNWAY(int dist[],int path[],qnode *q,int v,graph *g)
{
	dist[v]=0;
	push(q,v);
	g->head[v]=0;
	while(!isempty(q))
	{
		v=pop(q);
		for(int i=0;i<MAXSIZE;i++)
		{

			
				if(g->data[v][i]!=0&&dist[i]==-1&&g->head[i]!=0)
				{
					
					dist[i]=dist[v]+1;
					path[i]=v;
					g->head[i]=0;
					push(q,i);
				}
			
		}
	}
}
void print(int dist[],int path[])
{
	printf("\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("DIST:%d\tPATH:%d\n",dist[i],path[i]);
	}
}

int main()
{
	int dist[MAXSIZE];
	int path[MAXSIZE];
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	printf("the DFS:\n");
	DFSER(g);
	printf("\nthe BFS:\n");
	BFS(g,q,0);
	CS_unway(dist,path);
	UNWAY(dist,path,q,0,g);
	print(dist,path);
	
}

