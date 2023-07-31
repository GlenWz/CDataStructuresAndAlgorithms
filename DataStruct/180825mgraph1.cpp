#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 8
typedef int vertex;
typedef struct d{
	int Graph[maxsize][maxsize];
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
	mg->nv=0;
	for(v=0;v<maxsize;v++)
	{
		for(w=0;w<maxsize;w++)
		{
			if(v==2&&w!=0||v!=0&&w==2)
			{
				mg->Graph[v][w]=1;
				mg->nv++;
			}else 
			{
				mg->Graph[v][w]=0;
			}
		}
	}
	return mg;
}
void inserte(mgraph *mg,edge *e)
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
			printf("%d  ",mg->Graph[i][j]);
		}
		printf("\n");
	}
}


int main()
{
	mgraph *s=creat();
	edge *a=(edge *)malloc(sizeof(edge));
	a->v1=2;a->v2=5;a->weight=8;
	inserte(s,a);
	print(s);
}
