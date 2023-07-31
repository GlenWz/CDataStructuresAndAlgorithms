#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}Huffman;

void PDW(int a[],int i,int len)
{
	int parent,child,tmp;
	tmp=a[i];
	for(parent=i;(parent*2+1)<=len;parent=child)
	{
		child=parent*2+1;
	//	printf("P&C:  %d  %d  \n",parent,child);
		if((a[child]>a[child+1])&&(child!=len))
		{
			child++;
		}
		if(tmp<=a[child])
		{
			break;
		}else 
		{
			a[parent]=a[child];
		}
	}	
	a[parent]=tmp;
}

void SortHeap(int a[],int len)
{
	int i;
	for(i=(len-1)/2;i>=0;i--)   // 这里大于等于0 
	{
	//	printf("i&len:%d  %d  \n",i,len);
		PDW(a,i,len);
	}
}

void insertHeap(int a[],int num,int &len)
{
	int i=++len;
	int parent;
	for(;a[(i-1)/2]>num&&i>0;i=parent)
	{
		parent=(i-1)/2;
	//	printf("a[p]:%d  a[c]%d \n",a[i],a[(i-1)/2]);
		a[i]=a[parent];
		
	}
	a[i]=num;
}
int DeleteH(int a[],int &len)
{
	int p,c,min;
	if(len<0)
	{
		printf("the heap is empty!\n");
	}
	min=a[0];
	int tmp=a[len--];
	for(p=1;p*2+1<=len;p=c)
	{
		c=p*2+1;
		if(a[c]>a[c+1]&&c!=len)
		{
			c++;
		}
		if(tmp<=a[c])
		{
			break;
		}else
		{
			a[p]=a[c];
		}
	}
	a[p]=tmp;
	return min;
}

/*
Huffman *buildHuffman(int a[],int len)//这样没办法创建树的 
{
	Huffman *t;
	for(int i=0;i<len;i++)
	{
		t=(Huffman *)malloc(sizeof(Huffman));
		t->left->data=DeleteH(a,len);
		t->right->data=DeleteH(a,len);
		t->data=t->left->data+t->right->data;
		insertHeap(a,t->data,len);
	}
	return t;
	
}*/

void PrintH(int a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%d->",a[i]);
	}
	printf("\n");
}
/*
int PrintTree(Huffman *t)
{
	if(t==NULL)
	{
		return NULL;
	}else 
	{
		PrintTree(t->left);
		printf("%d->",t->data);
		PrintTree(t->right);
	}
	printf("\n");
}
*/

void HUF(int a[],int &len)
{
	int i,tmp,hl,hr;
	for(i=0;i<len;i++)
	{
		hl=DeleteH(a,len);
		hr=DeleteH(a,len);
		tmp=hl+hr;
		insertHeap(a,tmp,len);
	}
}

int main()
{
	int a[100]={5,9,3,7,8,11,6,2,4,10,};
	int len=9;
	SortHeap(a,len);
	insertHeap(a,1,len);
//	Huffman *t=buildHuffman(a,len);
	PrintH(a,len);
	//PrintTree(t);
	HUF(a,len);
	PrintH(a,len);
//	Huffman *t=BuildTree(a,)
}













