#include <stdio.h>

enum color{r,g,b
};
void f(enum color c);
int main()
{
	enum color t=r;
	scanf("%d",&t);
	f(t);
	return 0;
	
}
void f(enum color c)
{
	printf("%d\n",c);
 } 
