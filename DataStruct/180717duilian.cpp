#include <stdio.h>
#include <stdlib.h>

#define length 10

typedef struct Qnode{
	int data;
	struct Qnode *next;
}Qnode,*quep;

typedef struct{
	Qnode *front;
	Qnode *rear;
}linkq;

linkq initqueue()
{
	linkq Q;
	Q.front=Q.rear=(quep)malloc(length);
	Q.front=NULL;
	return Q;
}



int main()
{
	linkq head;
	head=initqueue();
}
