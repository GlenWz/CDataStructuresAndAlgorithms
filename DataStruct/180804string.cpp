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
        //�ж������ַ����м���û�пո� 
        if(buffer[i]== ' ')
        {
            //������ھͽ���־λ��0 
            flag=0 ;    
        }
        else 
        {
            //�����жϣ������־λΪ0��count��ʾ����
            //count�Ĵ�С���ڵ��ʵĸ��� 
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

