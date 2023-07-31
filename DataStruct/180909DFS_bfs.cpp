#include <Stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define maxsize 100

typedef int vertex;
int visited[maxsize];
int dist[maxsize];
int path[maxsize];
int collected[maxsize];
typedef struct edge{
	struct edge *next;
	vertex adjvex;
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
	int data[maxsize];
	int front,rear;
}qnode;

qnode *buildq()
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}

void chushihua()
{
	for(int i=0;i<maxsize;i++)
	{
		dist[i]=-1;
		path[i]=-1;
		collected[i]=-1;
	}
}
void chushihuaDJ()
{
	for(int i=0;i<maxsize;i++)
	{	
		if(i==0)
		{
			dist[i]=0;
		}else if(i==1)
		{
			dist[i]=2;
			path[i]=0;
		}else if(i==3)
		{
			dist[i]=1;
			path[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
	}
}
bool isfull(qnode *q)
{
	if(q->rear==maxsize)
	{
		return 1;
	}else{
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
int push(int v,qnode *q)
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
		printf("the queue is empty!");
		return NULL;
	}
	return q->data[(q->front)++];
}
graph *buildg()
{
	vertex v,w;
	int v1,v2,Weight;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=7;
	g->ne=12;
	for(v=0;v<g->nv;v++)
	{
		g->adjlist[v].firstedge=NULL;
		g->adjlist[v].head=v;
	}
	for(w=0;w<g->ne;w++)
	{
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		printf("please input the V1 and V2 and weight:\n");
		scanf("%d%d%d",&v1,&v2,&Weight);
		e1->adjvex=v2;
		e1->weight=Weight;
		e1->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e1;
		/*edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->adjvex=v1;
		e2->weight=Weight;
		e2->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e2;*/                 //无向边加上这一句。 
	}
	return g;
}
void print(graph *g)
{
	int i;
	edgenode *e;
	for(i=0;i<g->nv;i++)
	{
		printf("H:%d->",i);              //i 改成g->asjlist[i].head 
		e=g->adjlist[i].firstedge;
		while(e!=NULL)
		{
			printf("E:%d(W:%d)",e->adjvex,e->weight);
			e=e->next;
		}
		printf("\n");
	}
}
void DFS(graph *g,int v)
{
	visited[v]=-1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=-1)
		{
			DFS(g,e->adjvex);
		}
	}
}
void BFS(graph *g,int v,qnode *q)
{
	visited[v]=1;
	edgenode *e;
	printf("%d->",g->adjlist[v].head);
	push(v,q);
	while(!isempty(q))
	{
		v=pop(q);
		e=g->adjlist[v].firstedge;
		while(e!=NULL)                    // 这里用for 和while 有什么区别？ 
		{
			if(visited[e->adjvex]==-1)
			{
				printf("%d->",e->adjvex);
				visited[e->adjvex]=1;
				push(e->adjvex,q);
			}
			e=e->next;
		}
	}
}
void unweight(int s,graph *g,qnode *q)
{
	dist[s]=0;
	push(s,q);
	edgenode *e;
	while(!isempty(q))
	{
		s=pop(q);
		e=g->adjlist[s].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(dist[e->adjvex]==-1)
			{
				dist[e->adjvex]=dist[s]+1;
				path[e->adjvex]=s;
				push(e->adjvex,q);
			}
		}
	}
}
void printss(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("%d  ",dist[i]);
	}
	printf("\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d  ",path[i]);
	}
	printf("\n");	
}
void Dijkstra(int v,graph *g)
{
	edgenode *e;
	int tmp;
	while(1)
	{
		e=g->adjlist[v].firstedge;
		v=e->adjvex;
		tmp=e->weight;
		for(;e!=NULL;e=e->next)     // 简单粗暴的O（V）   
		{                           //顶点过多的利用 最小二叉堆 O(log|V|) 
			if(e->weight<tmp)		//更新dist之后还要插入dist进堆，有点复杂 
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
				if((dist[e->adjvex]+e->weight)<dist[e->adjvex])
				{
					dist[e->adjvex]=e->weight+dist[v];
					path[e->adjvex]=v;
				}
			}
		}
	}
}
void printDJ(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		printf("%d  ",dist[i]);
	}
	printf("\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d  ",path[i]);
	}
}
int main()
{
	graph *g=buildg();
	print(g);
	printf("DFS:");
	DFS(g,0);
	printf("\n");
	qnode *q=buildq();
	printf("BFS:");
	BFS(g,0,q);
	printf("\n");
	chushihua();
	unweight(0,g,q);
	printss(g);
	chushihuaDJ();
	Dijkstra(0,g);
	printf("\nDJ:\n");
	printDJ(g);
}
