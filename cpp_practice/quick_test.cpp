#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

void sieve(unsigned n,vector<bool>* p)
{
	vector<bool>&a = *p;
	a[0] = false;
	a[1] = false;
	for (unsigned i = 2; i * 2 <= n; i++)
		a[i * 2] = false;
	for (unsigned i = 3; i <= n; i += 2)
	{
		if (a[i])
		{
			for (unsigned j = 2; j*i <= n; j++)
				a[j*i] = false;
		}
	}
}

int main()
{
	unsigned n, m, max, min,count = 0;
	cin >> n >> m;
	max = n > m ? n : m;
	min = max == n ? m : n;
	m = 0;
	n = 0;
	vector<bool>a(max + 1, true);
	sieve(max, &a);
	for (unsigned i = min; i <= max; i++)
	{
		if (a[i])
		{
			if (m > 0)
			{
				n = i;
				if (n - m == 2)
				{
					count++;
				}
				m = n;
				n = 0;
			}
			else
				m = i;
		}
	}
	cout << count;

	system("pause");
	return 0;
}