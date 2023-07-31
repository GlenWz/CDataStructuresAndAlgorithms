#include <Stdio.h>
#include <stdbool.h>
#include <string.h>

struct xx{
	int x;
	double y;
	
};
int *p;
bool bl=true;

string s="s";


int main()
{
		printf("int=%d\n",sizeof(int));
		printf("shortint=%d\n",sizeof(short int));
		printf("long int=%d\n",sizeof(long int));
		printf("longlongint=%d\n",sizeof(long long int));
		printf("double=%d\n",sizeof(double));
		printf("char=%d\n",sizeof(char));
		printf("float=%d\n",sizeof(float));
		printf("struct=%d\n",sizeof(xx));	
		printf("*=%d\n",sizeof(p));
		printf("bool=%d\n",sizeof(bl));
		printf("string=%d\n",sizeof(s));
		return 0;
	
	
	
}
