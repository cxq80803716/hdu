#include <stdio.h>
int main()
{
char s[1000];
int i,sum;
while(scanf("%s",s)!=EOF)
{
      if(s[0]=='0')
       {
         break;
        }
      sum=0;
   for(i=0;s[i]!='\0';i++)
    {
      sum+=s[i]-'0';
    if(sum>9)
    {
     sum=sum%10+sum/10;
    }
    }
    printf("%d\n",sum);
    }
    return 0;
}