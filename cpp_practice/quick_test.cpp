#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <fstream>
#include <time.h>

using namespace std;

ifstream read;
ofstream write;

int get_max(int a, int b)
{
	return a > b ? a : b;
}

void solve()
{
	int len_x = 0, len_y = 0, max = 0;
	cin >> len_x >> len_y;
	vector<char>x,y;
	x.push_back(' ');
	y.push_back(' ');
	for (int i = 0; i < len_x; i++)
	{
		char temp;
		cin >> temp;
		x.push_back(temp);
	}
	for (int i = 0; i < len_y; i++)
	{
		char temp;
		cin >> temp;
		y.push_back(temp);
	}
	//done reading x and y
	vector<vector<int>>c;
	for (int i = 0; i <= len_x; i++)
	{
		vector<int>temp_vec(len_y+1, 0);
		c.push_back(temp_vec);
	}
	//done building c[][]
	for(int i=1;i<=len_x;i++)
		for (int j = 1; j <= len_y; j++)
		{
			if (x[i] == y[j])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				max = get_max(max, c[i][j]);
			}
			else
			{
				if (c[i - 1][j] >= c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
					max = get_max(max, c[i][j]);
				}
				else
				{
					c[i][j] = c[i][j - 1];
					max = get_max(max, c[i][j]);
				}
			}
		}
	cout << max << endl;
}

int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		solve();
	}

	system("pause");
	return 0;
}