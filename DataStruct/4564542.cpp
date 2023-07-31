#include <Stdio.h>
#include <stdlib.h>

typedef struct d{
	int data;
	struct d* left;
	struct d* right;
}tree;

tree build(tree t,int x)
{
	tree t=(tree *)malloc(sizeof(tree));
	t->data=x;
	
}



int main()
{
	tree t;
	build(t);
}
