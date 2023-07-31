#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play{
	char name[10];
	int number;
	struct play *next;
}player;                         //����һ�������� 

player *build()
{
	player *p1=(player *)malloc(sizeof(player));    //����malloc �����ڴ� 
	player *p2=(player *)malloc(sizeof(player));
	player *p3=(player *)malloc(sizeof(player));
	player *head,*q;
	int i=1;
	head=p1;
	p1->next=p2; p2->next=p3; p3->next=NULL;      //�������� 
	for(q=head;q;q=q->next,i++)                  //�˺���Ϣ 
	{
		q->number=i;
	} 
	strcpy(p1->name,"����");                    //���� 
	strcpy(p2->name,"��ʥ");
	strcpy(p3->name,"��ͷ");
	return head;
}
player *Del()                            //�������ɾ�� 
{
	player *head,*q,*p;
	head=build();
	for(q=head,p=NULL;q;p=q,q=q->next)    //��������һ���������ܻ����� 
	{                            //p��q��ǰһ��������Ϊ�ǵ�����û��ָ��ǰ���ָ�� 
		if(q->number==2)             //������P���� ���ҵ�Q->number==2��ɾ�� 
		{
			if(p)
			{
				p->next=q->next;    //����Q��ǰһ������P ָ��Q����һ�� 
			}
			else
			{
				head=q->next;
			}
			free(q);              //free q������ 
		    break;
		}
	}
	return head;
}

player * INST()            //���� 
{
	player *head,*q,*p;
	head=Del();
	player *p4=(player *)malloc(sizeof(player)); //���Ƚ���һ������ 
	p4->number=2;                        //��ֵ 
	strcpy(p4->name,"tencent");          //���� 
	for(q=head,p=NULL;q;p=q,q=q->next)  //p����Q��ǰָ�� 
	{
		if(q->number>=p4->number)      //�ҵ����ڵ�λ�ã����� 
		{
			p->next=p4;
			p4->next=q;
			break;	
		}
	}
	return head;
}

int main()
{
	player *head,*q,*p,*i;
	head=build();
	for(q=head;q;q=q->next)     //���� 
	{
		printf("build:%d player is %s\n",q->number,q->name);
	}
	player *del;
	del=Del();
	for(p=del;p;p=p->next)
	{
		printf("Del:%d player is %s\n",p->number,p->name);
	}
	player *insert;
	insert=INST();
	for(i=insert;i;i=i->next)
	{
		printf("insert:%d player is %s\n",i->number,i->name);
	}
	while(head!=NULL)             //������֮��free�ڴ� 
	{
	
		play *f;
		f=head;
		head=head->next;
		free(f);		
	}
	return 0;
 } 
