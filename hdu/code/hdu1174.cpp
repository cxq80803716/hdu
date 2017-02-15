#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "algorithm"
#include "iostream"

using namespace std;

#define eps 1e-6

struct node 
{
	double x , y , z ;
}line[ 3 ] ;

double chaji( node a , node b ) 
{
	double x1 = a.x ;
	double y1 = a.y ;
	double z1 = a.z ;
	double x2 = b.x ;
	double y2 = b.y ;
	double z2 = b.z ;
	double x = y1 * z2 - z1 * y2 ;
	double y = x1 * z2 - z1 * x2 ;
	double z = x1 * y2 - x2 * y1 ;
	return sqrt( x * x + y * y + z * z ) ;
}

int main()
{
	double h1 , r1 , x1 , y1 , z1 ;
	double h2 , r2 , x2 , y2 , z2 , x3 , y3 , z3 ;
	int n ;
	while( scanf( "%d" , &n ) != EOF )
	{
		while( n-- )
		{
			scanf( "%lf%lf%lf%lf%lf" , &h1 , &r1 , &x1 , &y1 , &z1 ) ;
			scanf( "%lf%lf%lf%lf%lf%lf%lf%lf" , &h2 , &r2 , &x2 , &y2 , &z2 , &x3 , &y3 , &z3 ) ;
			line[ 0 ].x = x3 , line[ 0 ].y = y3 , line[ 0 ].z = z3 ;
			line[ 1 ].x = x1 - x2 , line[ 1 ].y = y1 - y2 , line[ 1 ].z = z1 + h1 - r1 - ( h2 * 0.9 + z2 - r2 ) ;
			double d = chaji( line[ 0 ] , line[ 1 ] ) ;
			d /= sqrt( x3 * x3 + y3 * y3 + z3 * z3 ) ;
			if( d - r1 < eps )
				puts( "YES" );
			else
			 	puts( "NO" ) ;
		}
	}
	return 0; 
}
