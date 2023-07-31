#include <Stdio.h>
#include <stdlib.h>
#define maxsize 100
#define laozishiweight 8
typedef int vertex;

typedef struct node{
	vertex adjvex;
	struct node *next;
	int weight;
}edgenode;

typedef struct vnode{
	vertex head;
	edgenode *firstedge;
}Adjlist[maxsize];

typedef struct {
	Adjlist adjilist;
	int ne,nv;
}lgraph;

lgraph *build()
{
	vertex v,w;
	int v1,v2,k;
	lgraph *lg=(lgraph *)malloc(sizeof(lgraph));
	lg->ne=3;
	lg->nv=3;
	for(v=0;v<lg->nv;v++)
	{
		lg->adjilist[v].head=v;
		lg->adjilist[v].firstedge=NULL;
	}
	for(w=0;w<lg->ne;w++)
	{
		printf("please input the V1 and V2:\n ");
		scanf("%d %d",&v1,&v2);
		edgenode *s=(edgenode *)malloc(sizeof(edgenode));
		s->adjvex=v1;
		s->weight=laozishiweight;
		s->next=lg->adjilist[v2].firstedge;
		lg->adjilist[v2].firstedge=s;
		edgenode *e=(edgenode *)malloc(sizeof(edgenode));
		e->adjvex=v2;
		e->next=lg->adjilist[v1].firstedge;
		lg->adjilist[v1].firstedge=e;
		e->weight=laozishiweight;
	}
	return lg;
}
void print(lgraph *lg)
{
	int i,k,j;
	edgenode *e;
	printf("the graph is:\n");
	for(int i=0;i<lg->ne;i++)
	{
		printf("Head:%d->",lg->adjilist[i].head);
		e=lg->adjilist[i].firstedge;
		while(e!=NULL)
		{
			printf("E:%d(W:%d)",e->adjvex,e->weight);
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
