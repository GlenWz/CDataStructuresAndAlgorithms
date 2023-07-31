#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxsize 100
#define laozishiweight 8
int visit[maxsize];
typedef int vertex;
typedef struct edge{
	vertex adjvert;
	struct edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	edgenode *firstedge;
	vertex head;
}Adjlist[maxsize];

typedef struct {
	int nv,ne;
	Adjlist adjlist;
}lgraph;

lgraph *build()
{
	vertex v,w;
	vertex v1,v2;
	lgraph *lg=(lgraph *)malloc(sizeof(lgraph));
	lg->ne=5;
	lg->nv=6;
	for(v=0;v<lg->nv;v++)
	{
		lg->adjlist[v].firstedge=NULL;
		lg->adjlist[v].head=v;
	}
	for(w=0;w<lg->ne;w++)
	{
		printf("please input the V1 and V2:\n");
		scanf("%d %d",&v1,&v2);
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		e1->adjvert=v1;
		e1->weight=laozishiweight;
		e1->next=lg->adjlist[v2].firstedge;
		lg->adjlist[v2].firstedge=e1;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->adjvert=v2;
		e2->weight=laozishiweight;
		e2->next=lg->adjlist[v1].firstedge;
		lg->adjlist[v1].firstedge=e2;
	}
	return lg;
}
void print(lgraph *lg)
{
	int i,k,j;
	edgenode *e;
	for(i=0;i<lg->nv;i++)
	{
		printf("Head:%d->",lg->adjlist[i].head);
		e=lg->adjlist[i].firstedge;
		while(e!=NULL)
		{
			printf("E:%d(W:%d)",e->adjvert,e->weight);
			e=e->next;
		}
		printf("\n");
	}
}
void Visit(int v)
{
	visit[v]=1;
}

void DFS(lgraph *lg,int v)
{
	edgenode *e;
	Visit(v);
	printf("DFS:%d",lg->adjlist[v].head);
	for(e=lg->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visit[e->adjvert]!=1)
		{
			DFS(lg,e->adjvert);
		}
	}
}


int main()
{
	lgraph *lg=build();
	print(lg);
	DFS(lg,0);
}
