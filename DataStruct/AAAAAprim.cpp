#include <Stdio.h>
#include <Stdlib.h>
#define max 100

int Visited[max]={0,};
int Dist[max]={0,};
int Path[max]={0,};
int Parent[max]={0,};
int collected[max]={0,};

typedef int vertex;
typedef struct edge{
	vertex adjtex;
	int weight;
	edge *next;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	vertex head;
}Adjlist[max];

typedef struct{
	Adjlist adjlist;
	int nv,ne;
}graph;

graph *buildg()
{
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=12;
	g->nv=7;
	int queue[max]={1,2,2,1,3,4,1,4,1,2,4,3,2,5,10,3,4,2,3,6,5,4,5,7,4,6,8,4,7,4,5,7,6,6,7,1,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0])-1;
	int v1,v2,w;
	for(int v=0;v<=g->nv;v++)
	{
		g->adjlist[v].head=v;
		g->adjlist[v].firstedge=NULL;
	}
	for(int i=0;i<g->ne;i++)
	{
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->adjtex=v1;
		e1->weight=w;
		e1->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e1;
		
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->adjtex=v2;
		e2->weight=w;
		e2->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e2;
	}
	return g;
}
void PrintG(graph *g)
{
	edgenode *e;
	for(int i=1;i<=g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		e=g->adjlist[i].firstedge;
		for(;e!=NULL;e=e->next)
		{
			printf("E:%d(W:%d)->",e->adjtex,e->weight);
		}
		printf("\n");
	}
}
void DFS(graph *g,int v)
{
	Visited[v]=1;
	printf("%d->",v);
	edgenode *e;
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(Visited[e->adjtex]!=1)
		{
			DFS(g,e->adjtex);
		}
	}
}
void BFS(graph *g,int v)
{
	edgenode *e;
	Visited[v]=8;
	printf("%d->",v);
	int queue[max];
	int front=0,rear=0;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(Visited[e->adjtex]!=8)
			{
				Visited[e->adjtex]=8;
				printf("%d->",e->adjtex);
				queue[rear++]=e->adjtex;
			}
		}
	}
}
void Unway(graph *g,int v)
{
	Dist[v]=0;
	Path[v]=-1;
	edgenode *e;
	int queue[max];
	int front=0,rear=0;
	Visited[v]=5;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(Visited[e->adjtex]!=5)
			{
				Visited[e->adjtex]=5;
				Dist[e->adjtex]=Dist[v]+1;
				Path[e->adjtex]=v;
				queue[rear++]=e->adjtex;
			}
		}
	}
}

void PrintWay(graph *g)
{
	printf("The Dist:\n");
	for(int i=1;i<=g->nv;i++)
	{
		printf("%d\t",Dist[i]);
	}
	printf("\nThe Path:\n");
	for(int i=1;i<=g->nv;i++)
	{
		printf("%d\t",Path[i]);
	}
	printf("\n");
}
void CSHDJ(graph *g)
{
	for(int i=1;i<g->nv;i++)
	{
		if(i==2)
		{
			Dist[i]=2;
			Path[i]=1;
		}else if(i==3)
		{
			Dist[i]=4;
			Path[i]=1;
		}else if(i==4)
		{
			Dist[i]=1;
			Path[i]=1;
		}else 
		{
			Dist[i]=INT_MAX;
			Path[i]=-1;
		}
	}
}

int FindMinDJ(graph *g)
{
	int MinV,v,Mind;
	Mind=INT_MAX;
	for(v=1;v<=g->nv;v++)
	{
		if(Dist[v]<Mind&&collected[v]!=1)
		{
			Mind=Dist[v];
			MinV=v;
		}
	}
	if(Mind<INT_MAX)
	{
		return MinV;
	}else 
	{
		return -1;
	}
}

void Dijkstra(graph *g,int v)
{
	int min;
	Dist[v]=0;
	Path[v]=-1;
	edgenode *e;
	while(1)
	{
	//	v=FindMinDJ(g);
		min=INT_MAX;
		v=1;
		for(int i=1;i<=g->nv;i++)
		{
			if(Dist[i]<min&&collected[i]!=1)
			{
				min=Dist[i];
				v=i;
			}
		}
		if(collected[v]==1)
		{
			break;
		}
		collected[v]=1;
		
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			
			if(collected[e->adjtex]!=1)
			{
				if(Dist[e->adjtex]>Dist[v]+e->adjtex)
				{
					Dist[e->adjtex]=Dist[v]+e->weight;
					Path[e->adjtex]=v;
				
				}
			}
		}
		
	}
}
void PrintDJ(graph *g)
{
	printf("DIJKSTRA:\n");
	for(int i=1;i<=g->nv;i++)
	{
		printf("%d\t",Dist[i]);
	}
	printf("\n");
	for(int i=1;i<=g->nv;i++)
	{
		printf("%d\t",Path[i]);
	}
	printf("\n");
}




void CSHPrim(graph *g)
{
	for(int i=1;i<=g->nv;i++)
	{
		if(i==2)
		{
			Dist[i]=2;
			Parent[i]=1;
		}else if(i==3)
		{
			Dist[i]=4;
			Parent[i]=1;
		}else if(i==4)
		{
			Dist[i]=1;
			Parent[i]=1;
		}else 
		{
			Dist[i]=INT_MAX;
			Parent[i]=-1;
		}
	}
}
int FindMin(graph *g)
{
	int MinV,v,Mindist;
	Mindist=INT_MAX;
	for(v=1;v<=g->nv;v++)
	{
		if(Dist[v]!=0&&Dist[v]<Mindist)
		{
			Mindist=Dist[v];
			MinV=v;
		}
	}
	if(Mindist<INT_MAX)
	{
		return MinV;
	}else 
	{
		return -1;
	}
}

void Prim(graph *g,int v)
{
	edgenode *e;
	Dist[v]=0;
	Parent[v]=-1;
	while(1)
	{
		v=FindMin(g);
		printf("*****%d****\n",v);	
		if(v==-1)
		{
			break;
		}
		Dist[v]=0;
		for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
		{
			if(Dist[e->adjtex]!=0&&Dist[e->adjtex]>(Dist[v]+e->weight))
			{
				if(e->weight<Dist[e->adjtex])
				{
					Dist[e->adjtex]=e->weight;
					Parent[e->adjtex]=v;
				}
			}
		}
	}	
}
void PrintPrim(graph *g)
{
	printf("The Prim:\n");
	for(int i=1;i<=g->nv;i++)
	{
		printf("%d\t",Dist[i]);
	}
	printf("\nThe Parent:\n");
	for(int i=1;i<=g->nv;i++)
	{
		printf("%d\t",Parent[i]);
	}
	printf("\n");
}

int main()
{
	int v=1;
	graph *g=buildg();
	PrintG(g);
	DFS(g,v);
	printf("\n");
	BFS(g,v);
	printf("\n");
	Unway(g,v);
	PrintWay(g);
	CSHDJ(g);
	Dijkstra(g,v);
	PrintDJ(g);
	CSHPrim(g);
	Prim(g,v);
	PrintPrim(g);
}





