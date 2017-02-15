#include<stdio.h>
#include<math.h>

int main()
{
    double sum;
    int a;
    int N;
    while(scanf("%d",&N))
    {
        if(N<=0)
            break;
        sum=N;
        sum=sum*(sum+1)/6.0*(sum+2);
        a=log10(sum);
        sum=sum/pow(10,a);
        printf("%.2lfE%d\n",sum,a);
    }
    return 0;
}