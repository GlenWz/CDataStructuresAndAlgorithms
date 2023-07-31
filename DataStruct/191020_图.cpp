#include <Stdio.h>
#include <Stdlib.h>
#define MAX 8
typedef struct d{
	int data[MAX][MAX];
	int nv,ne;
	int head[MAX];
}graph;

int dist[MAX];
int parent[MAX];

int weight[MAX][MAX];
int path[MAX][MAX];


graph *buildG()
{
	int queue[]={0,1,1,1,2,4,1,4,2,1,7,3,1,3,1,2,4,1,2,5,1,3,5,3,3,6,2,6,7,1,};
	int v1,v2,w;
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=10;
	g->nv=8;
	for(int i=0;i<g->nv;i++)
	{
		for(int j=0;j<g->nv;j++)
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
		if(g->head[v1]==0)
		{
			g->head[v1]=1;
		}
		if(g->head[v2]==0)
		{
			g->head[v2]=1;
		}
		g->data[v2][v1]=w;
	}
	return g;
}
void DFS(graph *g,int v)
{
	printf("%d->",v);
	g->head[v]=2;
	for(int i=0;i<g->nv;i++)
	{
		if(g->data[v][i]!=0&&g->head[i]==1)
		{
			DFS(g,i);
		}
	}
}

void DFSER(graph *g)
{
	int v;
	for(int i=0;i<g->nv;i++)
	{
		if(g->head[i]==1)
		{
			DFS(g,i);
		}
	}
}

void BFS(graph *g,int v)
{
	int queue[MAX];
	int front=0,rear=0;
	queue[rear++]=v;
	g->head[v]=3;
	while(front!=rear)
	{
		v=queue[front++];
		printf("%d->",v);
		for(int i=0;i<g->nv;i++)
		{
			if(g->data[v][i]!=0&&g->head[i]==2)
			{
				g->head[i]=3;
				queue[rear++]=i;
			}
		}
	}
}
void CSHDJ(graph *g)
{
	for(int i=0;i<g->nv;i++)
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
int FindMin(graph *g)
{
	int MIN=INT_MAX,ret=-1;
	for(int i=0;i<g->nv;i++)
	{
		if(dist[i]<MIN&&g->head[i]!=4)
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
		v=FindMin(g);
		if(v==-1)
		{
			break;
		}
		g->head[v]=4;
		for(int i=0;i<g->nv;i++)
		{
			if(g->data[v][i]!=0)
			{
				if(g->data[v][i]+dist[v]<dist[i]&&g->head[i]!=4)
				{
					dist[i]=g->data[v][i]+dist[v];
					parent[i]=v;
				}
			}
		}		
	}
}
void PrintDJ(graph *g)
{
	printf("\nDIST:\n");
	for(int i=0;i<g->nv;i++)
	{
		printf("%d\t",dist[i]);
	}
	printf("\nParent:\n");
	for(int j=0;j<g->nv;j++)
	{
		printf("%d\t",parent[j]);
	}
}
int FindMinP(graph *g)
{
	int Min=INT_MAX;
	int ret=-1;
	for(int i=0;i<g->nv;i++)
	{
		if(g->head[i]==4&&dist[i]<Min)
		{
			Min=dist[i];
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
		for(int i=0;i<g->nv;i++)
		{
			if(g->head[i]==4&&g->data[v][i]!=0)
			{
				if(g->data[v][i]<dist[i])
				{
					dist[i]=g->data[v][i];
					parent[i]=v;
				}
			}
		}
	}
}
void CSHFloyed(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		for(int j=0;j<g->nv;j++)
		{
			if(g->data[i][j]==0)
			{
				weight[i][j]=INT_MAX;
			}else 
			{
				wight[i][j]=g->data[i][j];
			}
			path[i][j]=-1;
		}
	}
}

void Floyed(graph *g)
{
	for(k=0;k<MAX;k++)
	{
		for(int i=0;i<MAX;i++)
		{
			for(int j=0;j<MAX;j++)
			{
				if(weight[i][k]!=INT_MAX&&weight[k][j]!=INT_MAX&&weight[i][j]!=INT_MAX)
				{
					if(weight[i][k]+weight[k][j]<weight[i][j])
					{
						weight[i][j]=weight[i][k]+weight[k][j];
						path[i][j]=k;
						if(i==j&&weight[i][j<0])
						{
							return;
						}
					}
				}
			}
		}
	}
}



int main()
{
	int v=0;
	graph *g=buildG();
	printf("DFS:\n");
	DFSER(g);
	printf("\nBFS:\n");
	BFS(g,v);
	printf("\nDijkstra:\n");
	CSHDJ(g);
	Dijkstra(g,v);
	PrintDJ(g);
	printf("\nPrim:\n");
	CSHDJ(g);
	Prim(g,v);
	PrintDJ(g);
	printf("\nFloyed:\n");
	CSHFloyed(g);
	Floyed(g);
}











