#include <Stdio.h>
#include <stdlib.h>
#include <Stdbool.h>
#include <limits.h>
#define MAXSIZE 10
typedef struct g{
	int data[MAXSIZE][MAXSIZE];
	int nv,ne;
}graph;

graph* build()
{
	graph *g=(graph *)malloc(sizeof(graph));
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			if((i==2&&j!=2)||(j==2&&i!=2))
			{
				g->data[i][j]=i*j;
			}else 
			{
				g->data[i][j]=INT_MAX;
			}
		}
	}
	return g;
}
void PRINT(graph *g)
{
	for(int i=0;i<MAXSIZE;i++)
	{
		for(int j=0;j<MAXSIZE;j++)
		{
			if(g->data[i][j]==INT_MAX)
			{
				printf("*\t");
			}else 
			{
				printf("%d\t",g->data[i][j]);
			}
		}
		printf("\n");
	}
}
void BFS(graph *g,int visited[],int v)
{
	visited[v]
}


int main()
{
	int v=0;
	int visited[MAXSIZE];
	graph *g=build();
	PRINT(g);
	BFS(g,visited,v);
}
