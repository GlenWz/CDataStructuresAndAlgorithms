#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int *p;
	int length;
}Vector;

Vector *buildv(int n)
{
	Vector *v=(Vector *)malloc(sizeof(Vector));
	v->length=n;
	v->p=(int *)malloc(sizeof(int)*n);
	return v;
}

void Fuzhi(Vector *v)
{
	for(int i=0;i<v->length;i++)
	{
		v->p[i]=i;
	}
}
void Printv(Vector *v)
{
	for(int i=0;i<v->length;i++)
	{
		printf("%d->",v->p[i]);
	}
	printf("\n");
}
Vector *Grow(Vector *v,int n)
{
	Vector *v2=(Vector *)malloc(sizeof(Vector));
	v2->length=n*2;
	v2->p=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<v->length;i++)
	{
		v2->p[i]=v->p[i];
	}
	v2->length=n;
	free(v->p);
	free(v);
	return v2;
}
void Fuzhi2(Vector *v)
{
	for(int i=10;i<v->length;i++)
	{
		v->p[i]=i;
	}
}

int main()
{
	int n=10;
	Vector *v=buildv(10);	
	Fuzhi(v);
	Printv(v);
	Vector *v2=Grow(v,n*2);
	printf("\n");
	Fuzhi2(v2);
	Printv(v2);
	
}











 
