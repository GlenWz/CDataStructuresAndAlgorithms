#include <Stdio.h>
#include <Stdlib.h>
#define MAXSIZE 8

typedef struct g{
	int data[MAXSIZE][MAXSIZE];
	int nv,ne;
	int Head[MAXSIZE];
}graph;

int visited[MAXSIZE]={0};
int dist[MAXSIZE];
int parent[MAXSIZE];
//floyed
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
		g->Head[i]=0;
	}
	while(front!=rear)
	{
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		g->data[v1][v2]=w;
		g->ne++;
		g->data[v2][v1]=w;
		g->ne++;
		if(g->Head[v1]==0)
		{
			++g->nv;
			g->Head[v1]=1;
		}
		if(g->Head[v2]==0)
		{
			++g->nv;
			g->Head[v2]=1;
		}
	}
	return g;
}
void PrintG(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			printf("%d\t",g->data[i][j]);
		}
		printf("\n");
	}
}

void DFS(graph *g,int v)
{
	printf("%d->",v);
	g->Head[v]=2;
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->data[v][i]!=0&&g->Head[i]==1)
		{
			DFS(g,i);
		}
	}
}
void DFSER(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		if(g->Head[i]==1)
		{
			DFS(g,i);
		}
	}	
}
void BFS(graph *g,int v)
{
	int queue[MAXSIZE];
	int front=0,rear=0;
	printf("%d->",v);
	g->Head[v]=3;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->data[v][i]!=0&&g->Head[i]==2)
			{
				printf("%d->",i);
				g->Head[i]=3;
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
void Unway(graph *g,int v)
{
	int queue[MAXSIZE];
	int front=0,rear=0;
	queue[rear++]=v;
	g->Head[v]=4;
	while(front!=rear)
	{
		v=queue[front++];
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->Head[i]==3&&g->data[v][i]!=0)
			{
				g->Head[i]=4;
				dist[i]=dist[v]+1;
				parent[i]=v;
				queue[rear++]=i;
			}
		}
	}
}
void PrintW(graph *g)
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
int FindMinDJ(graph *g)
{
	int MIN=INT_MAX,ret=-1;
	for(int i=0;i<MAXSIZE;i++)
	{
		if(dist[i]<MIN&&g->Head[i]==4)
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
		g->Head[v]=5;
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->Head[i]==4&&g->data[v][i]!=0)
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
void CSHP(graph *g)
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
		if(dist[i]<MIN&&g->Head[i]==5)
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
		g->Head[v]=6;
		for(int i=0;i<MAXSIZE;i++)
		{
			if(g->Head[i]==5&&g->data[v][i]!=0)
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
void CSHfloyed(graph *g)
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
}

int Floyed(graph *g)
{	
	for(int k=0;k<MAXSIZE;k++)
	{
		for(int i=0;i<MAXSIZE;i++)
		{
			for(int j=0;j<MAXSIZE;j++)
			{
				if(weight[i][k]!=INT_MAX&&weight[k][j]!=INT_MAX&&weight[i][j]!=INT_MAX)
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
}
void PrintFloy(graph *g)
{
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
	printf("\n********************************\n");
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			printf("%d\t",path[i][j]);
		}
		printf("\n");
	}
}






int main()
{
	graph *g=buildG();
	PrintG(g);
	int v=0;
	printf("DFS:\n");
	DFSER(g);
	printf("\nBFS:\n");
	BFS(g,v);
	printf("\nUNweightWay:\n");
	CSHway(g);
	Unway(g,v);
	PrintW(g);
	printf("\nDijkstra:\n");
	CSHdj(g);
	Dijkstra(g,v);
	PrintW(g);
	printf("\nPrim:\n");
	CSHP(g);
	Prim(g,v);
	PrintW(g);
	printf("\nFloyed:\n");
	printf("\n\n");
	CSHfloyed(g);
	Floyed(g);
	PrintFloy(g);
	
}
























