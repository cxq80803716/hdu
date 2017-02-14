#include <stdio.h>


int main()
{
	long m,n,temp,i;
	long x,y;
	while(scanf("%ld%ld",&m,&n)!=EOF)
	{
		if(m>n)
		{
			temp=m;
			m=n;
			n=temp;
		}
		
		x=y=0;
		
		for(i=m;i<=n;i++)
		{
			if(i%2)
			y+=i*i*i;
			else
			x+=i*i;
		}
		
		printf("%ld %ld\n",x,y);
	}
	
	return 0;
}