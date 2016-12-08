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

int main()
{
	clock_t start, finish;
	vector<int>v;
	//int j = 0;
	int n = 1024;
	start = clock();
	for (int i = 0;i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			
		}
	}
	finish = clock();
	cout << ((double)(finish - start)) / CLOCKS_PER_SEC << endl;
	//cout << CLOCKS_PER_SEC << endl;

	system("pause");
	return 0;
}