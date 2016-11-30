#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

unsigned digit_sum(unsigned n)
{
	unsigned sum = 0;
	while (n > 0)
	{
		sum += (n % 10);
		n /= 10;
	}
	return sum;
}

void check(unsigned a, unsigned b, pair<unsigned, unsigned>* p)
{
	pair<unsigned, unsigned>& result = *p;
	unsigned sum_a = digit_sum(a);
	unsigned sum_b = digit_sum(b);
	unsigned greater = 0;
	unsigned sum_greater = 0;
	if (sum_a == sum_b)
	{
		greater = a < b ? a : b;
		sum_greater = greater == a ? sum_a : sum_b;
	}
	else
	{
		greater = sum_a > sum_b ? a : b;
		sum_greater = greater == a ? sum_a : sum_b;
	}
	cout << "gr_sum: " << sum_greater << endl;
	if (sum_greater == result.second)
	{
		result.first == result.first < greater ? result.first : greater;
	}
	else
	{
		result.first = result.second > sum_greater ? result.first : greater;
		result.second = result.first == greater ? sum_greater : result.second;
	}
}

int main()
{
	unsigned n = 0;
	while (true) {
		cout << "Enter n:" << endl;
		cin >> n;
		pair<unsigned, unsigned>result;
		result.first = 1;
		result.second = 1;
		pair<unsigned, unsigned>* p = &result;
		unsigned sq_root = floor(sqrt(n));
		for (unsigned i = 1; i <= sq_root; i++)
		{
			if (n%i == 0)
			{
				cout << i << " x " << (n / i) << " ";
				check(i, n / i, p);
			}
		}

		cout << result.first << endl;
	}

	system("pause");
	return 0;
}