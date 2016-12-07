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

int max_arr(vector<int>* v)
{
	vector<int>& a = *v;
	int max = 0, n=a.size();
	for (int i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

void solve()
{
	int n = 0;
	cin >> n;
	vector<int>a;
	for (int i = 0; i < n; i++)
	{
		int temp=0;
		cin >> temp;
		a.push_back(temp);
	}
	vector<int>lcs(n, 1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				if (lcs[i] < lcs[j] + 1)
				{
					lcs[i] = lcs[j] + 1;
				}
			}
		}
	}
	//lcs array ready
	cout << max_arr(&lcs)<<endl;
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