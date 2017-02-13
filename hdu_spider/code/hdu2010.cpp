#include <iostream>
using namespace std;
int main(){
	int m,n,i;
	while(cin>>m>>n)
	{
		if (m > n) 
		{
			int temp = m;
			m = n;
			n = temp;
		}
		bool flag = false;
		int count = 0;
		for (i = m; i <= n; i++) 
		{
			int a,b,c,s = i;
			a = s % 10;
			s = s / 10;
			b = s % 10;
			s = s / 10;
			c = s;
			s = a * a * a +b * b * b +c * c * c;
			if (s == i) 
			{
				if (count != 0)
					cout<<" ";
				cout<<i;
				flag = true;
				count++;
			}
		}
		if (flag)
			cout<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
