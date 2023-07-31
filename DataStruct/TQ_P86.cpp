#include <Stdio.h>
#include <Stdlib.h>
#define MAX 8
typedef struct d{
	int data[MAX][MAX];
	int head[MAX];
	int nv,ne;
}Graph;

typedef struct edge{
	int data;
	int weight;
	struct edge *next;
}edgenode;

typedef struct vnode{
	int head;
	edgenode *firstedge;
}Adjlist[MAX];

typedef struct {
	Adjlist adjlist;
	int nv,ne;
}GraphLink;

int visited[MAX]={0};


Graph *Buildg()
{
	int queue[]={0,1,1,1,2,4,1,4,2,1,3,1,1,7,3,2,4,1,2,5,1,3,5,3,3,6,2,6,7,1,};
	int front=0,rear=sizeof(queue)/sizeof(queue[0]);
	int v1,v2,w;
	Graph *g=(Graph *)malloc(sizeof(Graph));
	g->ne=10;
	g->nv=8;
	for(int i=0;i<g->nv;i++)
	{
		for(int j=0;j<g->nv;j++)
		{
			g->data[i][j]=0;
		}
		g->head[i]=0;
	}
	while(front!=rear)
	{
		v1=queue[front++];
		v2=queue[front++];
		w=queue[front++];
		g->data[v1][v2]=w;
		if(g->head[v1]==0)
		{
			g->head[v1]=1;
		}
		g->data[v2][v1]=w;
		if(g->head[v2]==0)
		{
			g->head[v2]=1;
		}
	}
	return g;
}
/*
void DFS(Graph *g,int v)
{
	printf("%d->",v);
	g->head[v]=2;
	for(int i=0;i<g->nv;i++)
	{
		if(g->data[v][i]!=0&&g->head[i]!=2)
		{
			DFS(g,i);
		}
	}
}*/

void DFSer(Graph *g,int v)
{
	printf("%d->",v);
	g->head[v]=2;
	for(int i=0;i<g->nv;i++)
	{
		if(g->head[i]==1&&g->data[v][i]!=0)
		{
			DFSer(g,i);
			g->head[i]=2;
		}		
	}
}
void BFS(Graph *g,int v)
{
	int queue[50];
	int front=0,rear=0;
	printf("%d->",v);
	g->head[v]=3;
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		for(int i=0;i<g->nv;i++)
		{
			if(g->data[v][i]!=0&&g->head[i]==2)
			{
				g->head[i]=3;
				printf("%d->",i);
				queue[rear++]=i;
			}
		}
	}
}
GraphLink *Convert2Node(Graph *g)
{
	GraphLink *gl=(GraphLink *)malloc(sizeof(GraphLink));
	gl->ne=g->ne;
	gl->nv=g->nv;
	for(int i=0;i<gl->nv;i++)
	{
		gl->adjlist[i].head=i;
		gl->adjlist[i].firstedge=NULL;
	}
	for(int i=0;i<g->nv;i++)
	{	
		for(int j=0;j<g->nv;j++)
		{
			if(g->data[i][j]!=0)
			{
				edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
				e1->data=j;
				e1->weight=g->data[i][j];
				e1->next=gl->adjlist[i].firstedge;
				gl->adjlist[i].firstedge=e1;	
			}
		}
	}
	return gl;
}
void DFSLink(GraphLink *gl,int v)
{
	printf("%d->",gl->adjlist[v].head);
	edgenode *e;
	visited[v]=1;
	for(e=gl->adjlist[v].firstedge;e;e=e->next)
	{
		if(visited[e->data]!=1)
		{
			DFSLink(gl,e->data);
		}
	}	
}
void PrintGL(GraphLink *gl)
{
	edgenode *e;
	for(int i=0;i<gl->nv;i++)
	{
		printf("H:%d->",gl->adjlist[i].head);
		for(e=gl->adjlist[i].firstedge;e;e=e->next)
		{
			printf("E:%d(W:%d)->",e->data,e->weight);
		}
		printf("\n");
	}
}
void FDGDFS(GraphLink *gl,int v)
{
	int stack[50];
	int top;
	stack[top++]=v;
	visited[v]=5;
	printf("%d->",gl->adjlist[v].head);
	edgenode *e;
	while(top!=0)
	{
		v=stack[--top];
		e=gl->adjlist[v].firstedge;
		if(visited[e->data]!=5)
		{
			stack[top++]=e->data;
			visited[e->data]=5;
			printf("%d->",gl->adjlist[e->data].head);
		}else
		{
			e=e->next;
			for(;e!=NULL;e=e->next)
			{
				if(visited[e->data]!=5)
				{
					stack[top++]=e->data;
					visited[e->data]=5;
					printf("%d->",gl->adjlist[e->data].head);
				}
			}
		}
	}
	//printf("\n%d\n",visited[0]);
}

int main()
{
	Graph *g=Buildg();
	int v=0;
	printf("DFS:\n");
	DFSer(g,v);
	printf("\nBFS:\n");
	BFS(g,v);
	printf("\n");
	GraphLink *gl=Convert2Node(g);
	PrintGL(gl);
	printf("DFSLink:\n");
	DFSLink(gl,1);
	printf("\nFDGDFS:\n");
	FDGDFS(gl,1);
}






