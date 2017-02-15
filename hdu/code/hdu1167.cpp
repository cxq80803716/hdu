#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int n,m,sta,fin,idx,cnt;
int tov[maxn*2],fr[maxn],des[maxn*2],fa[maxn],dep[maxn],siz[maxn],sig[maxn];
int tiilca[maxn*2],f[maxn*4][20],top[maxn],tii[maxn],son[maxn];
struct node
{
    int lef,rig,sig; 
}a[maxn*8];
struct node2
{
    int sta,fin,lca;
}b[maxn];
bool cmp(node2 x,node2 y)
{
    return dep[x.lca]>dep[y.lca];
}
void addedge(int cur)
{
    scanf("%d %d",&sta,&fin);
    tov[2*cur-1]=fr[sta];fr[sta]=2*cur-1;des[2*cur-1]=fin;
    tov[2*cur]=fr[fin];fr[fin]=2*cur;des[2*cur]=sta;
}
void dfs(int u,int fro,int ste)
{
    fa[u]=fro;dep[u]=ste;siz[u]=1;
    tiilca[++idx]=u;sig[u]=idx;f[idx][0]=idx;
    for(int i=fr[u];i;i=tov[i])
        if(des[i]!=fro){
            dfs(des[i],u,ste+1);
            tiilca[++idx]=u;
            f[idx][0]=sig[u];
            siz[u]+=siz[des[i]];
            if(siz[des[i]]>siz[son[u]])
                son[u]=des[i];
        }
}
void dfs2(int u,int fro,int t)
{
    top[u]=t;tii[u]=++cnt;
    if(son[u])dfs2(son[u],u,t);
    for(int i=fr[u];i;i=tov[i])
        if(des[i]!=fro&&des[i]!=son[u])
            dfs2(des[i],u,des[i]);
}
void bz()
{
    for(int i=1;i<=17;i++)for(int j=1;j<=2*n-1;j++)
        f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
}
void build(int u,int lef,int rig)
{
    a[u].lef=lef;a[u].rig=rig;
    int mid=(lef+rig)>>1;
    if(lef!=rig)
        build(2*u,lef,mid),build(2*u+1,mid+1,rig);
}
int lookfor(int lef,int rig)
{
    if(sig[lef]>sig[rig])swap(lef,rig);
    int tmp=floor(log(sig[rig]-sig[lef]+1)/log(2));
    return tiilca[min(f[sig[lef]][tmp],f[sig[rig]+1-(1<<tmp)][tmp])];
}
void update(int u,int dot)
{
    a[u].sig++;
    if(a[u].lef==a[u].rig&&a[u].rig==dot)return;
    int mid=(a[u].lef+a[u].rig)>>1;
    if(dot<=mid)update(2*u,dot);
    else update(2*u+1,dot);
}
int query(int u,int lef,int rig)
{
    if(a[u].lef==lef&&a[u].rig==rig)return a[u].sig;
    else{
        int mid=(a[u].lef+a[u].rig)>>1;
        if(rig<=mid)return query(2*u,lef,rig);
        else if(lef>mid)return query(2*u+1,lef,rig);
        else return query(2*u,lef,mid)+query(2*u+1,mid+1,rig);
    }
}
int queryctrl(int u)
{
    sta=b[u].sta;fin=b[u].fin;
    int ret=0;
    int fa1=top[sta],fa2=top[fin];
    while(fa1!=fa2){
        if(dep[fa1]<dep[fa2]){
            swap(sta,fin);swap(fa1,fa2);
        }
        ret+=query(1,tii[fa1],tii[sta]);
        sta=fa[fa1];fa1=top[sta];
    }
    if(sta==fin)return ret;
    if(tii[sta]>tii[fin])swap(sta,fin);
    ret+=query(1,tii[sta],tii[fin]);
    return ret;
}
void work()
{
    int ans=0;
    for(int i=1;i<=m;i++)
        scanf("%d %d",&b[i].sta,&b[i].fin);
    for(int i=1;i<=m;i++)
        b[i].lca=lookfor(b[i].sta,b[i].fin);
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<=m;i++){
    ans+=queryctrl(i);
    update(1,tii[b[i].lca]);
    }
    printf("%d",ans);
}
void init()
{
    memset(f,127,sizeof(f));
    scanf("%d %d",&n,&m);
    for(int i=1;i<n;i++)addedge(i);
    dfs(1,1,0);
    dfs2(1,1,1);
    bz();build(1,1,n);
}
int main()
{
    freopen("hihocoder1167.in","r",stdin);
    freopen("hihocoder1167.out","w",stdout);
    init();
    work();
    return 0;
}