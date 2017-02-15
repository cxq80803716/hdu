#include <iostream>
using namespace std;
int GCD(int a, int b)
{
	int temp;
	if(a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (a%b == 0)
		return b;
	else 
		return GCD(b, a%b);
}
int LCM(int a, int b)
{
	return a/GCD(a, b)*b;
}
int main()
{
	int a, b;
	while (cin>>a>>b)
	{
		cout<<LCM(a, b)<<endl;
	}
	return 0;
}