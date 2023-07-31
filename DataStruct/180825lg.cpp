#include <Stdio.h>
#include <Stdlib.h>
#define maxsize 8
typedef int vertex ;
typedef struct Arcnode{
	int dajvex;
	struct Arcnode *next;
	int info;
}Arcnode;

typedef struct vnode{
	char data;  
	Arcnode *firstact;
}vnode;

typedef struct {
	vnode adjlist[maxsize];
	int nv,ne; 
}lgraph;
 
lgraph *creat()
{
	vertex v,w;
	lgraph *lg=(lgraph *)malloc(sizeof(lgraph));
	lg->ne=0;
	lg->nv=10;
	for(v=0;v<lg->nv;v++)
	{
		lg->adjlist[v].firstact=NULL;
	}
	return lg;
}

int main()
{
	lgraph *lg=creat();
	return 0;
}

