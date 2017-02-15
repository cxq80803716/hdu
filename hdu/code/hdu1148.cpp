#include<stdio.h>
#include<string.h>

int main()
{
    int n,k;
    int w[110],l[110];
    int T=1;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&k);
        if(T==0)
            printf("\n");
        T=0;
        memset(w,0,sizeof(w));
        memset(l,0,sizeof(l));
        int a,b,i,m;
        char str1[10],str2[10];

        for(i=0;i<k;i++){
        scanf("%d",&a);
        scanf("%s",str1);
        scanf("%d",&b);
        scanf("%s",str2);
        if(strcmp(str1,"rock")==0)
        {
            if(strcmp(str2,"scissors")==0)
            {
                w[a]++;
                l[b]++;
            }
            if(strcmp(str2,"paper")==0)
            {
                l[a]++;
                w[b]++;
            }
        }
        if(strcmp(str1,"scissors")==0)
        {
            if(strcmp(str2,"paper")==0)
            {
                w[a]++;
                l[b]++;
            }
            if(strcmp(str2,"rock")==0)
            {
                l[a]++;
                w[b]++;
            }
        }
        if(strcmp(str1,"paper")==0)
        {
            if(strcmp(str2,"rock")==0)
            {
                w[a]++;
                l[b]++;
            }
            if(strcmp(str2,"scissors")==0)
            {
                l[a]++;
                w[b]++;
            }
        }
        }
        for(i=1;i<=n;i++)
        {
            m=w[i]+l[i];
            if(m==0)
                printf("-\n");
            else
                printf("%.3f\n",w[i]*1.0/m);
        }
    }
    return 0;
}