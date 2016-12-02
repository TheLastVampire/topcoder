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

bool has_unwanted_quotes(string* str)
{
	int quote_count = 0, pos_quo_start = 0, pos_quo_end = 0;
	//find the col_start pos
	for (int i = 0; i < (*str).length(); i++)
	{
		if ((*str)[i] == '\'')
		{
			if (quote_count == 2)
			{
				pos_quo_start = i;
				quote_count = 0;
				break;
			}
			else
			{
				quote_count++;
			}
		}
	}
	//find the col_end pos
	for (int i = (*str).length() - 1; i > pos_quo_start; i--)
	{
		if ((*str)[i] == '\'')
		{
			pos_quo_end = i;
			break;
		}
	}
	//check for unwanted quotes
	for (int i = pos_quo_start + 1; i < pos_quo_end; i++)
	{
		if ((*str)[i] == '\'')
			return true;
	}
	return false;
}

void save_culprit_no(int row_no, vector<int>* v)
{
	vector<int>& culprit_rows = *v;
	culprit_rows.push_back(row_no);
}

//read test file rows into rows vector
void read_rows_from_test(vector<string>* v) {
	vector<string>& rows = *v;
	read.open("test.txt");
	for (int i = 0; !read.eof(); i++)
	{
		string str;
		getline(read, str);
		rows.push_back(str);
	}
	read.close();
	cout << "Done reading rows" << endl;
}

//read test file for culprit rows
void read_testfile_for_culprits(vector<int>* v)
{
	vector<int>& culprit_rows = *v;
	read.open("test.txt");
	for (int i = 0; !read.eof(); i++)
	{
		string str;
		getline(read, str);
		if (has_unwanted_quotes(&str))
		{
			cout << "culprit found!" << endl;
			cout << str << endl;
			save_culprit_no(i, &culprit_rows);
		}
	}
	read.close();
	cout << "Done reading test file for culprits" << endl;
}

//write culprit row nos to result
void write_culprit_nos_to_result(vector<int>* v)
{
	vector<int>& culprit_rows = *v;
	write.open("result.txt");
	write.clear();
	for (int i = 0; i < culprit_rows.size(); i++)
	{
		write << culprit_rows[i] << endl;
		cout << culprit_rows[i] << endl;
	}
	write.close();
	cout << "Done writing culprit no.s to result" << endl;
}

//find unwanted pos in str
void save_unwanted_quo_pos(vector<int>* v, string* str)
{
	vector<int>& pos = *v;
	int quote_count = 0, pos_quo_start = 0, pos_quo_end = 0;
	//find the col_start pos
	for (int i = 0; i < (*str).length(); i++)
	{
		if ((*str)[i] == '\'')
		{
			if (quote_count == 2)
			{
				pos_quo_start = i;
				quote_count = 0;
				break;
			}
			else
			{
				quote_count++;
			}
		}
	}
	//find the col_end pos
	for (int i = (*str).length() - 1; i > pos_quo_start; i--)
	{
		if ((*str)[i] == '\'')
		{
			pos_quo_end = i;
			break;
		}
	}
	//save for unwanted quote pos
	for (int i = pos_quo_start + 1; i < pos_quo_end; i++)
	{
		if ((*str)[i] == '\'')
		{
			pos.push_back(i);
		}
	}
}

//correct the test file
void correct_culprit_rows_on_test(vector<string>* sv, vector<int>* v)
{
	vector<string>& rows = *sv;
	vector<string> rows_with_original_culprits(rows.size(), "");
	vector<int>& culprit_rows = *v;
	for (int i = 0; i < culprit_rows.size(); i++)
	{
		int row_no = culprit_rows[i];
		//copy culprit row to rows_with_original_culprits
		rows_with_original_culprits[row_no] = rows[row_no];
		string str = rows[row_no];
		vector<int>pos;
		save_unwanted_quo_pos(&pos, &str);
		for (int j = 0; j < pos.size(); j++)
		{
			int pos_to_correct = pos[j];
			string quote = "'";
			str.insert(pos_to_correct, quote);
		}
		//str is now corrected. replace the corrupt string in rows
		rows[row_no] = str;
	}
	//compare corrections
	/*cout << "CHECKING CHECKING CHECKING CHECKING CHECKING CHECKING CHECKING ..." << endl;
	for (int i = 0; i < culprit_rows.size(); i++)
	{
		int row_no = culprit_rows[i];
		cout << rows[row_no] << endl;
		cout << rows_with_original_culprits[row_no] << endl;
		cout << endl;
	}*/
	//write the correct rows to test file
	write.open("test.txt");
	write.clear();
	for (int i = 0; i < rows.size(); i++)
	{
		write << rows[i] << endl;
		cout << rows[i] << endl;
	}
	write.close();
	cout << "DONE!!! DONE!!! DONE!!! DONE!!! DONE!!! DONE!!! DONE!!! DONE!!! DONE!!! " << endl;
	//DONE!!!
}

void read_culprit_nos_from_result(vector<int>* v)
{
	vector<int>& culprit_rows = *v;
	read.open("result.txt");
	while (!read.eof())
	{
		int temp;
		read >> temp;
		culprit_rows.push_back(temp);
	}
	read.close();
	cout << "Done reading culprit nos" << endl;
}

int main()
{
	vector<string>rows;
	vector<int>culprit_rows;
	
	read_rows_from_test(&rows);
	//read_testfile_for_culprits(&culprit_rows);
	read_culprit_nos_from_result(&culprit_rows);
	//write_culprit_nos_to_result(&culprit_rows);
	correct_culprit_rows_on_test(&rows, &culprit_rows);

	getchar();
	return 0;
}