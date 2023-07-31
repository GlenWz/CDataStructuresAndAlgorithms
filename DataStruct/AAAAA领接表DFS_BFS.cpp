#include <Stdio.h>
#include <Stdlib.h>
#define max 100
#define laozishiweight 8 
int Visited[max];
typedef int vertex;
typedef struct edge{
	vertex adjtex;        //边信息 
	struct edge *next;   //指向下一条边 
	int weight;          //权重 
}edgenode;

typedef struct vnode{
	vertex vert;         //头节点信息 
	edgenode *firstedge;   //指向第一条边 
}Adjlist[max];

typedef struct {
	Adjlist adjlist;     
	int ne,nv;          //图的边和节点数目 
}graph;

graph *build()
{
	vertex v,w;
	int v1,v2;
	graph *g=(graph *)malloc(sizeof(graph));
	g->ne=9;
	g->nv=8;
	for(v=0;v<g->ne;v++)             //初始化头节点 
	{
		g->adjlist[v].vert=v;          
		g->adjlist[v].firstedge=NULL;
	}
	int queue[]={0,1,1,7,1,6,1,2,1,3,2,5,2,4,4,5,5,6,} ;  //改用队列进行输入 
	int front=0,rear;
	rear=sizeof(queue)/sizeof(queue[0])-1;
	for(w=0;w<g->ne;w++)
	{
		edgenode *e1=(edgenode *)malloc(sizeof(edgenode));
	//	printf("please input the v1 and v2?\n");
		//scanf("%d %d",&v1,&v2);
		v1=queue[front++];
		v2=queue[front++];
		e1->adjtex=v1;
		e1->weight=laozishiweight;
		edgenode *e2=(edgenode *)malloc(sizeof(edge));
		e2->adjtex=v2;
		e2->weight=laozishiweight;
		e2->next=g->adjlist[v1].firstedge;
		g->adjlist[v1].firstedge=e2;
	}
	return g;
}
void PrintG(graph *g)
{
	int i,j,k;
	edgenode *e;
	printf("the graph is :\n");
	for(i=0;i<g->nv;i++)
	{
		printf("Head:%d->",g->adjlist[i].vert);
		e=g->adjlist[i].firstedge;
		while(e!=NULL)
		{
			printf("E:%d(W:%d)",e->adjtex,e->weight);
			e=e->next;
		}
		printf("\n");
	}
}

void DFS_g(graph *g,vertex v)
{
	edgenode *e;
	Visited[v]=-1;
	printf("%d->",g->adjlist[v].vert);
	for(e=g->adjlist[v].firstedge;e!=NULL;e=e->next)
	{
		if(Visited[e->adjtex]!=-1)
		{
			DFS_g(g,e->adjtex);
		}
	}
}
void BFS_g(graph *g,vertex v)
{
	vertex queue[max];
	int front=0,rear=0;
	edgenode *e;
	Visited[v]=1;
	printf("%d->",g->adjlist[v].vert);
	queue[rear++]=v;
	while(front!=rear)
	{
		v=queue[front++];
		e=g->adjlist[v].firstedge;
		for(;e!=NULL;e=e->next)
		{
			if(Visited[e->adjtex]!=1)
			{
				printf("%d->",e->adjtex);
				Visited[e->adjtex]=1;
				queue[rear++]=e->adjtex;
			}
		}
	}	
}


int main()
{
	graph *lg=build();
	PrintG(lg); 
	vertex v=0;
	printf("DFS:\n");
	DFS_g(lg,v);
	printf("\nBFS:\n");
	BFS_g(lg,v);
	
}









