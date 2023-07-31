#include <Stdio.h>
#include <Stdlib.h>

typedef struct d{
	int data;
	struct d *left;
	struct d *right;
}bitree;

bitree *findmin(bitree *s);

bitree *build()
{
	int num;
	printf("input:");
	scanf("%d",&num);
	if(num==0)
	{
		return NULL;
	}else 
	{
		bitree *s=(bitree *)malloc(sizeof(bitree));
		s->data=num;
		s->left=build();
		s->right=build();
	}
}
bitree *insert(bitree *h,int x)
{
	if(h->left==NULL&&h->right==NULL)
	{
		bitree *s=(bitree *)malloc(sizeof(bitree));
		s->data=x;
		s->left=s->right=NULL;
		if(h->data>x)
		{
			h->left=s;
		}else 
		{
			h->right=s;
		}
	}else 
	{
		if(h->data>x)
		{
			h->left=insert(h->left,x);
		}else if(h->data<x)
		{
			h->right=insert(h->right,x);
		}else 
		{
			printf("error");
			return 0;	
		}
	}
}
void mid(bitree *s)
{
	if(s)
	{
		mid(s->left);
		printf("%d\t",s->data);
		mid(s->right);
	}
}
bitree *DEL(bitree *h,int x)
{
	if(h==NULL)
	{
		printf("the tree is empty\n");
		return 0;
	}else if(h->data>x)
	{
		h->left=DEL(h->left,x);
	}else if(h->data<x)
	{
		h->right=DEL(h->right,x);
	}
	else
	{
		bitree *tmp;
		if(h->left&&h->right)
		{
			tmp=findmin(h);
			h->data=tmp->data;
			h->right=DEL(h->right,h->data);
		}else 
		{
			tmp=h;
			if(h->left==NULL)
			{
				h=h->right;
			}else if(h->right==NULL)
			{
				h=h->left;
			}
			free(tmp);
		}
	}
	return h;
}

bitree *findmin(bitree *s)
{
	int d=s->data;
	bitree *min;
	while(s)
	{
		if(s->data<d)
		{
			min=s;
			d=s->data;
			s=s->left;
		}
		s=s->right;
	}
	return min;
}

int main()
{
	bitree *s=build();
	int x=25;
	bitree *in=insert(s,x);
	mid(in);
	printf("\n------------------------------------woshinidei\n");
	bitree *del=DEL(in,x);
	mid(del);
	printf("\n------------------------------------woshinidie\n");
}
