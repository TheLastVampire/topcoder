#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	unsigned n = 0, x = 0;
	cin >> n;
	vector<unsigned>count(100001, 0);
	set<unsigned>s;
	for (unsigned i = 0; i < n; i++)
	{
		cin >> x;
		if (s.find(x) == s.end())
		{
			s.insert(x);
			count[x]++;
		}
		else
		{
			count[x]++;
		}
	}

	unsigned long even = 0, odd = 0;
	for (set<unsigned>::iterator it = s.begin(); it != s.end(); it++)
	{
		unsigned temp = *it;
		if (temp % 2 == 0)
			even += temp*count[temp];
		else
			odd += temp*count[temp];
	}

	cout << (even > odd ? even : odd);

	system("pause");
	return 0;
}