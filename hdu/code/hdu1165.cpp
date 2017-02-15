#include<bits/stdc++.h>
using namespace std;
long long A(long long m,long long n)
{
	if(n==0) return A(m-1,1);
	else if(m==0)return n+1;
	else if(m==1) return n+2;
	else if(m==2) return A(m,n-1)+2;
	else  if(m==3)return A(m,n-1)*2+3;
}
int main()
{
	long long n,m;
	while(~scanf("%lld%lld",&m,&n))
		printf("%lld\n",A(m,n));
    return 0;
}