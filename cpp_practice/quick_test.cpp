#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;


int main()
{
	int n = 0, sum = 0, result = 0;
	cin >> n;
	vector<int>a;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
	{
		if (i != 0 && a[i - 1] == a[i])
			continue;
		sum += a[i];
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] % a[i] == 0)
			{
				sum += a[j];
			}
			else
			{
				if (a[j] > a[i])
				{
					sum += (a[i] * (a[j] / a[i]));
				}
			}
		}
		if (sum > result)
		{
			result = sum;
			sum = 0;
		}
		else
		{
			sum = 0;
		}
	}
	cout << result;

	system("pause");
	return 0;
}