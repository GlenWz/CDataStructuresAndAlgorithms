#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	link *head;
	head=NULL;
	int x=10;
	for(int i=0;i<5;i++,x+=5)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=x;
		s->next=head;
		head=s;
	}
	return head;
}

int del(link *a,int x)
{
	int ret=-1;
	link *p,*f,*tmp;
	for(f=a,p=NULL;f;p=f,f=f->next)
	{
		if(x==f->data)
		{
			tmp=f;
			p->next=f->next;
			f=f->next;
			free(tmp);
			ret=1;
		}
	}
	return ret;
}
void print(link *a)
{
	for(a;a;a=a->next)
	{
		printf("%d\t",a->data);
	}
	printf("\n---------------------------------------\n");
}



int main()
{
	link *a=build();
	print(a);
	int x=20;
	int ret=del(a,x);
	print(a);
	printf("%d\n",ret);
}
