#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX 1000

char a[MAX+1],b[MAX+1];
int T;

int main()
{
    scanf("%d",&T);
    for(int w=1;w<=T;++w)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%s%s",a,b);
        printf("Case %d:\n",w);
        printf("%s + %s = ",a,b);
        int len1=strlen(a);
        int len2=strlen(b);
        int fpla=MAX-( len1>len2 ? len1:len2);
        for(int i=len1-1,k=MAX;i>=0;--i,--k) 
            a[k]=(a[i]-'0'),a[i]=0;
            
        for(int i=len2-1,k=MAX;i>=0;--i,--k) 
            b[k]=(b[i]-'0'),b[i]=0;
            
        for(int i=MAX;i>=fpla;--i)
            a[i]+=b[i]; 
        for(int i=MAX;i>=fpla;--i)
        {
            int c=a[i]/10;
            a[i-1]+=c;
            a[i]%=10;
        } 
        for(int i=fpla+1;i<=MAX;++i)
            printf("%d",a[i]);
        puts("");
        if(w<T)
            puts("");
    }
    return 0;
}
