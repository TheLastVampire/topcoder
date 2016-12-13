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

int max(int a, int b)
{
	return a > b ? a : b;
}

string lcs(string* str1, string* str2)
{
	string& s1 = *str1;
	string& s2 = *str2;

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
					c[i][j] = c[i][j-1];
					m[i][j] = '<';
				}
			}
		}
	}

	//done building c,m
	string z="";
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
	cout << s1 << endl << s2 << endl << z;
	return z;
}

int main()
{
	string str1 = "klsrmnp", str2 = "serimno";
	string z = lcs(&str1, &str2);

	//cout << z;

	system("pause");
	return 0;
}