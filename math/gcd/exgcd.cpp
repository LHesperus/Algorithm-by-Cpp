
#include <stdio.h>
#include <iostream>
using namespace std;

int exgcd(int a, int b, int &x,int&y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	int g = exgcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;

	return g;

}
void main(void) 
{
	//求解不定方程99x+78y=6;
	int a = 99, b = 78, x, y, d = 6;
	int g = exgcd(a, b, x, y);
	if (d % g != 0)
	{
		cout << "err" << endl;
	}
	else
	{
		cout << a << "*" << x * (d / g) << "+" << b << "*" << y * (d / g) << "=" << d << endl;
	}

	//求解同余方程2x=1(mod 10)=>2x+10y=1,无解，2无逆元
	a = 2, b = 10, x, y, d = 1;
	g = exgcd(a, b, x, y);
	if (d % g != 0)
	{
		cout << "err" << endl;
	}
	else
	{
		cout << a << "*" << x * (d / g) << "+" << b << "*" << y * (d / g) << "=" << d << endl;
	}
	//求解同余方程3x=10(mod 4)=>3x+4y=10,有解
	a = 3, b = 4, x, y, d = 10;
	g = exgcd(a, b, x, y);
	if (d % g != 0)
	{
		cout << "err" << endl;
	}
	else
	{
		cout << a << "*" << x * (d / g) << "+" << b << "*" << y * (d / g) << "=" << d << endl;
	}
	//求解乘法逆元3x=1(mod 4)=>3x+4y=1
	a = 3, b = 4, x, y, d = 1;
	g = exgcd(a, b, x, y);
	if (d % g != 0)
	{
		cout << "err" << endl;
	}
	else
	{
		cout << a << "*" << x * (d / g) << "+" << b << "*" << y * (d / g) << "=" << d << endl;
	}

}
