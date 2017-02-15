#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int test(double a,double b,double x,double y)
{

    if(a*b<x*y)
    return 0;
    if(a>x&&b>y)
    return 1;
    if(b<=y)
    return 0;

    double d=sqrt(x*x+y*y);
    double angle=acos(y/d)-acos(b/d);
    double h=x*cos(angle)+y*sin(angle);
    if(h>a)
    return 0;
    else
    return 1;
}
int main()
{
    int i,j;
    double a,b,x,y;
    int t;
    scanf("%d",&t);
    while(t--)
    {

     cin>>a>>b>>x>>y;
     if(a<b)
     swap(a,b);
     if(x<y)
     swap(x,y);
     if(test(a,b,x,y))
     printf("Escape is possible.\n");
     else
     printf("Box cannot be dropped.\n");
    }
    return 0;
}
