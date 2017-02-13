#include <stdio.h>
#include <string.h>
#include <math.h>

int n,m,t;
char map[10][10];
int flag;
int di,dj,wall;
int to[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

void dfs(int si,int sj,int cnt)//深搜
{
    int i,tem;
    if(si>n || sj>m || si<=0 || sj <= 0)//出界
        return ;
    if(cnt == t && si == di && sj == dj)//到达终点
        flag = 1;
    if(flag)
        return ;
    int s1 = si-di;
    int s2 = sj-dj;
    if(s1<0)
        s1=-s1;
    if(s2<0)
        s2=-s2;
    tem = t-cnt - s1 - s2;
    if(tem<0 || tem&1)//看剩下的时间能能否到达终点，tem&1则是判断其是否偶数，根据LCY的奇偶性剪枝可得tem必须是偶数，是奇数则不行
        return;
    for(i = 0; i<4; i++)
    {
        if(map[si+to[i][0]][sj+to[i][1]]!='X')
        {
            map[si+to[i][0]][sj+to[i][1]]='X';//走过的地方变为墙
            dfs(si+to[i][0],sj+to[i][1],cnt+1);
            map[si+to[i][0]][sj+to[i][1]]='.';//迷宫还原，以便下次广搜
        }
    }
    return ;
}

int main()
{
    int i,j,si,sj;
    while(~scanf("%d%d%d%*c",&n,&m,&t))
    {
        if(!n && !m && !t)
            break;
        wall = 0;
        for(i = 1; i<=n; i++)
        {
            for(j = 1; j<=m; j++)
            {
                scanf("%c",&map[i][j]);
                if(map[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                else if(map[i][j] == 'D')
                {
                    di = i;
                    dj = j;
                }
                else if(map[i][j] == 'X')
                    wall++;
            }
            getchar();
        }
        if(n*m-wall<=t)//t是代表要走的步数，步数加墙数必须小于总格子数的，因为所有格子中还包括了S和D，这是剪枝
        {
            printf("NO\n");
            continue;
        }
        flag = 0;
        map[si][sj] = 'X';//出发点是不可能再走的了，变为墙
        dfs(si,sj,0);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
