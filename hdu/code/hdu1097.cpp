#include <iostream>
using namespace std;
int main()
{
	int a, b, n;
	while (cin>>a>>b) {
		a %= 10;
		b %= 4;
		switch(b) {
		case 1:
			n = a%10;
			break;
		case 2:
			n = a*a%10;
			break;
		case 3:
			n = a*a*a%10;
			break;
		case 0:
			n = a*a*a*a%10;
			break;
		default:
			break;
		}
		cout<<n<<endl;
	}
	return 0;
}