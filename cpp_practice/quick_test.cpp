#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

void solve()
{
	int n = 0;
	cin >> n;
	int x = floor((-3 + sqrt(9 + 8 * n)) / 2);
	int u = 2 * n;
	int w = ((x*(x + 1)) / 2) + 2 * (n - x);
	int result = u < w ? u : w;
	cout << result << endl;
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		solve();

	system("pause");
	return 0;
}