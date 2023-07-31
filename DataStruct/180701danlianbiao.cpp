#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct play{
	char name[10];
	int number;
	struct play *next;
}player;                         //构建一个单链表 

player *build()
{
	player *p1=(player *)malloc(sizeof(player));    //利用malloc 分配内存 
	player *p2=(player *)malloc(sizeof(player));
	player *p3=(player *)malloc(sizeof(player));
	player *head,*q;
	int i=1;
	head=p1;
	p1->next=p2; p2->next=p3; p3->next=NULL;      //链接起来 
	for(q=head;q;q=q->next,i++)                  //账号信息 
	{
		q->number=i;
	} 
	strcpy(p1->name,"死歌");                    //名字 
	strcpy(p2->name,"剑圣");
	strcpy(p3->name,"狗头");
	return head;
}
player *Del()                            //单链表的删除 
{
	player *head,*q,*p;
	head=build();
	for(q=head,p=NULL;q;p=q,q=q->next)    //这里的最后一个条件不能换过来 
	{                            //p是q的前一个链表，因为是单链表没有指向前面的指针 
		if(q->number==2)             //所以用P代替 ，找到Q->number==2的删除 
		{
			if(p)
			{
				p->next=q->next;    //利用Q的前一个链表P 指向Q的下一个 
			}
			else
			{
				head=q->next;
			}
			free(q);              //free q就行了 
		    break;
		}
	}
	return head;
}

player * INST()            //插入 
{
	player *head,*q,*p;
	head=Del();
	player *p4=(player *)malloc(sizeof(player)); //首先建立一个链表 
	p4->number=2;                        //赋值 
	strcpy(p4->name,"tencent");          //赋名 
	for(q=head,p=NULL;q;p=q,q=q->next)  //p代表Q的前指针 
	{
		if(q->number>=p4->number)      //找到所在的位置，插入 
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
	for(q=head;q;q=q->next)     //遍历 
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
	while(head!=NULL)             //结束完之后free内存 
	{
	
		play *f;
		f=head;
		head=head->next;
		free(f);		
	}
	return 0;
 } 
