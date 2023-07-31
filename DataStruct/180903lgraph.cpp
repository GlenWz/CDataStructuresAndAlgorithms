#include <Stdio.h>
#include <stdlib.h>
#define maxsize 100
#define laozishiweight 8
int visit[maxsize]={};
typedef int vertex;
typedef struct enode{
	vertex adjvet;
	struct enode *next;
	int weight;
}edgenode;

typedef struct vnode{
	vertex head;
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
		e1->weight=laozishiweight;
		e1->adjvet=v1;
		e1->next=lg->adjlist[v2].firstedge;
		lg->adjlist[v2].firstedge=e1;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->weight=laozishiweight;
		e2->adjvet=v2;
		e2->next=lg->adjlist[v1].firstedge;
		lg->adjlist[v1].firstedge=e2;
	}
	return lg;
}
void print(lgraph *lg)
{
	int i,j,k;
	edgenode *e;
	for(i=0;i<lg->nv;i++)
	{
		printf("H:%d->",lg->adjlist[i].head);
		e=lg->adjlist[i].firstedge;
		while(e!=NULL)
		{
			printf("V:%d(W:%d)",e->adjvet,e->weight);
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
	printf("DFS:%d ",lg->adjlist[v].head);
	for(e=lg->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visit[e->adjvet]==0)
		{
			DFS(lg,e->adjvet);
		}
	}
}


int main()
{
	lgraph *lg=build();
	print(lg);
	DFS(lg,0);
}
