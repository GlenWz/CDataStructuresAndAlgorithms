#include <Stdio.h>
#include <Stdlib.h>
#define max 100
typedef int vertex;
typedef struct node{
	int adjtex;
	struct node *next;
	int weight;
}edgenode;

typedef struct vnode{
	vertex vert;
	edgenode * firstedge;
}vertexnode;
typedef vertexnode Adjlist[max];
typedef struct {
	Adjlist adjlist;
	int ne,nv;
}lgraph;

lgraph *build()
{
	edgenode *s;
	int i,j,k;
	lgraph *lg=(lgraph *)malloc(sizeof(lgraph));
	lg->ne=3;
	lg->nv=3;
	for(i=0;i<lg->ne;i++)
	{
		lg->adjlist[i].vert=i;
		lg->adjlist[i].firstedge=NULL;
	}
	for(k=0;k<lg->nv;k++)
	{
		printf("please input the edge<vi,vj>");
		scanf("%d %d",&i,&j);
		s=(edgenode *)malloc(sizeof(edgenode));
		s->adjtex=j;
		s->weight=k*k;
		s->next=lg->adjlist[i].firstedge;
		s->adjtex=i;
		s->next=lg->adjlist[j].firstedge;
		lg->adjlist[i].firstedge=s;
		s->weight=k*k;
	}
	return lg;
}

void print(lgraph *lg)
{
	int i,j,k;
	edgenode *a;
	printf("List Graph :\n");
	for(i=0;i<lg->nv;i++)
	{
		printf("%d(%d)",i,lg->adjlist[i].vert);
		a=lg->adjlist[i].firstedge;
		while(a!=NULL)
		{
			printf("%d(%d)",a->adjtex,lg->adjlist[a->adjtex].vert);
			a=a->next;
		}
		printf("\n");
	}
}

int main()
{
	lgraph *lg=build();
	print(lg);
	return 0;
	
	
}
