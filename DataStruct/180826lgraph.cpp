#include <Stdio.h>
#include <Stdlib.h>
#define maxvex 100
typedef int vertex;              //vertex 
typedef struct node{            //边表节点 
	int adjtex;                 //邻接点域 
	struct node *next;          //邻接点指针，链域 
	int weight;                 //权重 ,网数据结构才有权重 
}edgenode;                     //边

typedef struct vnode{         //顶点表节点 
	vertex vert;              //顶点域 
	edgenode *firstedge;      //指向第一条边 
}vertexnode;        

typedef vertexnode Adjlist[maxvex];
typedef struct {
	Adjlist adjlist;         //邻接表 
	int ne,nv;               //ne边数，nv点数 
}lgraph;               

void creatlgraph()
{
	int i,k,j;
	edgenode *s;
	lgraph *g=(lgraph *)malloc(sizeof(lgraph));
	g->ne=2;
	g->nv=2;
	for(i=0;i<g->nv;i++)
	{
		g->adjlist[i].vert=i;             // 顶点信息  ****
		g->adjlist[i].firstedge=NULL;     //           ***
	}
	for(k=0;k<g->ne;k++)
	{
		scanf("%d%d",&i,&j);             //读入边（vi，和vj）
		s=(edgenode *)malloc(sizeof(edgenode));
		s->adjtex=j;
		s->next=g->adjlist[i].firstedge;
		g->adjlist[i].firstedge=s;
		s=(edgenode *)malloc(sizeof(edgenode));
		s->adjtex=i;
		s->next=g->adjlist[j].firstedge;
		g->adjlist[j].firstedge=s;
	}
} 

      


int main()
{
	creatlgraph();	
} 
