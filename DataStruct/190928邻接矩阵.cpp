#include <stdio.h>
#include <Stdlib.h>
#define MAXSIZE 8

typedef struct g{
	int data[MAXSIZE][MAXSIZE];
	int nv,ne;
	int Vnode[MAXSIZE];
}graph;

int parent[MAXSIZE];
int dist[MAXSIZE];




void DFS(graph *g,int v);
graph *buildG()
{
	int a[]={0,1,1,1,2,4,1,4,2,2,4,1,2,5,1,1,3,1,1,7,3,3,5,3,3,6,2,6,7,1,};
	int lena=sizeof(a)/sizeof(a[0]);
	int n=0;
	
	graph *g=(graph *)malloc(sizeof(graph));
	int v1,v2,w;
	g->ne=0;
	g->nv=0;
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			g->data[i][j]=0;
		}
		g->Vnode[i]=0;
	}
	for(int i=0;i<lena;i+=3)
	{
		v1=a[n++];
		v2=a[n++];
		w=a[n++];
		if(n==lena-1)
		{
			break;
		}
		if(g->Vnode[v1]==0)
		{
			g->Vnode[v1]=1;
			++g->nv;
		}
		if(g->Vnode[v2]==0)
		{
			g->Vnode[v2]=1;
			++g->nv;
		}
		g->data[v1][v2]=w;
		g->data[v2][v1]=w;
		++g->ne;
	}
	return g;
}
void PrintG(graph *g)
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

void DFSer(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->Vnode[i]==1)
		{
			DFS(g,i);
		}
	}
}


void DFS(graph *g,int v)
{
	g->Vnode[v]=-1;
	printf("%d->",v);
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->Vnode[i]==1&&g->data[v][i]!=0)
		{
			DFS(g,i);
		}
	}
}
void BFS(graph *g,int v)
{
	g->Vnode[v]=2;
	int queue[MAXSIZE];
	int front=0,rear=0;
	queue[rear++]=v;
	printf("%d->",v);
	while(front!=rear)
	{
		v=queue[front++];
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->Vnode[i]==-1&&g->data[v][i]!=0)
			{
				queue[rear++]=i;
				printf("%d->",i);
				g->Vnode[i]=2;
			}
		}
	}
}
void CSway(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(i==0)
		{
			dist[i]=0;
			parent[i]=-1;
		}else 
		{
			dist[i]=INT_MAX;
			parent[i]=-1;
		}
	}
}

void Unway(graph *g,int v)
{
	g->Vnode[v]=3;
	int queue[MAXSIZE];
	int front=0,rear=0;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->Vnode[i]==2&&g->data[v][i]!=0)
			{
				g->Vnode[i]=3;
				dist[i]=dist[v]+1;
				parent[i]=v;
				queue[rear++]=i;
			}
		}
	}
}

void PrintWay(graph *g)
{
	printf("\nthe dist:\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		if(dist[i]==INT_MAX)
		{
			printf("*  ");
		}else 
		{
			printf("%d\t",dist[i]);
		}
	}
	printf("\nthe parent:\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("%d\t",parent[i]);
	}
}

void CSHdj(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(i==0)
		{
			dist[i]=0;
			parent[i]=-1;
		}else if(i==1)
		{
			dist[i]=1;
			parent[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			parent[i]=-1;
		}
	}
}

int FindMINdj(graph *g)
{
	int MIN=INT_MAX,ret=-1;
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->Vnode[i]==3&&dist[i]<MIN)
		{
			MIN=dist[i];
			ret=i;
		}
	}
	return ret;
}

void DijkstraG(graph *g,int v)
{
	while(1)
	{
		v=FindMINdj(g);
		if(v==-1)
		{
			break;
		}
		g->Vnode[v]=4;
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->Vnode[i]==3&&g->data[v][i]!=0)
			{
				if(dist[i]>dist[v]+g->data[v][i])
				{
					dist[i]=dist[v]+g->data[v][i];
					parent[i]=v;
				}
			}
		}
	}
}

void PrintDJ(graph *g)
{
	printf("\nDIST:\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nParent:\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("%d\t",parent[i]);
	}
}
void CSHPrim(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(i==0)
		{
			dist[i]=0;
			parent[i]=-1;
		}else if(i==1)
		{
			dist[i]=1;
			parent[i]=0;
		}else 
		{
			dist[i]=INT_MAX;
			parent[i]=-1;
		}
	}
}

int FindMinPrim(graph *g)
{
	int MIN=INT_MAX,ret=-1;
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->Vnode[i]==4&&dist[i]<MIN)
		{
			MIN=dist[i];
			ret=i;
		}
	}
	return ret;
}

void Prim(graph *g,int v)
{
	while(1)
	{
		v=FindMinPrim(g);
		if(v==-1)
		{
			break;
		}	
		g->Vnode[v]=5;
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->Vnode[i]==4&&g->data[v][i]!=0)
			{
				if(dist[i]>g->data[v][i])
				{
					dist[i]=g->data[v][i];
					parent[i]=v;
				}
			}
		}	
	}
}
void PrintPri(graph *g)
{
	printf("\nDist:\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nparent:\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		printf("%d\t",parent[i]);
	}
	printf("\n");
}







int main()
{
	int v=0;
	graph *g=buildG();
	PrintG(g);
	printf("\nDFS:\n");
	DFSer(g);
	printf("\nBFS:\n");
	BFS(g,v);
	CSway(g);
	Unway(g,v);
	PrintWay(g);
	printf("\nDijkstra:\n");
	CSHdj(g);
	DijkstraG(g,v);
	PrintDJ(g);
	printf("\nPrim:\n");
	CSHPrim(g);
	Prim(g,v);
	PrintPri(g);
	printf("\nFloyerd:\n");
	Floyed(g);
}






