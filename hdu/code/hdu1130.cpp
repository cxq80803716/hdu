#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "algorithm"
#include "iostream"

using namespace std;
const int maxn = 105 ;
int a[ maxn ][ maxn ] ;
int b[ maxn ] ;
void catalan()
{
	int i , j , len , carry ,temp ;
	a[ 1 ][ 0 ] = b[ 1 ] =  1 ;
	len = 1 ;
	for( i = 2 ; i <= 100 ; i++ )
	{
		for( j = 0 ;  j < len ; j++ )
			a[ i ][ j ] = a[ i - 1 ][ j ] * ( 4 * ( i - 1 ) + 2 ) ; 
		carry = 0 ;
		for( j =  0 ; j < len ; j++ )
		{
				temp = a[ i ][ j ] + carry ;
				a[ i ][ j ] = temp % 10 ;
				carry = temp / 10 ;
		}
		while( carry )
		{
			a[ i ][ len++ ] = carry % 10 ;
			carry /= 10 ;
		}
		carry = 0  ;
		for( j = len - 1 ;  j >= 0 ; j-- )
		{
			temp = a[ i ][ j ] +  carry * 10 ;
			a[ i ][ j ]  =	temp / ( i + 1)  ;
			carry = temp % ( i + 1 ) ;
		}
		while( !a[ i ] [ len - 1 ] )
		{
			len-- ;
		}
		b[ i ] = len ;
	}
} 
			
		 
int main()
{
	catalan();
	int i , n ;
	while( ~scanf( "%d" ,& n) )
	{
		for( i = b[ n ] - 1 ; i >= 0 ; i-- )
			printf( "%d" , a[ n ][ i ] ) ;
		puts("") ;
	} 
	return 0;
}
