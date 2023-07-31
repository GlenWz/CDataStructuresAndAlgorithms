#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
#define laozishiweight 8
typedef int vertex;
typedef struct edge{
	vertex adjtex;
	struct edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	vertex vert;
	edgenode *firstedge;
}Adjlist[maxsize];

typedef struct {
	Adjlist adjlist;
	int ne,nv;
}lgraph;

lgraph *build()
{
	vertex v,w;
	int v1,v2;
	lgraph *lg=(lgraph *)malloc(sizeof(lgraph));
	lg->ne=3;
	lg->nv=3;
	for(v=0;v<lg->ne;v++)
	{
		lg->adjlist[v].vert=v;
		lg->adjlist[v].firstedge=NULL;
	}
	for(w=0;w<lg->ne;w++)
	{
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		printf("please input the v1 and v2\n");
		scanf("%d %d",&v1,&v2);
		e1->adjtex=v1;
		e1->weight=laozishiweight;
		e1->next=lg->adjlist[v2].firstedge;
		lg->adjlist[v2].firstedge=e1;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->adjtex=v2;
		e2->weight=laozishiweight;
		e2->next=lg->adjlist[v1].firstedge;
		lg->adjlist[v1].firstedge=e2;
	}
	return lg;
}
void print(lgraph *lg)
{
	int i,k,j;
	printf("the lgraph is :\n");
	for(i=0;i<lg->nv;i++)
	{
		printf("head:%d->",lg->adjlist[i].vert);
		edgenode *e=lg->adjlist[i].firstedge;
		while(e!=NULL)
		{
			printf("E:%d(W:%d)",e->adjtex,e->weight);
			e=e->next;
		}
		printf("\n");
	}
}

int main()
{
	lgraph *lg=build();
	print(lg);
}
