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

int min(int a, int b)
{
	return a < b ? a : b;
}

int dis(int a, int b)
{
	int k1 = 0, k2 = 0;
	if (a % 2 == 0)
		k1 = (a + 2) / 2;
	else
		k1 = (a + 1) / 2;
	if (b % 2 == 0)
		k2 = (b + 2) / 2;
	else
		k2 = (b + 1) / 2;
	return abs(k1 - k2);
}

int main()
{
	int n = 0, p = 0, a = 1;
	cin >> n >> p;
	cout << min(dis(a, p), dis(p, n));


	system("pause");
	return 0;
}