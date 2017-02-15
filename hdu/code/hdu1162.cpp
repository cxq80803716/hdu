#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int flag1=0;
double sum;
double arr_list[110][110];
struct Edge
{
     int point;
     double lowcost;
     int flag;
};
Edge edge[12100];
struct Point
{
     double x,y;
}point[110];
double prim(int n)
{
     int i,j,k=1,flag;
     double min,sum2=0;
     j=1;
     for(i=1;i<=n;i++)
     {
          if(i!=j)
          {
               edge[i].point=i;
               edge[i].lowcost=arr_list[j][i];
               edge[i].flag=0;
          }
     }
     edge[j].lowcost=0;
     edge[j].flag=1;
     for(i=2;i<=n;i++)
     {
          k=1;
          min=65535;
          flag=0;
          for(j=2;j<=n;j++)
          {
               if(edge[j].flag==0&&edge[j].lowcost<min)
               {
                    k=j;
                    min=edge[j].lowcost;
                    flag=1;
               }
          }
          if(!flag) return -1;
          sum2+=min;
          edge[k].flag=1;
          for(j=2;j<=n;j++)
          {
               if(edge[j].flag==0&&arr_list[k][j]<edge[j].lowcost)
               {
                    edge[j].point=k;
                    edge[j].lowcost=arr_list[k][j];
               }
          }
     }
     return sum2;
}
int main()
{
   // freopen("cin.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
         for(int i=1;i<=n;i++)
         {
              cin>>point[i].x>>point[i].y;
              arr_list[i][i]=65535;
         }
         for(int i=1;i<n;i++)
         {
              for(int j=i+1;j<=n;j++)
              {
                   arr_list[i][j]=sqrt(pow((point[i].x-point[j].x),2)+pow((point[i].y-point[j].y),2));
                   arr_list[j][i]=arr_list[i][j];
                   //cout<<arr_list[i][j]<<endl;
              }
         }
         sum=prim(n);
         printf("%.2lf\n",sum);
    }
    return 0;
}
