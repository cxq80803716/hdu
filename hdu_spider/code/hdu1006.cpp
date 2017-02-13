#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=12*60*60;
double hm,hs,ms,T_hm,T_hs,T_ms;
void init()
{
    double h,m,s;//角速度
    h=1.0/120;
    m=1.0/10;
    s=6;
    hm=m-h;hs=s-h;ms=s-m;//表示两个针分离的速度
    T_hm=360/hm;//表示时针和分针从重合到再次重合所花的时间，下面同理
    T_hs=360/hs;
    T_ms=360/ms;
    //printf("%.3lf %.3lf %.3lf\n",T_hm*11,T_hs*719,T_ms*59);
}
double Max(double a,double b,double c)
{
    return max(max(a,b),c);
}
double Min(double a,double b,double c)
{
    return min(min(a,b),c);
}
int main()
{
    init();
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        if(n<0)break;
        double i,j,k,a[6],p,q,ans=0;
        //两针分离到n所需的时间
        a[0]=n/hm;
        a[1]=n/hs;
        a[2]=n/ms;
        //两针合并到n所需的时间,等价于两针分离了360-n
        a[3]=(360-n)/hm;
        a[4]=(360-n)/hs;
        a[5]=(360-n)/ms;
        //每次所有的针从有重合到再次有重合至多有一段连续的段符合三针分离度大于n。
        for(i=0;i<=1.0*maxn;i+=T_hm)
        {
            for(j=0;j<=1.0*maxn;j+=T_hs)
            {
                if(j+a[1]>i+a[3])break;//p>=j+a[1]&&q<=i+a[3]=>p>q=>无效
                if(i+a[0]>j+a[4])continue;//与上同理
                for(k=0;k<=1.0*maxn;k+=T_ms)
                {
                    if(k+a[2]>i+a[3]||k+a[2]>j+a[4])break;
                    if(i+a[0]>k+a[5]||j+a[1]>k+a[5])continue;
                    p=Max(i+a[0],j+a[1],k+a[2]);//在这三个时间段刚好完成分离n度，所以取最大值才能保证全都分离n以上
                    q=Min(i+a[3],j+a[4],k+a[5]);//在这三个时间段刚好完成合并n度，所以取最小值才能保证全都未合并到n以内
                    if(q>p)
                        ans+=q-p;
                }
            }
        }
        printf("%.3lf\n",100.0*ans/maxn);
    }
    return 0;
}
