#include "Triangle.h"


int triangle(int a, int b, int c)
{
	if( a < 0 || a > 200)return InvalidInput;
	if( b < 0 || b > 200)return InvalidInput;
	if( c < 0 || c > 200)return InvalidInput;

	int match = (a==b) + (b==c) + (c==a);
	if ( a + b <= c || b + c <= a || a + c <= b)return NotTriangle;
	if( match ==1 ) return IsIsosceles;
	if( match >1 ) return IsEquilateral;
	return IsScalene;
}

