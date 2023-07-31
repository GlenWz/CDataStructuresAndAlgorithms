#include <Stdio.h>
#include <Stdlib.h>
#define maxvex 100
typedef int vertex;              //vertex 
typedef struct node{            //�߱�ڵ� 
	int adjtex;                 //�ڽӵ��� 
	struct node *next;          //�ڽӵ�ָ�룬���� 
	int weight;                 //Ȩ�� ,�����ݽṹ����Ȩ�� 
}edgenode;                     //��

typedef struct vnode{         //�����ڵ� 
	vertex vert;              //������ 
	edgenode *firstedge;      //ָ���һ���� 
}vertexnode;        

typedef vertexnode Adjlist[maxvex];
typedef struct {
	Adjlist adjlist;         //�ڽӱ� 
	int ne,nv;               //ne������nv���� 
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
		g->adjlist[i].vert=i;             // ������Ϣ  ****
		g->adjlist[i].firstedge=NULL;     //           ***
	}
	for(k=0;k<g->ne;k++)
	{
		scanf("%d%d",&i,&j);             //����ߣ�vi����vj��
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
