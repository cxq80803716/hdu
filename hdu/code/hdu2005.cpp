#include <iostream>
#include <string>
using namespace std;
int strtoint(string s)
{
	int r = 0;
	for (int n = 0; n < s.size(); n++) 
	{
		int t = 1;
		for (int m = n + 1; m < s.size(); m++) 
		{
			t *= 10;
		}
		r += (s[n] - 48) * t;
	}
	return r;
}
int main()
{
	string s;
	int y,m,d,i;
	while(cin>>s)
	{
		string year,month,day;
		int count = 0,total_days = 0;
		for(i = 0; i < s.size(); i++)
		{
			if (s[i] == '/') 
			{
				count++;
				continue;
			}
			if (count == 0)
				year += s[i];
			else if (count == 1)
				month += s[i];
			else if (count == 2)
				day += s[i];
		}
		y = strtoint(year);
		m = strtoint(month);
		d = strtoint(day);
		for (i = 1; i < m; i++) 
		{
			if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) 
				total_days += 31;
			else if(i == 2)
				total_days += 28;
			else
				total_days += 30;
		}
		total_days += d;
		if (m > 2 && ((y % 100 == 0 && y % 400 == 0) || (y % 100 != 0 && y % 4 == 0)))//m>2 don't forget
			total_days += 1;
		cout<<total_days<<endl;		
	}
	return 0;
}