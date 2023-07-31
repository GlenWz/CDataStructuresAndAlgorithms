#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 8

typedef struct d{
	int data[MAXSIZE][MAXSIZE];
	int head[MAXSIZE];
	int nv,ne;
}graph;

int dist[MAXSIZE];
int parent[MAXSIZE];

int weight[MAXSIZE][MAXSIZE];
int path[MAXSIZE][MAXSIZE];




graph *buildG()
{
	int queue[]={0,1,1,1,2,4,1,4,2,1,7,3,1,3,1,2,4,1,2,5,1,3,5,3,3,6,2,6,7,1,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
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
	while(front!=rear)
	{
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		g->data[v1][v2]=w;
		g->data[v2][v1]=w;
		++g->ne;
		++g->nv;
		g->head[v1]=1;
		g->head[v2]=1;	
	}
	return g;
}

void DFS(graph *g,int v)
{
	g->head[v]=-1;
	printf("%d->",v);
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->data[v][i]!=0&&g->head[i]==1)
		{
			DFS(g,i);
		}
	}
}

void DFSer(graph *g)
{
	
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->head[i]==1)
		{
			DFS(g,i);
		}
	}
}

void BFS(graph *g,int v)
{
	int queue[MAXSIZE];
	int front=0,rear=0;
	queue[rear++]=v;
	printf("%d->",v);
	g->head[v]=2;
	while(front!=rear)
	{
		v=queue[front++];
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->data[v][i]!=0&&g->head[i]==-1)
			{
				printf("%d->",i);
				g->head[i]=2;
				queue[rear++]=i;
			}
		}
	}
}

void CSHway(graph *g)
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

void UnweightWay(graph *g,int v)
{
	int queue[MAXSIZE];
	int front=0,rear=0;
	queue[rear++]=v;
	g->head[v]=3;
	while(front!=rear)
	{
		v=queue[front++];
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->data[v][i]!=0&&g->head[i]==2)
			{
				g->head[i]=3;
				dist[i]=dist[v]+1;
				parent[i]=v;
				queue[rear++]=i;
			}
		}
	}
}

void PrintWay(graph *g)
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
int FindMinDJ(graph *g)
{
	int MIN=INT_MAX,ret=-1;
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->head[i]==3&&dist[i]<MIN)
		{
			MIN=dist[i];
			ret=i;
		}
	}
	return ret;
}

void Dijkstra(graph *g,int v)
{
	while(1)
	{
		v=FindMinDJ(g);
		if(v==-1)
		{
			break;
		}
		g->head[v]=4;
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->head[i]==3&&g->data[v][i]!=0)
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
void CSHDJ(graph *g)
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
int FindMinP(graph *g)
{
	int MIN=INT_MAX,ret=-1;
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->head[i]==4&&dist[i]<MIN)
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
		v=FindMinP(g);
		if(v==-1)
		{
			break;
		}
		g->head[v]=5;
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->data[v][i]!=0&&g->head[i]==4)
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
void PrintG(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			printf("%d   ",g->data[i][j]);
		}
		printf("\n");
	}
}

void CSHfloyed()
{
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			weight[i][j]=INT_MAX;
			path[i][j]=INT_MAX;
		}
	}
}
bool Floyed(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			if(g->data[i][j]==0)
			{
				weight[i][j]=INT_MAX;
			}else 
			{
				weight[i][j]=g->data[i][j];
			}
			path[i][j]=-1;
		}
	}
	for(int k=0;k<MAXSIZE;k++)
	{
		for(int i=0;i<MAXSIZE;i++)
		{
			for(int j=0;j<MAXSIZE;j++)
			{
				if(weight[i][k]!=INT_MAX&&weight[k][j]!=INT_MAX&&weight[i][j]!=INT_MAX)   //要加上这一句判断，不然越界了咋办? 
				{
						if(weight[i][k]+weight[k][j]<weight[i][j])
					{
						weight[i][j]=weight[i][k]+weight[k][j];
						path[i][j]=k;
						if(i==j&&weight[i][j]<0)
						{
							return 0;
						}
					}
				}
			}
		}
	}
	return 1;
}
void PrintFloyed(graph *g)
{
	printf("\nweight:\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			if(weight[i][j]==INT_MAX)
			{
				printf("***\t");
			}else 
			{
				printf("%d\t",weight[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n*****************\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			printf("%d\t",path[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	graph *g=buildG();
	PrintG(g);
	printf("邻接矩阵DFS:\n");
	DFSer(g);
	printf("\n邻接矩阵BFS:\n");
	int v=0;
	BFS(g,v);
	printf("\n无权路:\n");
	CSHway(g);
	UnweightWay(g,v);
	PrintWay(g);
	printf("\nDijkstra:\n");
	CSHDJ(g);
	Dijkstra(g,v);
	PrintDJ(g);
	printf("\nPrim:\n");
	CSHPrim(g);
	Prim(g,v);
	PrintPri(g);
	printf("\nFloyed:\n");
	CSHfloyed();
	bool Ret=Floyed(g);
	PrintFloyed(g);
}












