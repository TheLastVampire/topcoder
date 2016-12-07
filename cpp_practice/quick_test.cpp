#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

ifstream read;
ofstream write;

unsigned MOD = 1000000007;

void print_fib(unsigned a, unsigned b, unsigned n)
{
	map<unsigned, unsigned> fib;
	fib[0] = a%MOD;
	fib[1] = b%MOD;
	for (unsigned i = 2; i <= n; i++)
	{
		fib[i] = (fib[i - 1] + fib[i - 2])%MOD;
	}
	cout << fib[n] << endl;
}

void solve()
{
	unsigned a = 0, b = 0, n = 0;
	cin >> a >> b >> n;
	switch (n)
	{
	case(0):
		cout << a << endl;
		break;
	case(1):
		cout << b << endl;
		break;
	default:
		print_fib(a, b, n);
		break;
	}
}

int main()
{
	unsigned n = 0;
	cin >> n;
	for (unsigned i = 0; i < n; i++)
		solve();

	system("pause");
	return 0;
}