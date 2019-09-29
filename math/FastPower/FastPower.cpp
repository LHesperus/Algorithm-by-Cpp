#include <iostream>
using namespace std;

int FastPower(long long x, int pow,int mod)
{
	long long rst = 1;
	while (pow)
	{
		if (pow & 0x01)
		{
			rst = rst * x;
			rst %= mod;
		}
		x *= x;
		x %= mod;
		pow >>= 1;
	}

	return rst;
}

int main()
{
	int n = 10;
	cout << FastPower(2, 10,1e9) << endl;
	return 0;

}
