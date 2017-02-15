#include<stdio.h>
int sum(int number)
{
    int i;
    int sum=0;
    for(i=1;i<number;i++)
    {
        if(number%i==0)
            sum=sum+i;
    }
    return sum;
}

int main()
{
    int i,a,b,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        sum(a);
        if(sum(a)==b)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
