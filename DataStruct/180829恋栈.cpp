#include <stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}lstack;

lstack *build()
{
	lstack *s=(lstack *)malloc(sizeof(lstack));
	s->data=NULL;
	s->next=NULL;
	return s;
}
void insertl(lstack *li,int x)
{
	lstack *s=(lstack *)malloc(sizeof(lstack));
	s->data=x;
	s->next=li->next;
	li->next=s;
}
int DEL(lstack *li)
{
	int ret;
	lstack *tmp=li->next;
	ret=tmp->data;
	li->next=tmp->next;
	free(tmp);
	return ret;
}
void print(lstack *li)
{
	for(li=li->next;li;li=li->next)
	{
		printf("%d\t",li->data);
	}
	printf("\n");
}

int main()
{
	lstack *l=build();	
	for(int i=0;i<5;i++)
	{
		insertl(l,i*i);
	}
	int de=DEL(l);
	printf("%d\n",de);
	print(l);
	return 0;
}
