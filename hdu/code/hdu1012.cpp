#include<stdio.h>
#include<string.h>
double run(int n)
{
    if(n == 0 || n == 1) return 1;
    else return run(n-1)*n;
}

int main()
{
    int n, i, j;
    double sum[11];
    memset(sum, 0, sizeof(sum));
    printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
    sum[2] = 2.5;
    for(i=3; i<=9; i++)
    {
        sum[i] = sum[i-1] + 1.0/run(i);
        printf("%d %.9lf\n", i, sum[i]);
    }
}