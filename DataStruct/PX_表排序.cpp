#include <Stdio.h>
#include <stdlib.h> 
#include <string.h>
#define maxsize 10

typedef struct d{
	int data[maxsize];        //数组指针 ，指向不可移动的数据 
	int table[maxsize];      //这个是指针 
	char key[maxsize];      //关键信息，也就是相当于字典的首字母。 
}Array;

Array *buildA()
{
	Array *a=(Array *)malloc(sizeof(Array));
	char kkk[]={'d','f','b','c','j','e','g','h','i','a'};
//	int kk[]={3,5,1,2,9,4,6,7,8,0};
	for(int i=0;i<maxsize;i++)
	{
		a->data[i]=i;
		a->table[i]=i;
		a->key[i]=kkk[i];
	}
	return a;
}
void SWAP(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void Biao_sort(Array *a)
{
	int tmp,i,j,change;
	char min;
	for(i=0;i<maxsize-1;i++)
	{
		min=a->key[i];
		tmp=i;
		for(j=i+1;j<maxsize;j++)
		{
			printf("%c  %c->\n",a->key[j],min);
			if(a->key[j]>min)
			{
				min=a->key[j];
				tmp=j;
			}
		}
		change=a->table[i];
		a->table[i]=a->table[tmp];
		a->table[tmp]=change;
	}
}
void PrintA(Array *a)
{
	for(int i=0;i<maxsize;i++)
	{
		
		printf("%d->",a->table[i]);
		
	}
	printf("\n");
	for(int i=0;i<maxsize;i++)
	{
		printf("%c->",a->key[a->table[i]]);
	}
	printf("\n");
}

int main()
{
	Array *a=buildA();
	Biao_sort(a);
	PrintA(a);
}
