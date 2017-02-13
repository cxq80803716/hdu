#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    double x1,x2,y1,y2;
    while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF)
    {
        double ans=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        printf("%.2lf\n",ans);
    }
    return 0;
}