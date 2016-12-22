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

bool process_guid(string* str, int pos, vector<string>* v, set<string>* s)
{
	string& line = *str;
	vector<string>& guid = *v;
	set<string>& guid_set = *s;

	string gu = "";
	for (int i = pos + 1; i < line.length() && line[i] != '}'; i++)
	{
		gu.append(1, line[i]);
	}

	if (guid_set.find(gu) != guid_set.end())
	{
		cout << "DUPLICATE " << gu << endl;
		return true;
	}
	else
	{
		guid.push_back(gu);
		guid_set.insert(gu);
		return false;
	}

}

bool process_line(string* str, vector<string>* v, set<string>* s)
{
	string& line = *str;
	vector<string>& guid = *v;
	set<string>& guid_set = *s;

	if (line.find('{') != line.npos)
	{
		for (int ind = 0; ind < line.length(); ind++)
		{
			if (line[ind] == '{')
				if (process_guid(&line, ind, &guid, &guid_set))
				{
					return true;
				}
				else
				{
					return false;
				}
		}
	}
	else
	{
		return false;
	}
}

int main()
{
	vector<string>guid;
	set<string>guid_set;
	read.open("test.txt");
	int i = 1;
	while (!read.eof())
	{
		string line = "";
		getline(read, line);
		cout << "line " << i << " ..." << endl;
		if (process_line(&line, &guid, &guid_set))
		{
			char temp;
			cin >> temp;
			break;

		}
		i++;
	}

	read.close();


	system("pause");
	return 0;
}