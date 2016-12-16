#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <fstream>
#include <time.h>
#include <stack>

using namespace std;

ifstream read;
ofstream write;

void solve()
{
	int x1, y1, x2, y2, count = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	if (x1 == x2)
		count = abs(y2 - y1) - 1;
	else
	{
		int min = x1 < x2 ? x1 : x2;
		int max = x1 > x2 ? x1 : x2;
		for (int i = min + 1; i < max; i++)
			if (abs((y2 - y1)*(i - x1)) % abs(x2 - x1) == 0)
				count++;
	}
	cout << count << endl;
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