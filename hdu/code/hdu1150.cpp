#include<cstring>
#include<cstdio>

const int maxn = 2e2+10;

bool vis[maxn],mp[maxn][maxn];
int link[maxn];

int n,m,k;

bool dfs(int u){
    for(int i=1;i<n+m;i++){
        if(!vis[i]&&mp[u][i]){
            vis[i]=true;
            if(link[i]==-1||dfs(link[i])){
                link[i]=u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    while(scanf("%d",&n),n){
        scanf("%d%d",&m,&k);
        memset(link,-1,sizeof(link));
        memset(mp,false,sizeof(mp));
        for(int i=1;i<=k;i++){
            int a,b,c;scanf("%d%d%d",&a,&b,&c);
            if(b==0||c==0)continue;
            mp[b][c+n]=true;
        }
        int ans = 0;
        for(int i=1;i<n;i++){
            memset(vis,false,sizeof(vis));
            if(dfs(i))ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}