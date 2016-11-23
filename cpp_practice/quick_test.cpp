#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

void solve()
{
	unsigned long long n = 0;
	cin >> n;
	if (n == 1)
	{
		cout << 1 << endl;
		return;
	}
	unsigned long long x = floor((-3 + sqrt(9 + 8 * n)) / 2);
	unsigned long long by_walk = (n*(n + 1)) / 2;
	unsigned long long by_elev = 2 * (n - x);
	unsigned long long result = by_walk<by_elev ? by_walk : by_elev;
	cout << result << endl;
}

int main()
{
	/*int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)*/
		solve();

	system("pause");
	return 0;
}