#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#define maxn 1000
#define maxm 10000
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

char key[110][110], lock[10010][1010];
int r, c, d, w, ans, tmpl, tmpr;
bool vis[1010][10110];

bool jg(int l, int r, int kd, int ld)
{
    int tmp = 0;
    for(int i = l;i <= r;i++)
    {
        if(key[kd][tmp] == '#'&&lock[ld][i] == '#')
            return false;
        tmp++;
    }
    return true;
}

bool jg2(int ll, int rr, int dd)
{
    int ddl = min(dd, d - 1), ddk = min(r - 1, r - 1 - (dd - d + 1));
    while(ddk >= 0&&ddl >= 0)
    {
        if(!jg(ll, rr, ddk, ddl))
            return false;
        ddk--;
        ddl--;
    }
    return true;
}

void dfs(int ll, int rr, int dd)
{
    if(ans == d + r)
        return;
    vis[ll][dd] = 1;
    bool flag = 0;
    int tmp = dd;
    while(!flag)
    {
        int ddl = min(tmp, d - 1), ddk = min(r - 1, r - 1 - (tmp - d + 1));
        flag = 0;
        while(ddk >= 0&&ddl >= 0)
        {
            if(!jg(ll, rr, ddk, ddl))
            {
                for(int j = ll;j >= 0;j--)
                {
                    if(!vis[j][tmp - 1]&&jg2(j, j + c - 1, tmp - 1))
                        dfs(j, j + c - 1, tmp - 1);
                    else
                        break;
                }
                for(int j = ll + 1;j <= (w - c);j++)
                {
                    if(!vis[j][tmp - 1]&&jg2(j, j + c - 1, tmp - 1))
                        dfs(j, j + c - 1, tmp - 1);
                    else
                        break;
                }
                flag = 1;
                break;
            }
            ddk--;
            ddl--;
        }
        if(!flag)
        {
            tmp++;
            for(int j = ll;j >= 0;j--)
            {
                if(!vis[j][tmp - 1]&&jg2(j, j + c - 1, tmp - 1))
                    dfs(j, j + c - 1, tmp - 1);
                else
                    break;
            }
            for(int j = ll + 1;j <= (w - c);j++)
            {
                if(!vis[j][tmp - 1]&&jg2(j, j + c - 1, tmp - 1))
                    dfs(j, j + c - 1, tmp - 1);
                else
                    break;
            }
        }
        if(tmp == d + r)
            break;
    }
    ans = max(ans, tmp);
}

void inits()
{
    ans = 0;
    mem(vis, 0);
    return;
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while(cas--)
    {
        scanf("%d%d%*c", &r, &c);
        for(int i = 0;i < r;i++)
            scanf("%s", key[i]);
        scanf("%d%d%*c", &d, &w);
        for(int i = 0;i < d;i++)
            scanf("%s", lock[i]);
        if(c > w)
        {
            printf("The key falls to depth 0.\n");
            continue;
        }
        inits();
        for(int i = 0;i <= (w - c);i++)
        {
            int rr = i + c - 1;
            int dd = 0;
            bool flag = 0;
            while(!flag)
            {
                int ddl = min(dd, d - 1), ddk = min(r - 1, r - 1 - (dd - d + 1));
                flag = 0;
                while(ddk >= 0&&ddl >= 0)
                {
                    if(!jg(i, rr, ddk, ddl))
                    {
                        for(int j = i;j >= 0;j--)
                        {
                            if(!vis[j][dd - 1]&&jg2(j, j + c - 1, dd - 1))
                                dfs(j, j + c - 1, dd - 1);
                            else
                                break;
                        }
                        for(int j = i + 1;j <= (w - c);j++)
                        {
                            if(!vis[j][dd - 1]&&jg2(j, j + c - 1, dd - 1))
                                dfs(j, j + c - 1, dd - 1);
                            else
                                break;
                        }
                        flag = 1;
                        break;
                    }
                    ddk--;
                    ddl--;
                }
                if(!flag)
                {
                    vis[i][dd] = 1, dd++;
                    for(int j = i;j >= 0;j--)
                    {
                        if(!vis[j][dd - 1]&&jg2(j, j + c - 1, dd - 1))
                            dfs(j, j + c - 1, dd - 1);
                        else
                            break;
                    }
                    for(int j = i + 1;j <= (w - c);j++)
                    {
                        if(!vis[j][dd - 1]&&jg2(j, j + c - 1, dd - 1))
                            dfs(j, j + c - 1, dd - 1);
                        else
                            break;
                    }
                }
                if(dd == d + r)
                    break;
            }
            ans = max(ans, dd);
            if(ans == d + r)
                break;
        }
        if(ans >= d + r)
            printf("The key can fall through.\n");
        else
            printf("The key falls to depth %d.\n", ans);
    }
    return 0;
}