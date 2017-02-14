#include<stdio.h>
int main()
{
    int n, m, times, count = 0, i, j, flag = 1;
    scanf("%d", &times);
    while(times--)
    {
        while(1)
        {
            scanf("%d%d", &n, &m);
            if(!n && !m) break;
            for(i=1; i<n; ++i)
            for(j=1; j<i; ++j)
            if((i*i+j*j+m)%(i*j) == 0) count++;
            printf("Case %d: %d\n", flag++, count);
            count = 0;
        }
        flag = 1;
        if(times != 0) printf("\n");
    }
    
return 0;
}