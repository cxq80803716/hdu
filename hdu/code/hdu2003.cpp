#include<stdio.h>
#include<math.h>
int main()
{
	double x,y;
	while(scanf("%lf",&x)!=EOF)
	{
	y=fabs(x);
	printf("%.2lf\n",y);
}
	return 0;
}
