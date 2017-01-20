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
	read.open("test.txt");
	vector<string>lines;
	int i = 1;
	while (!read.eof())
	{
		cout << "reading line " << i << endl;
		string line = "";
		getline(read, line);
		lines.push_back(line);
		i++;
	}
	read.close();
	i = 1;
	for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++, i++)
	{
		cout << "changing line " << i << endl;
		(*it).insert(0, "\"");
		(*it) += "\",";

	}
	i = 1;
	write.open("result.txt");
	write.clear();
	for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++, i++)
	{
		cout << "writimg line " << i << endl;
		write << *it << endl;

	}
	write.close();
	cout << "done!" << endl;

	system("pause");
	return 0;
}