#include <stdio.h>
#include <Stdlib.h>
#define maxsize 8

typedef int vertex;
typedef struct d{
	int Graph[maxsize][maxsize];
	int data;
	int nv,ne;
}mgraph;

typedef struct enode{
	vertex v1,v2;
	int weight;
}edge;

mgraph *creat()
{
	vertex v,w;
	mgraph *mg=(mgraph *)malloc(sizeof(mgraph));
	mg->ne=0;
	mg->nv=7;
	for(v=0;v<maxsize;v++)
	{
		for(w=0;w<maxsize;w++)
		{
			if(v==2&&w!=2||v!=2&&w==2)
			{
				mg->Graph[v][w]=1;
			}else 
			{
				mg->Graph[v][w]=0;
			}
		}
	}
	return mg;
}
void insertedge(mgraph *mg,edge *e)
{
	mg->Graph[e->v1][e->v2]=e->weight;
	mg->Graph[e->v2][e->v1]=e->weight;
	mg->ne++;
}
void print(mgraph *mg)
{
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			printf("%d ",mg->Graph[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	mgraph *mg=creat();
	edge *e1=(edge *)malloc(sizeof(edge));
	e1->v1=2;e1->v2=5;e1->weight=8;
	insertedge(mg,e1);	
	print(mg);
} 
