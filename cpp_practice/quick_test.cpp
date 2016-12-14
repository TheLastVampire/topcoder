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

struct lcs
{
	string z;
	map<char, int>x_ind;
	map<char, int>y_ind;

	lcs()
	{
		z = "?";
	}
};

int min_moves(string* s1, string* s2, lcs* long_com_substr)
{
	int x_prev = -1, y_prev = -1, count = 0;
	string& z = long_com_substr->z;
	map<char, int>& x_ind = long_com_substr->x_ind;
	map<char, int>& y_ind = long_com_substr->y_ind;

	//begin
	for (int i = 0; i < z.length(); i++)
	{
		int x = x_ind[z[i]] - x_prev - 1;
		int y = y_ind[z[i]] - y_prev - 1;
		count += max(x, y);
		x_prev = x_ind[z[i]];
		y_prev = y_ind[z[i]];
	}
	//tail
	int tail_x = (*s1).length() - x_prev - 1;
	int tail_y = (*s2).length() - y_prev - 1;
	count += max(tail_x, tail_y);
	return count;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

lcs l_c_s(string* str1, string* str2)
{
	string& s1 = *str1;
	string& s2 = *str2;

	map<char, int>x_ind;
	map<char, int>y_ind;

	string x = "?" + s1;
	string y = "?" + s2;

	vector<vector<int>>c;
	vector<vector<char>>m;
	for (int i = 0; i < x.length(); i++)
	{
		vector<int> temp(y.length(), 0);
		c.push_back(temp);
	}
	for (int i = 0; i < x.length(); i++)
	{
		vector<char> temp(y.length(), ' ');
		m.push_back(temp);
	}
	for (int i = 1; i < x.length(); i++)
	{
		for (int j = 1; j < y.length(); j++)
		{
			if (x[i] == y[j])
			{
				c[i][j] = max(c[i - 1][j], c[i][j - 1]) + 1;
				m[i][j] = '\\';
				x_ind[x[i]] = i - 1;
				y_ind[x[i]] = j - 1;
			}
			else
			{
				if (c[i - 1][j] > c[i][j - 1])
				{
					c[i][j] = c[i - 1][j];
					m[i][j] = '^';
				}
				else
				{
					c[i][j] = c[i][j - 1];
					m[i][j] = '<';
				}
			}
		}
	}

	//done building c,m
	string z = "";

	stack<char> st;
	for (int i = x.length() - 1, j = y.length() - 1; m[i][j] != ' ';)
	{
		if (m[i][j] == '\\')
		{
			st.push(x[i]);
			i--;
			j--;

		}
		else
		{
			if (m[i][j] == '^')
			{
				i--;
			}
			else
			{
				j--;
			}
		}
	}
	//done filling stack
	while (!st.empty())
	{
		z.push_back(st.top());
		st.pop();
	}
	lcs result;
	result.x_ind = x_ind;
	result.y_ind = y_ind;
	result.z = z;

	//cout << s1 << endl << s2 << endl << z;
	return result;
}

void solve()
{
	string str1 = "", str2 = "";
	int blank;
	ifstream read;
	read.open("test.txt");
	read >> blank >> blank;  //ignore the lengths
	read >> str1 >> str2;
	read.close();
	//cin >> blank >> blank;  //ignore the lengths
	//cin >> str1 >> str2;
	lcs common_str = l_c_s(&str1, &str2);
	cout << common_str.z << endl;
	cout << common_str.z.length() << endl;
	int result = min_moves(&str1, &str2, &common_str);

	cout << result << endl;
}

int main()
{
	int n = 1;
	//cin >> n;
	for (int i = 0; i < n; i++)
		solve();
	

	system("pause");
	return 0;
}