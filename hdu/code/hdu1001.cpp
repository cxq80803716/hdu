#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        int sum=0;
        for(i=1;i<=n;i++)
        sum+=i;
        printf("%d\n\n",sum);
    }
    return 0;
}