#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
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

typedef struct{
	Adjlist adjlist;
	int nv,ne;
}graph;                          //图 采用领接表存储 

typedef struct qnode{
	vertex data[maxsize];
	int front,rear;	
}qnode;                         //队列用于存放图的初始化v1,v2和weight 

qnode *buildq()                //队列初始化 
{
	qnode *q=(qnode *)malloc(sizeof(qnode));
	q->front=q->rear=0;
	return q;
}
bool isfull(qnode *q)        //判断队列是否为满的 
{
	return q->rear==maxsize;
}
bool isempty(qnode *q)       //判断队列是否为空 
{
	return q->front==q->rear;
}
void CS_unway(int dist[],int path[]) //无权路，dist初始化，dist用于存放起点V到 
{                            //顶点X的无权距离 
	for(int i=0;i<maxsize;i++)      //path用于存放来源结点 
	{
		path[i]=-1;
		dist[i]=-1;
	}
}
void CS_DJ(int dist[],int path[],int collected[])
{							//Dijkstra算法所需的dist，path，collected数组，
	//path存放来源结点，dist存放从起点V到N的距离权重，collected用于 顶点是否被访问 
	for(int i=0;i<maxsize;i++)
	{
		collected[i]=-1;
		if(i==0)
		{
			dist[i]=0;
		}else if(i==1)
		{
			dist[i]=3;
			path[i]=0;
		}else if(i==2)
		{
			dist[i]=2;
			path[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
		
	}
}

int push(qnode *q,int v)     //进队操作 
{
	if(isfull(q))
	{
		printf("the queue is full!");
		return false;
	}else 
	{
		q->data[q->rear]=v;
		q->rear++;
	}
}
int pop(qnode *q)        //出队操作 
{
	if(isempty(q))
	{
		printf("the queue is empty!");
		return false;
	}else
	{
		return q->data[(q->front)++];
	}
}

void insertq(qnode *q)
{	//a数组存放的是5个顶点，6条边 ，0、1、3|表示边0->1，权重为3 
	int a[]={0,1,3,0,2,2,1,4,1,1,3,3,2,3,3,3,4,2,-1};
	for(int i=0;a[i]!=-1;i++)
	{
		push(q,a[i]);   //进队 
	}
}
graph *buildg(qnode *q)
{	//图的初始化 
	vertex v,w;
	int v1,v2,v3;
	graph *g=(graph *)malloc(sizeof(graph));
	g->nv=5;
	g->ne=6;
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
		v3=pop(q);   //权重出队 
		e->adjvex=v2;
		e->weight=v3;
		e->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e;
	}
	return g;
}
void printg(graph *g)   //打印邻接表 
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		e=g->adjlist[i].firstedge;
		for(;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)",e->adjvex,e->weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int visited[],vertex v)  //DFS算法 
{
	visited[v]=-1;
	edgenode *e;
	printf("%d->",g->adjlist[v].head);
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=-1)
		{
			DFS(g,visited,e->adjvex);
		}
	}
}
void BFS(graph *g,int visited[],vertex v,qnode *q) //bfs算法 
{
	visited[v]=1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
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
void Unway(graph *g,int dist[],int path[],vertex v,qnode *q)
{		//无权路 
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
void printway(graph *g,int dist[],int path[])
{	//最短路径打印 
	for(int i=0;i<g->nv;i++)
	{
		printf("DIST:%d\t",dist[i]);
		printf("PATH:%d\n",path[i]);
	}
}
void Dijkstra(graph *g,int dist[],int path[],int collected[],vertex v,qnode *q)
{	//dijkstra 算法的实现，问题接在这里！！找了很久都不知道哪里错了 
	int min;      //最小值 
	while(1)
	{
		edgenode *e;  
		e=g->adjlist[v].firstedge;
		min=e->weight;
		v=e->adjvex;
		for(;e!=NULL;e=e->next)  //未收录顶点中距离最小者 
		{
			if(e->weight<min)
			{
				min=e->weight;
				v=e->adjvex;
			}
		}
		if(v==NULL)
		{
			break;
		}
		collected[v]=1;     //收录进去 
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collected[e->adjvex]==-1)
			{
				if(dist[v]+e->weight<dist[e->adjvex])
				{
					dist[e->adjvex]=dist[v]+e->weight;
					path[e->adjvex]=v;
					
				}
			}
		}
	}
}

int main()
{
	int visited[maxsize];
	int dist[maxsize];
	int path[maxsize];
	int collected[maxsize];
	
	vertex v=0;
	qnode *q=buildq();
	insertq(q);
	graph *g=buildg(q);	
	printg(g);
	
	printf("\nDFS:\n");
	DFS(g,visited,v);
	printf("\nBFS:\n");
	BFS(g,visited,v,q);
	
	CS_unway(dist,path);    //初始化dist，path 
	Unway(g,dist,path,v,q);
	printf("\nUNWAY:\n");
	printway(g,dist,path);
	
	CS_DJ(dist,path,collected);
	printf("\nDijkstra:\n");
	Dijkstra(g,dist,path,collected,v,q);
	printway(g,dist,path);
	
}
