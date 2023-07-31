#include <Stdio.h>
#include <stdlib.h>
#define max 100 
#define wsweight 10

int visited[max]={0,};
int collect[max]={0,};
int dist[max]={0,};
int path[max]={0,};

int adj[max]={0,};
int low[max]={0,};
int parent[max]={0,};


typedef int vertex;
typedef struct edge{
	vertex adjvex;            //边 
	edge *next;				  //指向下一条边 
	int weight;				//权重 
}edgenode;

typedef struct vnode{
	vertex head;           //头节点 
	edgenode *firstedge;   //指向第一条边 
}Adjlist[max];

typedef struct {
	Adjlist adjlist;
	int nv,ne;                //边数，和节点数 
}graph;                      //图 

graph *buildg()
{
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=12;
	g->nv=8;
	int queue[max]={0,1,15,1,2,7,1,6,10,2,3,1,3,4,2,4,5,3,1,5,4,1,7,5,5,6,6,0,2,7,2,7,1,7,6,2,};
	int v1,v2,w;
	int front=0,rear=sizeof(queue)/sizeof(queue[0])-1;
	for(int i=0;i<g->nv;i++)
	{
		g->adjlist[i].head=i;
		g->adjlist[i].firstedge=NULL;
	}
	for(int i=0;i<g->ne;i++)
	{
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->adjvex=v1;
		e1->weight=w;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->adjvex=v2;
		e2->weight=w;
		e2->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e2;
		
		edgenode *e3=(edgenode *)malloc(sizeof(edgenode));
		e3->adjvex=v1;
		e3->weight=e1->weight;
		edgenode *e4=(edgenode *)malloc(sizeof(edgenode));
		e4->adjvex=v2;
		e4->weight=e2->weight;
		e4->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e4;
	}
	return g;
}
void Printg(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		e=g->adjlist[i].firstedge;
		for(;e!=NULL;e=e->next)
		{
			printf("E:%d(w%d)->",e->adjvex,e->weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int v)
{
	visited[g->adjlist[v].head]=1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=1)
		{
			DFS(g,e->adjvex);
		}
	}
}
void BFS(graph *g,int v)
{
	visited[g->adjlist[v].head]=-1;
	printf("%d->",g->adjlist[v].head);
	edgenode *e;
	int queue[max];
	int front=0,rear=0;
	queue[rear++]=g->adjlist[v].head;
	while(front!=rear)
	{
		v=queue[front++];
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]!=-1)
			{
				visited[e->adjvex]=-1;
				printf("%d->",e->adjvex);
				queue[rear++]=e->adjvex;
			}
		}
	}
}
void UNWAY(graph *g,int v)
{
	edgenode *e;
	dist[v]=0;
	path[v]=-1;
	visited[v]=8;
	int queue[max];
	int front=0,rear=0;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(visited[e->adjvex]!=8)
			{
				visited[e->adjvex]=8;
				dist[e->adjvex]=dist[v]+1;
				path[e->adjvex]=v;
				queue[rear++]=e->adjvex;
			}
		}
	}
}
void cshdj(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		if(i==0)
		{
			dist[i]=0;
			path[i]=-1;
		}else if(i==1)
		{
			dist[i]=15;
			path[i]=0;
		}else if(i==2)
		{
			dist[i]=7;
			path[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			path[i]=-1;
		}
	}
}
void PrintWay(graph *g)
{
	printf("the dist:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",path[i]);
	}
}
void Dijkstra(graph *g,int v)
{
	edgenode *e;
	int min;
	while(1)
	{
		min=INT_MAX;
		v=0;
		int i;
		for(i=0;i<g->nv;i++)
		{
			if(dist[i]<min&&collect[i]!=8)
			{
				min=dist[i];
				v=i;
			}
		}
		if(collect[v]==8)
		{
			break;
		}
		collect[v]=8;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(collect[e->adjvex]!=8)
			{
				if(dist[e->adjvex]>dist[v]+e->weight)
				{
					dist[e->adjvex]=dist[v]+e->weight;
					path[e->adjvex]=v;
				}
			}
		}
	}
}
void Printdj(graph *g)
{
	printf("dist:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",path[i]);
	}
}
void CSHprim(graph *g)     //初始化dist，和parent数组，dist用于收录，parent记录路径 
{
	for(int i=0;i<g->nv;i++)
	{
		if(i==0)
		{
			dist[i]=0;
			parent[i]=-1;
		}else if(i==1)
		{
			dist[i]=15;
			parent[i]=0;
		}else if(i==2)
		{
			dist[i]=7;
			parent[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			parent[i]=-8;
		}
	}
}
int FindMin(graph *g)
{
	int Mindist,v,Minv;
	Mindist=INT_MAX;
	for(v=0;v<g->nv;v++)
	{
		if(dist[v]!=0&&dist[v]<Mindist)
		{
			Mindist=dist[v];
			Minv=v;
		}
	}
	if(Mindist<INT_MAX)
	{
		return Minv;
	}else 
	{
		return -1;
	}
}


void Prim(graph *g,int v)
{
	edgenode *e;
	int min;
	parent[v]=-1;
	dist[v]=0;
	while(1)
	{
		v=FindMin(g);
		if(v==-1)
		{
			break;
		}
		dist[v]=0;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(dist[e->adjvex]!=0)
			{
				if(dist[e->adjvex]>dist[v]+e->weight)
				{
					dist[e->adjvex]=e->weight;
					parent[e->adjvex]=v;
				}
			}
		}
	}
}
void PrintPrim(graph *g)
{
	printf("\nthe prim,Dist[]:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nparent:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",parent[i]);
	}
}




int main()
{
	int v=0;
	graph *g=buildg();
	Printg(g);
	DFS(g,v);
	printf("\n");
	BFS(g,v);
	printf("\n");
	UNWAY(g,v);
	PrintWay(g);
	printf("\n");
	cshdj(g);
	Dijkstra(g,v);
	printf("Dijkstra:\n");
	Printdj(g);
	CSHprim(g);
	Prim(g,v);
	printf("\n");
	PrintPrim(g);
}









