#include <stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d *next;
}link;

link *build()
{
	int num;
	link *head=(link *)malloc(sizeof(link));
	link *ret=head;
	printf("please input the NUM:\n");
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		link *s=(link *)malloc(sizeof(link));
		s->data=i*i;
		s->next=NULL;
		head->next=s;
		head=s;
	}
	return ret;
}
void print(link *s)
{
	link *d=s;
	for(d=d->next;d!=NULL;d=d->next)
	{
		printf("%d->",d->data);
	}
	printf("\n");
}




int main()
{
	link *s=build();
	print(s);
}
