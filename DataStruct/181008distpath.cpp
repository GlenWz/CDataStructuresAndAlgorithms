#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define MAXSIZE 9
typedef struct qnode{
	int data[MAXSIZE*MAXSIZE];
	int front,rear;
}qnode;

typedef struct g{
	int Data[MAXSIZE][MAXSIZE];
	int nv,ne;
	int vnode[MAXSIZE];
}graph;

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}

bool isempty(qnode *q) //队列是否为空 
{
	return q->front==q->rear;
}
bool isfull(qnode *q) //队列是否满了 
{
	return q->rear==MAXSIZE*MAXSIZE;
}

int push(qnode *q ,int v)//入队 
{
	if(isfull(q))
	{
		printf("the queue is full!\n");
		return NULL;
	}
	q->data[q->rear]=v;
	q->rear++;
}
int pop(qnode *q)//出队 
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
	//这里是采用数组来存储节点和权重 ，数组入队。数组以v1，v2，weight存储 
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
	g->nv=0;
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			g->Data[i][j]=0;
		}
		g->vnode[i]=0;
	}
	while(!isempty(q))
	{
		v1=pop(q);
		v2=pop(q);
		w=pop(q);
		if(g->vnode[v1]==0)
		{
			g->vnode[v1]=1;
			++g->nv;
		}
		if(g->vnode[v2]==0)
		{
			g->vnode[v2]=1;
			++g->nv;
		}
		g->Data[v1][v2]=w;
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
			printf("%d  ",g->Data[i][j]);
		}
		printf("\n");
	}
}
void DFS(graph *g,int v)
{
	g->vnode[v]=-1;
	printf("%d->",v);
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->Data[v][i]!=0&&g->vnode[i]!=0)
		{
			DFS(g,i);
		}
	}
}

void DFSER(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->vnode[i]==1)
		{
			DFS(g,i);
		}
	}
}
void BFS(graph *g,qnode *q,int v)
{
	g->vnode[v]=2;
	push(q,v);
	printf("%d->",v);
	while(!isempty(q)){
		v=pop(q);
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->vnode[i]==-1&&g->Data[v][i]!=0)
			{
				printf("%d->",i);
				push(q,i);
				g->vnode[i]=2;
			}
		}
	}
}

void CS_WAY(int path[],int dist[])
{
	for(int i=0;i<MAXSIZE;i++)
	{
		path[i]=-1;
		dist[i]=-1;
	}
	
}

void UNWAY(graph *g,int path[],int dist[],int v,qnode *q)
{
	dist[v]=0;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->Data[v][i]!=0&&g->vnode[i]!=0)
			{
				dist[i]=dist[v]+1;
				path[i]=v;
				push(q,i);
				g->vnode[i]=0;
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
	
}


int main()
{
	int path[MAXSIZE];
	int dist[MAXSIZE];
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);
	print(g);
	printf("DFS:\n");
	DFSER(g);
	printf("\nBFS:\n");
	BFS(g,q,1);
	CS_WAY(path,dist);
	UNWAY(g,path,dist,1,q);
	printway(dist,path);
}
