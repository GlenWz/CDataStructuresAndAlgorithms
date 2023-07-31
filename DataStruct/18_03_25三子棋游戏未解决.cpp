#include <stdio.h>

int main()
{
	const int size=3;
	int board[size][size];
	int i,j;
	int numOfx;
	int numOfo;
	int result=-1;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size;j++)
		{
			scanf("%d",&board[i][j]);
		}
	}
	//*******检查行 
	for (i=1;i<size&&result==-1;i++)
	{
		numOfo=numOfx=0;
		for(j=0;j<size;j++)
		{
			if(board[i][j]==1)
			numOfx++;
			else
			numOfx++;
		}
		if(numOf==size)
		{
			result=0;
		}
		else if(numOfx==size)
		{
			result=1;
		}
	 } 
	 //********检查列
	 i f(result==-1)
	 {
	 	for(j=0;j<size&&result==-1;j++)
	 	{
	 		numOfo=numOfx=0;
	 		for(i=0;i<size;i++)
	 		{
	 			if(board[i][j]==1)
	 			{
	 				numOfx++;
				 }
				 else
				 {
				 	numOfo++;
				 }
			 }
			 if(numOfo==size)
			 {
			 	result=0;
			 }
			 else if(numOfx==size)
			 {
			 	result=1;
			 }
		 }
	 }
	 //*****对角
	 numOfo=numOfx=0;
	 for(i=0;i<size;i++)
	 {
	 	if(board[i][j]==1)
		 {
		 	numOfx++;
		  } 
		  else
		  {
		  	numOfo++;
		  }
	 } 
	 if(numOfo==size)
	 {
	 	result=0;
	 }
	 else if(numOfx==size)
	 {
	 	result =1;
	 }
	 numOfo=numOfx=0;
	 for(i=0;i<size;i++)
	 {
	 	if(board[i][size-i-1]==1)
	 	{
	 		numOfx++;
		 }
		 else
		 {
		 	numOfo++;
		 }
	  } 
	 
	 
	  
}
