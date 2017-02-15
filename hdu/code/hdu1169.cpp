#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
char s[1000];
int main()
{
    int i,j,n,m,sum,p;
    while(scanf("%d",&n)&&n)
    {
       itoa(n,s,2);
       //printf("%s\n",s);
       m=strlen(s);p=0;
       for(i=m-1;i>=0;i--)
       {
          p++;
          if(s[i]=='1')
          {
             m=p-1;
             break;
          }
       }


       sum=1;
       for(i=m-1;i>=0;i--)
       sum*=2;
       printf("%d\n",sum);
    }
    return 0;
}