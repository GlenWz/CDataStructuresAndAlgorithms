#include <Stdio.h>
#include <Stdlib.h>
#include <stdbool.h>
#define maxsize 100
typedef int vertex;
typedef struct edge{
	vertex adjvex;
	struct edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	vertex head;
}Adjlist[maxsize];

typedef struct {
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
void push(qnode *q,int v)
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
int  pop(qnode *q )
{
	if(isempty(q))
	{
		printf("the queue is empty!");
	}else 
	{
		return q->data[(q->front)++];
	}
}

void insertQ(qnode *q)
{
	int a[maxsize]={0,1,1,0,2,2,1,5,4,1,3,5,2,4,3,3,6,7,4,3,2,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);
	}
}
graph *buildg(qnode *q)
{
	vertex v,w;
	int v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=7;
	g->nv=7;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].firstedge=NULL;
		g->adjlist[v].head=v;
	}
	for(w=0;w<g->ne;w++)
	{
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		v1=pop(q);
		v2=pop(q);
		v3=pop(q);
		e->adjvex=v2;
		e->weight=v3;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
	}
	return g;
}
void printg(graph *g)
{
	edgenode  *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		for(e=g->adjlist[i].firstedge;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)",e->adjvex,e->weight);
		}
		printf("\n");
	}
}

void DFS(graph *g,int visited[],vertex v)
{
	visited[v]=1;
	edgenode *e;
	printf("%d->",g->adjlist[v].head);
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=1)
		{
			DFS(g,visited,e->adjvex);
		}
	}
}
void BFS_CS(int visited[])
{
	for(int i=0;i<maxsize;i++)
	{
		visited[i]=-1;
	}
}
void BFS(graph *g,qnode *q,vertex v,int visited[])
{
	visited[v]=1;
	edgenode *e;
	printf("%d->",g->adjlist[v].head);
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]!=1)
			{
				visited[e->adjvex]=1;
				printf("%d->",e->adjvex);
				push(q,e->adjvex);
			}
		}
	}
}
void UNWAY(graph *g,qnode *q,int dist[],int path[],vertex v)
{
	dist[v]=0;
	edgenode *e;
	push(q,v);
	while(!isempty(q))
	{
		v=pop(q);
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(dist[e->adjvex]==-1)
			{
				dist[e->adjvex]=dist[v]+1;
				path[e->adjvex]=v;
				push(q,e->adjvex);
			}
		}
	}
}
void CS_UNWAY(int dist[],int path[])
{
	for(int i=0;i<maxsize;i++)
	{
		dist[i]=-1;
		path[i]=-1;
	}
}

void printway(int dist[],int path[],graph *g)
{
	printf("\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("Path:%d\n",path[i]);
	}
	
}
void DJ_CS(int dist[],int parent[],int collected[])
{
	for(int i=0;i<maxsize;i++)
	{
		if(i==0)
		{
			dist[i]=0;
			parent[i]=-1;
		}else if(i==1)
		{
			dist[i]=1;
			parent[i]=0;
		}else if(i==2)
		{
			dist[i]=2;
			parent[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			parent[i]=-1;
		}
		collected[i]=-1;
		//parent[i]=-1;
	}
}

void Dijkstra(graph *g,int dist[],int parent[],vertex v,int collected[])
{	
	int tmp;
	edgenode *e;
	while(1)
	{	
		e=g->adjlist[v].firstedge;
		tmp=e->weight;
		v=e->adjvex;
		for(;e!=NULL;e=e->next)
		{
			if(e->weight<tmp)
			{
				tmp=e->weight;
				v=e->adjvex;
			}
		}
		if(v==NULL)
		{
			break;
		}
		collected[v]=1;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collected[e->adjvex]==-1)
			{
				if(dist[e->adjvex]+e->weight<dist[e->adjvex])
				{
					dist[e->adjvex]=dist[v]+e->weight;
					parent[e->adjvex]=v;
				//	v=g->adjlist[v].firstedge->adjvex;
				}
			}	
		}
	}	
}
void printDJ(int dist[],int parent[],graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("PART:%d\n",parent[i]);
	}
}

int main()
{
	int visited[maxsize];
	int dist[maxsize];
	int path[maxsize];
	int parent[maxsize];
	int collected[maxsize];
	vertex v=0;
	
	qnode *q=buildq();
	insertQ(q);
	graph *g=buildg(q);
	printg(g);
	printf("\nDFS:\n");
	DFS(g,visited,v);
	BFS_CS(visited);
	printf("\nBFS:\n");
	BFS(g,q,v,visited);
	CS_UNWAY(dist,path);
	UNWAY(g,q,dist,path,v);
	printway(dist,path,g);
	DJ_CS(dist,parent,collected);
	Dijkstra(g,dist,parent,v,collected);
	printDJ(dist,parent,g);
}
