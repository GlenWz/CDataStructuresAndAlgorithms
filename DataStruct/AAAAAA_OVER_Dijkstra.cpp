#include <Stdio.h>
#include <stdlib.h>

#define max 100
int visited[max]={0,};
int collect[max]={0,};
int dist[max]={0,};
int path[max]={0,};



typedef int vertex;
typedef struct edge{
	vertex adjvex;
	struct edge *next;
	int weight;
}edgenode;
typedef struct vnode{
	vertex head;
	edgenode *firstedge;
}Adjlist[max];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

graph *buildg()
{
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=12;
	g->nv=8;
	int queue[max]={0,1,15,1,2,7,1,6,10,2,3,1,3,4,2,4,5,3,1,5,4,1,7,5,5,6,6,0,2,7,2,7,1,7,6,2,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0])-1;
	int v1,v2,w;
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
void PrintG(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		e=g->adjlist[i].firstedge;
		for(;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)->",e->adjvex,e->weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int v)
{
	edgenode *e;
	visited[g->adjlist[v].head]=1;
	printf("%d->",g->adjlist[v].head);
	e=g->adjlist[v].firstedge;
	for(;e!=NULL;e=e->next)
	{
		if(visited[e->adjvex]!=1)
		{
			DFS(g,e->adjvex);
		}
	}
}
void BFS(graph *g,int v)
{
	int queue[max];
	int front=0,rear=0;
	edgenode *e;
	visited[g->adjlist[v].head]=-1;
	printf("%d->",g->adjlist[v].head);
	queue[rear++]=g->adjlist[v].head;
	while(front!=rear)
	{
		v=queue[front++];
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(collect[e->adjvex]!=-1)
			{
				collect[e->adjvex]=-1;
				printf("%d->",e->adjvex);
				queue[rear++]=e->adjvex;
			}
		}
	}
}
void Unway(graph *g,int v)
{
	edgenode *e;
	dist[v]=0;
	path[v]=-1;
	visited[g->adjlist[v].head]=8;
	int queue[max];
	int front=0,rear=0;
	queue[rear++]=g->adjlist[v].head;
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
void PrintW(graph *g)
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
void CSHDJ(graph *g)
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
void Dijkstra(graph *g,int v)
{
	edgenode *e;
	int min;
	while(1)
	{
		v=0;
		min=INT_MAX;
		int i;
		for(i=0;i<g->nv;i++)
		{
			if(collect[i]!=8&&dist[i]<min)
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
	printf("the dist:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\n");
	for(int j=0;j<g->nv;j++)
	{
		printf("%d\t",path[j]);
	}
}



int main()
{
	graph *g=buildg();
	PrintG(g);
	int v=0;
	DFS(g,v);
	printf("\n");
	BFS(g,v);
	printf("\n");
	Unway(g,v);
	PrintW(g);
	printf("\n");
	CSHDJ(g);
	Dijkstra(g,v);
	printf("\n");
	Printdj(g);
}






