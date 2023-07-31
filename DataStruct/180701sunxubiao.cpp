#include <stdio.h>
#include <stdlib.h>
#define maxsize 10

typedef struct{
	int data[maxsize];
	int length;
}sqlist;      //利用结构建立sqlist的顺序表 ，数据项为定义的宏 10 

sqlist *build();
sqlist *Del();
sqlist *INST(int x); 

sqlist *build(void)  //顺序表的建立，赋值。 
{
	int j;
	sqlist *q=(sqlist *)malloc(maxsize*sizeof(sqlist)); //使用 malloc 函数动态分配10个sqlist结构内存 
	for(int i=10,j=0;j<sizeof(q->data)/sizeof(q->data[0]);i++,j++)       //i为data，j为计数器 
	{
		q->data[j]=i;
		q->length=j+1;                       //这里为什么要+1呢？因为计算机都是从0开始数 
	}
	return q;                          
}

sqlist *Del()
{
	sqlist *p;
	p=build();                        //调用之前建好的顺序表 
	for(int i=0;i<maxsize;i++)        //从0 开始遍历顺序表 
	{
		if(p->data[i]==12)             //这里 12为 要删除的顺序表的data为12的数；这个12可以用户自行输入 
		{
			for(int j=i;j<sizeof(p->data)/sizeof(p->data[0]);j++)  //将i的位置赋值给j计数器，j要小于 p的长度，j++ 
			{
				p->data[j]=p->data[j+1];    //****这里就是将j这个位置的数给覆盖掉，不断地覆盖掉， 
			}                              //然后data为12 的数就删掉了，是不是很简单！ 
			p->length--;                   //你把别人覆盖掉了，长度自然要减一。 
			break;                        //跳出去 
		}
		else if(i>p->length-1)          //要是i 一直遍历到 length-1 说明没有找到 
		{
			printf("没找到！");
			break; 
		 } 
	}
	return p;
}

sqlist *INST(int x)               //插入一个数 
{
	sqlist *q;
	q=Del();                     //调用被删除的函数Del(); 
	for(int i=0;i<sizeof(q->data)/sizeof(q->data[0]);i++)    //遍历 
	{
		if(q->data[i]>=x||i==q->length)      //如果  data[i] 大于那就插进去 
		{
			for(int j=q->length;j>=i;j--)   //j计数器， 
			{
				q->data[j]=q->data[j-1];  //从后往前挪位置才能插进去 
			}
			q->data[i]=x;             //腾完位置 就插进去啊 
			q->length++;             //长度+1 
			break;
		}
	}
	return q;
}

int main()
{
	sqlist *h;
	h=build();             //调用函数build 
	for(int i=0;i<sizeof(h->data)/sizeof(h->data[0]);i++)                  //遍历输出 
	{
		printf("data=%d\n",h->data[i]);
	}
	sqlist *del; int x=15;             //20 为插入顺序表的值 
	del=Del();                            //调用函数 
	for(int i=0;i<del->length;i++)        //遍历输出 
	{
		printf("del:%d\n",del->data[i]);  
	}
	sqlist *insert;                       
	insert =INST(x);                 //调用遍历输出查看 结果 
	for(int i=0;i<sizeof(insert->data)/sizeof(insert->data[0]);i++)
	{
		printf("Insert:%d\n",insert->data[i]);
	}
	//*********************别忘了分配了内存你要你要 free();!!!!!!!!!
	
	return 0;
	
	
}
