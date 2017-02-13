#include <stdio.h>


int main()
{
    float num;
    int n,i,a,b,c;
    
    while(scanf("%d",&n)!=0)
    {	
    	a=b=c=0;
    	
    	if(n==0)
    	break;
    	
    	for(i=0;i<n;i++)
    	{
    		scanf("%f",&num);
    		
    		if(num<0)
    		a++;
    		else
    		{
    			if(num==0)
    			b++;
    			else
    			c++;
    		}
    	}
    	
    	printf("%d %d %d\n",a,b,c);
    }
	
	return 0;
}