#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, string> str;
string s, t;

int main()
{
	while(cin >> s && s != "XXXXXX")
	{
		t = s;
		sort(s.begin(), s.end());
		str[t] = s;
	}
	while(cin >> s && s != "XXXXXX")
	{
		bool flag = 0;
		t = s;
		sort(s.begin(), s.end());
		for(map<string, string>::iterator it=str.begin(); it!=str.end(); ++it)
			if(it->second == s)
			{
				cout << it->first << endl;
				flag = 1;
			}
			if(flag == 0)
				cout << "NOT A VALID WORD\n";
			cout << "******\n";
	}
	return 0;
}