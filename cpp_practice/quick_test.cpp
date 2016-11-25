#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

bool are_coprimes(unsigned a, unsigned b)
{
	if (((a | b) & 1) == 0)
		return false;
	while ((a & 1) == 0)
		a >>= 1;
	if (a == 1)
		return true;
	do
	{
		while ((b & 1) == 0)
			b >>= 1;
		if (b == 1)
			return true;
		if (a > b)
		{
			unsigned t = a;
			a = b;
			b = t;
		}
		b -= a;
	} while (b != 0);
	return false;
}

int gcd(int a, int b)
{
	if (a == 0 || b == 0 || a < 0 || b < 0)
	{
		cout << "Both numbers should belong to +Z";
		return -1;
	}
	if (b%a == 0)
		return a;
	return gcd(b%a, a);
}

int look_left(vector<int>* a, int i)
{
	if (i == 1)
		return -1;
	for (int j = i - 1; j >= 1; j--)
	{
		if (!are_coprimes((*a)[i], (*a)[j]))
		{
			return j;
		}
	}
	return -1;
}

int look_right(vector<int>* a, int i)
{
	int n = (*a).size() - 1;
	if (i == n)    //if i = n, there is nothing on the right!
		return -1;
	for (int j = i + 1; j <= n; j++)
	{
		if (!are_coprimes((*a)[i], (*a)[j]) )
		{
			return j;
		}
	}
	return -1;
}

int closest_or_min(vector<int>* a, int i, int j_left, int j_right)
{
	int d_left = abs(i - j_left);
	int d_right = abs(i - j_right);
	if (!(d_left == d_right))
	{
		return (d_right < d_left ? j_right : j_left);
	}
	else
	{
		return ((*a)[j_right] < (*a)[j_left] ? j_right : j_left);
	}
}

int main()
{
	int n = 0;
	cin >> n;
	vector<int>a;
	a.push_back(-999);
	for (int i = 0; i < n; i++)
	{		
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	//ignore a[0] !!!!
	for (int i = 1; i <= n; i++)
	{
		int j_left = look_left(&a, i);
		int j_right = look_right(&a, i);
		if (j_left != -1 && j_right != -1)
		{
			cout << closest_or_min(&a, i, j_left, j_right) << " ";
		}
		else
		{
			if (j_left != -1)
				cout << j_left << " ";
			else
			{
				if (j_right != -1)
					cout << j_right << " ";
				else
					cout << -1 << " ";
			}
		}
	}



	system("pause");
	return 0;
}