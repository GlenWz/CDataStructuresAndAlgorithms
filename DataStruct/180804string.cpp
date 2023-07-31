#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    int len ; 
    int i  ; 
    int flag = 0 ; 
    int count = 0 ;
    char buffer[]={"the paper definitely illustrates the important status and contributions"} ; 
   // gets(buffer);
    puts(buffer);
    for(i=0;i<sizeof(buffer)/sizeof(buffer[0]);i++)
    {
        //判断输入字符串中间有没有空格 
        if(buffer[i]== ' ')
        {
            //如果存在就将标志位置0 
            flag=0 ;    
        }
        else 
        {
            //否则判断，如果标志位为0，count表示计数
            //count的大小等于单词的个数 
            if(flag==0)
            {
             count++; 
             flag=1 ;
            }
        }
    }
    printf("%d\n",count);
    getchar();
    return 0 ;
}

