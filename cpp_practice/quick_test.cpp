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
	string HEAD = "http://ma.brazzers.com/scene/view/";
	vector<string>v;
	string arr[20];
	for (int i = 0; i < 20; i++)
		cin >> arr[i];
	for (int i = 0; i < 20; i++)
	{
		string url = HEAD + arr[i] + "/";
		v.push_back(url);
	}

	write.open("result.txt");
	write.clear();

	for (int i = 0; i < v.size(); i++)
		write << v[i] << endl;

	write.close();

	system("pause");
	return 0;
}