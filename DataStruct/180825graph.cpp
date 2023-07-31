#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 10
typedef int vertex;
typedef struct d{
	int Grph[10][10];
	int nv,ne;         //v is vert and e is edge
	int data;        //vert's value;
}mgraph;

typedef struct enode{
	vertex v1,v2;
	int weight;
}edge;

mgraph *initiative()
{
	vertex v,w;       
	mgraph *mg=(mgraph *)malloc(sizeof(mgraph));
	mg->ne=0;
	mg->nv=9;
	for(v=0;v<maxsize;v++)
	{
		for(w=0;w<maxsize;w++)
		{
			if(w==2&&v!=2||v==2&&w!=2)
			{
				mg->Grph[v][w]=1;
			}else
			{
				mg->Grph[v][w]=0;
			}
		}
	}
	return mg;
}

void print(mgraph *mg)
{
	for(int i=0;i<maxsize;i++)
	{
		for(int j=0;j<maxsize;j++)
		{
			printf("%d  ",mg->Grph[i][j]);
		}
		printf("\n");
	}
}
void insertedge(mgraph *mg,edge *e)      //无向图，插入两遍，有向图，就v1，v2就行了 
{
	mg->Grph[e->v1][e->v2]=e->weight;
	mg->Grph[e->v2][e->v1]=e->weight;
}



int main()
{
	mgraph *mg=initiative();
	edge *e1=(edge *)malloc(sizeof(edge));
	e1->v1=2;e1->v2=5;e1->weight=8;
	insertedge(mg,e1);
	print(mg);
}
