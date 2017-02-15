#include<iostream>
#include<cstring>
#include<cmath> 

using namespace std ;

#define MAX 1000005
int num[ MAX ] ;

int judge( int n )
{
	int sum = n ; 
	while( n )
	{
		sum += n % 10 ;
		n /= 10 ;	
	}
	num[ sum ] = 1 ;
}

int main()
{
	int n ;
	memset( num , 0 , sizeof( num ) ) ;
	for( int i = 1 ; i < MAX; ++i )
	{
		if( !num[ i ] )
			cout  << i << endl ;
		judge( i ) ; 
		
	} 
}