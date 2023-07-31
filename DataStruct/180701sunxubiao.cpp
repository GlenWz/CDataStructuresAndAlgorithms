#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct{
	int data[maxsize];
	int length;
}sqlist;      //���ýṹ����sqlist��˳��� ��������Ϊ����ĺ� 10 

sqlist *build();
sqlist *Del();
sqlist *INST(int x); 

sqlist *build(void)  //˳���Ľ�������ֵ�� 
{
	int j;
	sqlist *q=(sqlist *)malloc(maxsize*sizeof(sqlist)); //ʹ�� malloc ������̬����10��sqlist�ṹ�ڴ� 
	for(int i=10,j=0;j<sizeof(q->data)/sizeof(q->data[0]);i++,j++)       //iΪdata��jΪ������ 
	{
		q->data[j]=i;
		q->length=j+1;                       //����ΪʲôҪ+1�أ���Ϊ��������Ǵ�0��ʼ�� 
	}
	return q;                          
}

sqlist *Del()
{
	sqlist *p;
	p=build();                        //����֮ǰ���õ�˳��� 
	for(int i=0;i<maxsize;i++)        //��0 ��ʼ����˳��� 
	{
		if(p->data[i]==12)             //���� 12Ϊ Ҫɾ����˳����dataΪ12���������12�����û��������� 
		{
			for(int j=i;j<sizeof(p->data)/sizeof(p->data[0]);j++)  //��i��λ�ø�ֵ��j��������jҪС�� p�ĳ��ȣ�j++ 
			{
				p->data[j]=p->data[j+1];    //****������ǽ�j���λ�õ��������ǵ������ϵظ��ǵ��� 
			}                              //Ȼ��dataΪ12 ������ɾ���ˣ��ǲ��Ǻܼ򵥣� 
			p->length--;                   //��ѱ��˸��ǵ��ˣ�������ȻҪ��һ�� 
			break;                        //����ȥ 
		}
		else if(i>p->length-1)          //Ҫ��i һֱ������ length-1 ˵��û���ҵ� 
		{
			printf("û�ҵ���");
			break; 
		 } 
	}
	return p;
}

sqlist *INST(int x)               //����һ���� 
{
	sqlist *q;
	q=Del();                     //���ñ�ɾ���ĺ���Del(); 
	for(int i=0;i<sizeof(q->data)/sizeof(q->data[0]);i++)    //���� 
	{
		if(q->data[i]>=x||i==q->length)      //���  data[i] �����ǾͲ��ȥ 
		{
			for(int j=q->length;j>=i;j--)   //j�������� 
			{
				q->data[j]=q->data[j-1];  //�Ӻ���ǰŲλ�ò��ܲ��ȥ 
			}
			q->data[i]=x;             //����λ�� �Ͳ��ȥ�� 
			q->length++;             //����+1 
			break;
		}
	}
	return q;
}

int main()
{
	sqlist *h;
	h=build();             //���ú���build 
	for(int i=0;i<sizeof(h->data)/sizeof(h->data[0]);i++)                  //������� 
	{
		printf("data=%d\n",h->data[i]);
	}
	sqlist *del; int x=15;             //20 Ϊ����˳����ֵ 
	del=Del();                            //���ú��� 
	for(int i=0;i<del->length;i++)        //������� 
	{
		printf("del:%d\n",del->data[i]);  
	}
	sqlist *insert;                       
	insert =INST(x);                 //���ñ�������鿴 ��� 
	for(int i=0;i<sizeof(insert->data)/sizeof(insert->data[0]);i++)
	{
		printf("Insert:%d\n",insert->data[i]);
	}
	//*********************�����˷������ڴ���Ҫ��Ҫ free();!!!!!!!!!
	
	return 0;
	
	
}
