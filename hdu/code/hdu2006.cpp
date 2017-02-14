#include <iostream>
using namespace std;
int main(){
	int n,b,i;
	while(cin>>n)
	{
		int r = 1;
		for (i = 0; i < n; i++) 
		{
			cin>>b;
			if (b % 2 == 1)
				r *= b;
		}
		cout<<r<<endl;
	}
	return 0;
}
