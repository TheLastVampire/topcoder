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

int main()
{
	int n = 0;
	cin >> n;
	vector<int>v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	//done reading v
	sort(v.begin(), v.end());
	int ans_1 = -1, ans_2 = -1;
	if (n == 1)
	{
		ans_1 = v[0] * 2;
		ans_2 = 1;
	}
	else
	{
		int min = v[0];
		int count = 1;
		for (int i = 1; i < v.size(); i++)
			if (v[i] == min)
				count++;
			else
				break;
		ans_2 = count;
		if (count > 1)
		{
			ans_1 = min*2;
		}
		else
		{
			if (count = v.size())
			{
				ans_1 = min;
			}
			else
			{
				ans_1 = min * 2 < v[count] ? min * 2 : v[count];
			}
		}
	}
	cout << ans_1 << " " << ans_2 << endl;

	system("pause");
	return 0;
}