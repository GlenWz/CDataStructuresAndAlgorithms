#include <Stdio.h>
#include <stdlib.h>
#include <Windows.h>


int main()
{
	int n=0;
	while(1)
	{
		for(int i=0;i<96000000000;i++)
		{
			n++;
		}
		Sleep(10); 
	}
}
