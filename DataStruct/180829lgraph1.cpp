#include <Stdio.h>
#include <stdlib.h>
#define laozishiweight 8
#define maxsize 100
typedef int vertex;
typedef struct d{
	vertex adjvert;
	struct d *next;
	int weight;
}enode;

typedef struct vn{
	vertex vert;
	vertex mark=0;
	enode *firstedge;
}Adjlist[maxsize];

typedef struct {
	Adjlist adjlist;
	int ne,nv;
}lgraph;

lgraph *build()
{
	vertex v1,v2;
	lgraph *lg=(lgraph *)malloc(sizeof(lgraph));
	enode *s;
	lg->ne=3;
	lg->nv=3;
	for(int i=0;i<lg->nv;i++)
	{
		lg->adjlist[i].vert=i;
		lg->adjlist[i].firstedge=NULL;
	}
	for(int i=0;i<lg->ne;i++)
	{
		printf("please input the v1 and v2:\n");
		scanf("%d %d",&v1,&v2);
		s=(enode *)malloc(sizeof(enode));
		s->weight=laozishiweight;
		s->adjvert=v1;
		s->next=lg->adjlist[v2].firstedge;
		lg->adjlist[v2].firstedge=s;
		s=(enode *)malloc(sizeof(enode));
		s->weight=laozishiweight+1;
		s->adjvert=v2;
		s->next=lg->adjlist[v1].firstedge;
		lg->adjlist[v1].firstedge=s;
	}
	return lg;
}
void printv(lgraph *lg)
{
	int i,j,k;
	enode  *e;
	printf("the graph is :\n");
	for(i=0;i<lg->nv;i++)
	{
		printf("HEAD:%d",lg->adjlist[i].vert);
		e=lg->adjlist[i].firstedge;
		while(e!=NULL)
		{
			printf("E:%d(W:%d)",e->adjvert,e->weight);
			e=e->next;
		}
		printf("\n");
	}
}

void DFS(lgraph *lg,vertex i)
{
	enode *n;
	lg->adjlist[i].mark=1;
	n=lg->adjlist[i].firstedge;
	while(n!=NULL)
	{
		printf("%d->",lg->adjlist[i].vert);
		if(lg->adjlist[i].mark==0)
		{
			DFS(lg,n->adjvert);
			n=n->next;
		}
		
	}
}

int main()
{
	lgraph *lg=build();
	printv(lg);
	DFS(lg,1);
}
