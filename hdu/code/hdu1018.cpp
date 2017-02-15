#include<stdio.h>
#include<math.h>
double reback(int n)
{
	double cnt=0;
	for(int i=2;i<=n;i++)
	{
		cnt+=log10(i);
	}
	return cnt;
}

int main()
{
	int cas,n;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		printf("%d\n",(int)reback(n)+1);
	}
	return 0;
}