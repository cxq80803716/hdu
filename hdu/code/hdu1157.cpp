#include <stdio.h>
#define wbx 10005
int a[wbx];
#include <string.h>
#include <algorithm>
using namespace std;
void solve()
{
    int n,i;
    while(~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d\n",a[n/2]);
	}
}
int main()
{
	solve();
	return 0;
}