#include"stdio.h"
#include"string.h"


struct seg
{
    int l;
    int r;
    int n;
} T[150011];


void build(int l,int r,int k)
{
    int mid;
    if(l==r)
    {
        T[k].l=l;
        T[k].r=r;
        T[k].n=0;
        return ;
    }


    mid=(l+r)/2;
    T[k].l=l;
    T[k].r=r;
    T[k].n=0;
    build(l,mid,2*k);
    build(mid+1,r,2*k+1);
}


void insert(int n,int d,int k)
{
    int mid;
    if(T[k].l==T[k].r&&T[k].l==d)
    {
        T[k].n+=n;
        return ;
    }
    mid=(T[k].l+T[k].r)>>1;
    if(d<=mid)	insert(n,d,2*k);
    else		insert(n,d,2*k+1);
    T[k].n=T[2*k].n+T[2*k+1].n;
}


int ans;
void search(int l,int r,int k)
{
    int mid;
    //printf("l = %d,r = %d\n",l);
    if(T[k].l==l&&T[k].r==r)
    {
        ans+=T[k].n;
        return ;
    }
    mid=(T[k].l+T[k].r)>>1;
    if(r<=mid)		search(l,r,2*k);
    else if(l>mid)	search(l,r,2*k+1);
    else
    {
        search(l,mid,2*k);
        search(mid+1,r,2*k+1);
    }
}


int main()
{
    int Case,TT;
    int n;
    int i;
    int temp;
    char str[11];
    int a,b;
    scanf("%d",&TT);
    for(Case=1; Case<=TT; Case++)
    {
        scanf("%d",&n);

        build(1,n,1);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&temp);
            insert(temp,i,1);
        }

        printf("Case %d:\n",Case);

        while(scanf("%s",str),strcmp(str,"End"))
        {
            scanf("%d%d",&a,&b);
            if(strcmp(str,"Add")==0)		insert(b,a,1);
            else if(strcmp(str,"Sub")==0)	insert(-b,a,1);
            else
            {
                ans=0;
                search(a,b,1);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
