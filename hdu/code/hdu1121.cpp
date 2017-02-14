#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int T;
    int a[110][110];
    scanf("%d",&T);
    while(T--)
    {
        int i,j,s,c;
        scanf("%d%d",&s,&c);
        for(i=1;i<=s;i++)
            scanf("%d",&a[1][i]);
        for(i=2;i<=s;i++)
            for(j=s-1;j>=1;j--)
                a[i][j]=a[i-1][j+1]-a[i-1][j];
        /*for(i=1;i<=s;i++)
        {
            for(j=1;j<=s-i+1;j++)
                printf("%d ",a[i][j]);
            cout<<endl;
        }*/
        for(i=2;i<=c+1;i++)
            a[s][i]=a[s][1];
        for(i=s-1;i>=1;i--)
        {
            int t=s-i+1+c;
            for(j=s-i+2;j<=t;j++)
                a[i][j]=a[i][j-1]+a[i+1][j-1];
        }
        /*for(i=1;i<=s+c;i++)
        {
            for(j=1;j<=s+c-i+1;j++)
                printf("%d ",a[i][j]);
            cout<<endl;
        }*/
        for(i=s+1;i<=s+c-1;i++)
            printf("%d ",a[1][i]);
        printf("%d\n",a[1][s+c]);
    }
    return 0;
}
