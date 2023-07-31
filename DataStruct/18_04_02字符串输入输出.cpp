#include <stdio.h>

int main()
{
    char word[1];
    scanf("%s",word);

    printf("%s\n",word);
    printf("sizeof=%lu\n",sizeof(word));
    printf("weizhi=%p\n",word); 
    printf("weizhi[0]=%p %d\n",&word[0],word[0]); 
    printf("weizhi[1]=%p %d\n",&word[1],word[1]);
    printf("weizhi[2]=%p %d\n",&word[2],word[2]);
    printf("weizhi[3]=%p %d\n",&word[3],word[3]);
    printf("weizhi[4]=%p %d\n",&word[4],word[4]);
    printf("weizhi[5]=%p %d\n",&word[5],word[5]);
    printf("weizhi[6]=%p %d\n",&word[6],word[6]);
    printf("weizhi[7]=%p %d\n",&word[7],word[7]);
    printf("weizhi[8]=%p %d\n",&word[8],word[8]);
    
   
	
	  
    return 0;
    
}
