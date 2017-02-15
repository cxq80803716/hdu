#include<stdio.h>
#include<math.h>
#include<string.h>
int f[1000];
int main()
{
    int a, b;
    int n, i;
    while(1)
    {
        memset(f, 0, sizeof(f));
        scanf("%d%d%d", &a, &b, &n);
        if(a==0 && b==0 && n == 0) break;
        f[0] = f[1] = 1;
        if(n == 1 || n ==2 )
        {
            printf("1\n");
            continue;
        }
        for(i = 2; i<1000; i++)
        {
            f[i] = (a * f[i-1] + b * f[i-2])% 7;
            if(f[i-1] == 1 && f[i-2] == 1 && i != 2  )  break;    
        }
        printf("%d\n",f[(n-1)%(i-2)]);
    }
    return 0;
}