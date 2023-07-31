#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct d{
	int data[MAX][MAX];
	int nv,ne;
	int head[MAX];
}graph;

void DFS(graph *g,int v,int visited[]);


graph *buildg(int a[])
{
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=8;
	g->nv=7;
	for(int i=0;i<g->nv;i++)
	{
		for(int j=0;j<g->nv;j++)
		{
			g->data[i][j]=0;
		}
		g->head[i]=0;
	}
	int n1,n2,w;
	int n=0;
	for(int i=0;i<g->ne;i++)
	{
		n1=a[n++];
		n2=a[n++];
		w=a[n++];
		g->data[n1][n2]=w;
		g->data[n2][n1]=w;
		g->head[n1]=1;
		g->head[n2]=1;
	}
	return g;
}
void PrintG(graph *g)
{
	for(int i=0;i<g->nv;i++)
	{
		for(int j=0;j<g->nv;j++)
		{
			printf("%d  ",g->data[i][j]);
		}
		printf("\n");
	}
}
void DFSER(graph *g,int visited[])
{
	for(int i=0;i<g->nv;i++)
	{
		
		if(visited[i]==1&&g->head[i]==1)
		{
			DFS(g,i,visited);
		}
	}
}

void DFS(graph *g,int v,int visited[])
{
	int j;
	visited[v]=0;
	printf("%d->",v);
	for(j=0;j<g->nv;j++)
	{
		if(g->data[v][j]!=0&&(visited[v]!=0&&g->head[j]!=0))
		{
			DFS(g,j,visited);
			DFSER(g,visited);
		}
	}
}

int main()
{
	int a[]={0,2,1,0,6,2,1,2,2,1,4,1,2,5,1,2,6,2,4,5,3,5,6,1,};
	int v=0;
	graph *g=buildg(a);
	PrintG(g);
	printf("\nDFS:\n");
	int visited[MAX];
	for(int i=0;i<g->nv;i++)
	{
		visited[i]=1;
	}
	DFS(g,v,visited); 
	printf("\nBFS:\n");
	
}







