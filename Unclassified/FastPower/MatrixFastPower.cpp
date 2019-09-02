#include <iostream>
#include <vector>
using namespace std;

//矩阵乘法 求模
vector<vector<int> > Matrix2dMul(vector<vector<int> > x, vector<vector<int> >y,int mod)
{
	int N = x.size();
;	vector<vector<int> > temp(N);
	for (unsigned int i = 0; i < N; i++)
	{
		temp[i].resize(N);
	}
	for (unsigned int i = 0; i < N; i++)
	{
		for (unsigned int j = 0; j < N; j++)
		{
			for (unsigned int k = 0; k < N; k++)
			{
				temp[i][j] += x[i][k] * y[k][j] % mod;
			}
			temp[i][j] %= mod;
		}
	}
	return temp;
}
//矩阵快速幂求模
vector<vector<int> > MatrixFastPower(vector<vector<int> > x, int pow, int mod)
{
	//初始化
	int N = x.size();
	vector<vector<int> > rst(N);
	for (unsigned int i = 0; i < N; i++)
		rst[i].resize(N);

	for(unsigned int i = 0; i < N; i++)//单位阵
			rst[i][i] = 1;
	//求模快速幂
	while (pow)
	{
		if (pow & 0x01)
		{
			rst = Matrix2dMul(rst, x, mod);
		}
		x = Matrix2dMul(x, x, mod);
		pow >>= 1;
	}
	return rst;
}
int main()
{
	vector<vector<int> > test(2);
	for (int i = 0; i < test.size(); i++)
	{
		test[i].resize(2);
	}
	test[0][0] = 1;
	test[0][1] = 2;
	test[1][0] = 3;
	test[1][1] = 4;
	
	test = MatrixFastPower(test, 10, 1e9);
	return 0;

}
