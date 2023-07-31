#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

char* longestPalindrome(char* s) {
    char a[1000000],*p,b[1000000];
    int start,end,max,size;
    bool flag;
    start=end=max=size=0;
    p=s;
    for(size=0;*p!=NULL;p++) a[size++]=*p;

    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            flag=true;
            for(int n=i,m=j;n<m;n++,m--){
                if(a[n]!=a[m]){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                if(max<j-i+1){
                    max=j-i+1;start=i;end=j;
                }
            }
        }
    }
    for(int i=start,j=0;i<=end;i++,j++) b[j]=a[i];
    b[max]='\0';
    p=b;
    return p;


}

int main(){
    char s[1000000]="cbbd";
    printf("%s",longestPalindrome(s));
}



