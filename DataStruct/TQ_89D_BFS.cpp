#include <Stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct edge{
	int data;
	struct edge *next;
	int weight;
}edgenode;

typedef struct vnode{
	int head;
	edgenode *firstedge;
}Adjlist[MAX];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}graph;

int visited[MAX]={0,};


graph *buildg()
{
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=10;
	g->nv=8;
	int v1,v2,w;
	int queue[]={0,1,1,1,2,4,1,4,2,1,7,3,1,3,1,2,4,1,2,5,1,3,5,3,3,6,2,6,7,1,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	for(int i=0;i<g->nv;i++)
	{
		g->adjlist[i].head=i;
		g->adjlist[i].firstedge=NULL;
	}
	for(int i=0;i<g->ne;i++)
	{
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		e1->data=v2;
		e1->weight=w;
		e1->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e1;
		edgenode *e2=(edgenode *)malloc(sizeof(edgenode));
		e2->data=v1;
		e2->weight=w;
		e2->next=g->adjlist[v2].firstedge;
		g->adjlist[v2].firstedge=e2;
	}
	return g;
}
void Printg(graph *g)
{
	edgenode *e;
	for(int i=0;i<g->nv;i++)
	{
		printf("H:%d->",g->adjlist[i].head);
		for(e=g->adjlist[i].firstedge;e;e=e->next)
		{
			printf("E:%d(W:%d)->",e->data,e->weight);
		}
		printf("\n");
	}
}

void D_BFS(graph *g,int v)
{
	int stack[MAX];
	int top=0;
	edgenode *e;
	stack[top++]=v;
	visited[v]=1;
	while(top!=0)
	{
		v=stack[--top];
		printf("%d->",g->adjlist[v].head);
		for(e=g->adjlist[v].firstedge;e;e=e->next)
		{
			if(visited[e->data]!=1)
			{
				stack[top++]=e->data;
				visited[e->data]=1;
			}
		}
	}
	
}


int main()
{
	int v=0;
	graph *g=buildg();
	Printg(g);
	D_BFS(g,v);
	
}






