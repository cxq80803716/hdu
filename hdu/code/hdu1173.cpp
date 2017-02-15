#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>


const int inf = 0x3f3f3f;
const int MAXN = 1e6+10;

using namespace std;

float a[MAXN];
float b[MAXN];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++){
            scanf("%f%f",&a[i],&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        printf("%.2f %.2f\n",a[n/2],b[n/2]);
    }
    //cout << "Hello world!" << endl;
    return 0;
}