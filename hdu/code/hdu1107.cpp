#include<stdio.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;

typedef struct nn
{
    int y,x;
}node;
typedef struct nnn
{
    char ID;
    int nenli,cofu,life;
    int fite,dir;
}people;

int inList[2][13][13],peopNumb[2][13][13],step;
people p[2][13][13][1005];
queue<node> head[2];
void setFite(people &pp)
{
    double f;
    if(pp.ID=='S')
         f=(0.5*pp.nenli+0.5*pp.cofu)*(pp.life+10)/100.0;
    else if(pp.ID=='W')
         f=(0.8*pp.nenli+0.2*pp.cofu)*(pp.life+10)/100.0;
    else f=(0.2*pp.nenli+0.8*pp.cofu)*(pp.life+10)/100.0;
    pp.fite= (int)f;
}
void moveTo(people pp,int flog,int y,int x)
{
    int n=peopNumb[flog][y][x];
    p[flog][y][x][++n]=pp;
    peopNumb[flog][y][x]++;
}
void countLoct(people &pp,int &y,int &x)
{
    if(pp.ID=='S'){
        if(pp.dir==0){
            if(y==12)pp.dir=1,y=11;
            else y+=1;
        }
        else {
            if(y==1)pp.dir=0,y=2;
            else y-=1;
        }
    }
    else if(pp.ID=='W'){
        if(pp.dir==0){
            if(x==12)pp.dir=1,x=11;
            else x+=1;
        }
        else {
            if(x==1)pp.dir=0,x=2;
            else x-=1;
        }
    }
    else if(pp.ID=='E')
    {
        if(pp.dir==0)
        {
            if(y==12&&x>1||x==12&&y>1)
                pp.dir=1,y-=1,x-=1;
            else if(y<12&&x<12) y+=1,x+=1;
        }
        else
        {
            if(y==1&&x<12||x==1&&y<12)
                pp.dir=0,y+=1,x+=1;
            else if(y>1&&x>1) y-=1,x-=1;
        }
    }
}
void GoFite(int flog)
{
    int ty,tx,i,j;
    node q,qq;
    for( i=1; i<=12; i++)
    for( j=1; j<=12; j++)
    inList[!flog][i][j]=0;
    while(!head[flog].empty())
    {
        q=head[flog].front(); head[flog].pop();
        int &n=peopNumb[flog][q.y][q.x];
        people &pp1=p[flog][q.y][q.x][1];
        people &pp2=p[flog][q.y][q.x][2];
        if(n==2&&pp1.ID!=pp2.ID)
        {
            pp1.life-=pp2.fite; pp2.life-=pp1.fite;
            if(pp1.life<=0&&pp2.life>0)
                  pp1=pp2, n--;
            else if(pp1.life>0&&pp2.life<=0)
                  n--;
            else if(pp1.life<=0&&pp2.life<=0)
                  n=0;
        }

        for( ; n>0; n--)
        {
            ty=q.y; tx=q.x;
            countLoct(p[flog][q.y][q.x][n],ty,tx);
            setFite(p[flog][q.y][q.x][n]);
            moveTo(p[flog][q.y][q.x][n],!flog,ty,tx);
            if(inList[!flog][ty][tx]==0)
            {
                qq.y=ty; qq.x=tx;
                head[!flog].push(qq);
                inList[!flog][ty][tx]=1;
            }
        }
    }
    step--;
    if(step)
    GoFite(!flog);
}
int main()
{
    int t,x,y,flog;
    char str[5];
    people s;
    node q;

    scanf("%d",&t);
    while(t--)
    {
        memset(inList,0,sizeof(inList));
        memset(peopNumb,0,sizeof(peopNumb));
        scanf("%d",&step);
        while(scanf("%s",str)>0&&str[0]!='0')
        {
            s.ID=str[0]; s.dir=0;
            scanf("%d%d%d%d%d",&y,&x,&s.nenli,&s.cofu,&s.life);
            int &n=peopNumb[0][y][x];
            p[0][y][x][++n]=s;
            setFite(p[0][y][x][n]);
            if(!inList[0][y][x])
            {
                 q.y=y; q.x=x; inList[0][y][x]=1;
                head[0].push(q);
            }
        }
        flog=step%2;
        GoFite(0);
        int m[3]={0},sum[3]={0};
        while(!head[flog].empty())
        {
            q=head[flog].front(); head[flog].pop();
            y=q.y; x=q.x;
            int n=peopNumb[flog][y][x];
            for( ; n>0; n--)
            {
                if(p[flog][y][x][n].ID=='S')m[0]++,sum[0]+=p[flog][y][x][n].life;
                if(p[flog][y][x][n].ID=='W')m[1]++,sum[1]+=p[flog][y][x][n].life;
                if(p[flog][y][x][n].ID=='E')m[2]++,sum[2]+=p[flog][y][x][n].life;
            }
        }
        printf("%d %d\n%d %d\n%d %d\n",m[0],sum[0],m[1],sum[1],m[2],sum[2]);
        printf("***\n");
    }
}
