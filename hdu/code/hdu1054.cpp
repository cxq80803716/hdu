#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;
#pragma comment(linker,"/STACK:102400000,102400000")
#define MAX   1505
int visit[MAX];//标记节点是否被访问过；
int ret[MAX];//标记n个节点的增广节点的编号
vector<int>map[MAX];//用stl模版中的向量存放邻接表
int find(int cur )//找增广路径
{
     for(int i=0;i<map[cur].size();i++)
     {
          int j=map[cur][i];
          if(!visit[j])//若j与cur相邻，且没有被标记
          {
               visit[j]=1;
               if(ret[j]==-1||find(ret[j]))//如果j未在前一个匹配M中，或者，j在匹配M中，但从j相邻的节点出发可以找到增广路
               {
                    ret[j]=cur;//则把cur放到匹配M中；
                    return 1;
               }
          }
     }
     return 0;
}
int main()
{
  // freopen("input.txt","r",stdin);
     int n,x,m,y;
     while(scanf("%d",&n)!=EOF)
     {
          for(int i=0;i<n;i++)map[i].clear();//注意要清零；
          for(int i=0;i<n;i++)
          {
               scanf("%d:(%d)",&x,&m);
               for(int j=0;j<m;j++)
               {
                    scanf("%d",&y);
                    map[x].push_back(y);//用向量存放双向邻接表
                    map[y].push_back(x);
               }
          }
          int sum=0;
          memset(ret,-1,sizeof(ret));//因为节点从0开始，所以要赋值为-1；
          for(int i=0;i<n;i++)//
          {
               memset(visit,0,sizeof(visit));
               sum+=find(i);//若有增广路，匹配数则加一
          }
          printf("%d\n",sum/2);//最小顶点覆盖 == 最大匹配（双向图）/2；
     }
   return 0;
}
