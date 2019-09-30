
#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void main(void) 
{
	cout << gcd(15, 20) << endl;
}
