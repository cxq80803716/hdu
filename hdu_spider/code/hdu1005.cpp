#include <stdio.h>
int main()
{
    int n=0,A=0,B=0;
    //freopen(".\\1005in.txt","r",stdin);
    while(scanf("%d %d %d",&A,&B,&n),A||B||n)
    {
        int result[50]= {1,1};
        int i;
        for(i=2; i<50; i++)
        {
            result[i]=(A*result[i-1]+result[i-2]*B)%7;
            if(result[i]==1&&result[i-1]==1)
            {
                break;
            }
        }

        int T=i-1;//和代码1对比一下就知道这有多恶心了.
        //printf("T for this time:%d\n",T);
        if(n%T)
            printf("%d\n",result[n%T-1]);
        else
            printf("%d\n",result[T-1]);
    }
    return 0;
}
