#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define eps 1e-10
#define M 1000100
//#define LL __int64
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.1415926535898

const int maxn = 1010;
using namespace std;

struct point1
{
    double x, y, z;
};

point1 f[maxn], p[maxn];

const double R = 20000/PI;
double Distance(point1 a, point1 b)
{
    double s = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
    return s;
}

double Lenth(double a, double b)
{
    double c = sqrt(a*a - b*b);
    return c;
}

bool vis[maxn];
int main()
{
    int n, m;
    while(cin >>n>>m)
    {
        if(!n && !m)
            break;
       memset(vis, false, sizeof(vis));
        for(int i = 0; i < n; i++)
            cin >>f[i].x>>f[i].y>>f[i].z;
        for(int i = 0; i < m; i++)
            cin >>p[i].x>>p[i].y>>p[i].z;
        point1 t;
        t.x = 0.0;
        t.y = 0.0;
        t.z = 0.0;
        for(int i = 0; i < n; i++)
        {
            double d = Distance(f[i], t);
            double dd = Lenth(d, R);
            for(int j = 0; j < m; j++)
            {
                if(!vis[j])
                {
                    double s;
                    s = Distance(f[i], p[j]);
                    if(s <= dd)
                        vis[j] = true;
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; i++)
            if(vis[i])
                cnt ++;
        cout<<cnt<<endl;
    }
    return 0;
}


