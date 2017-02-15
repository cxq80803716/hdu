#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n,max;
	map<string , int> ballon;
	string color;
	string MaxColor;
	while(cin>>n)
	{
		if(n==0)
		{
			return 0;
		}
		ballon.clear();
		for(int i=0;i<n;i++)
		{
			cin>>color;
			ballon[color]++;
		}
		map<string, int>::iterator it;
		max=0;
		for(it=ballon.begin();it!=ballon.end();it++)
		{
			if(it->second>max)
			{
				max = it->second;
				MaxColor = it->first;
			}
		}
		cout<<MaxColor<<endl;
	}
}