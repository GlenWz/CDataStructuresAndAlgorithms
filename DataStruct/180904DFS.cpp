#include <Stdio.h>
#include <stdlib.h>
#define maxsize 100
#define laozishiweight 8
int visit[maxsize]={};
typedef int vertex;
typedef struct enode{
	vertex adjtex;
	struct enode *next;
	int weight;
}edgenode;
typedef struct vnode{
	edgenode *firstedge;
	vertex head;
}Adjlist[maxsize];
typedef struct {
	Adjlist adjlist;
	int nv,ne;
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
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		printf("please input the v1 and v2");
		scanf("%d %d",&v1,&v2);
		e1->adjtex=v1;
		e1->weight=laozishiweight;
		e1->next=lg->adjlist[v2].firstedge;
		lg->adjlist[v2].firstedge=e1;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->adjtex=v2;
		e2->next=lg->adjlist[v1].firstedge;
		e2->weight=laozishiweight;
		lg->adjlist[v1].firstedge=e2;
	}
	return lg;
}
void print(lgraph *lg)
{
	int i,k,j;
	edgenode *e;
	printf("the Graph is :\n");
	for(int i=0;i<lg->nv;i++)
	{
		printf("H:%d->",lg->adjlist[i].head);
		e=lg->adjlist[i].firstedge;
		while(e!=NULL)
		{
			printf("E:%d(W:%d)",e->adjtex,e->weight);
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
	for(e=lg->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(visit[e->adjtex]==0)
		{
			DFS(lg,e->adjtex);
		}
	}
}



int main()
{
	lgraph *lg=build();
	print(lg);
	DFS(lg,0);
}
