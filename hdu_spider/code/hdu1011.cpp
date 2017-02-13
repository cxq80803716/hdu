#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int MAXN=110;
struct Node
{
    int to;
    int next;
}edge[MAXN*2];
int tol;
int head[MAXN];
int bug[MAXN];
int bra[MAXN];
int n,m;
int dp[MAXN][MAXN];
void init()
{
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));
    tol=0;
}

void add_edge(int a,int b)
{
    edge[tol].to=b;
    edge[tol].next=head[a];
    head[a]=tol++;
    edge[tol].to=a;
    edge[tol].next=head[b];
    head[b]=tol++;
}

void dfs(int u,int p)
{
    int temp=(bug[u]+19)/20;
    for(int i=temp;i<=m;i++)
       dp[u][i]=bra[u];
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v=edge[i].to;
        if(v==p)continue;
        dfs(v,u);
        for(int j=m;j>=temp;j--)//一定要倒序
          for(int k=1;k+j<=m;k++)
            dp[u][j+k]=max(dp[u][j+k],dp[u][j]+dp[v][k]);
    }
}
int main()
{
   // freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    int a,b;
    while(scanf("%d%d",&n,&m))
    {
        init();
        if(n==-1&&m==-1)break;
        for(int i=1;i<=n;i++)
          scanf("%d%d",&bug[i],&bra[i]);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            add_edge(a,b);
        }
        if(m==0)
        {
            printf("0\n");
            continue;
        }
        dfs(1,-1);
        printf("%d\n",dp[1][m]);

    }
    return 0;
}