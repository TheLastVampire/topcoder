#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int temp_count = 1,temp_count_cross=1;

vector<int> max_cross_sub_arr(vector<int>* a, int low, int mid, int high)
{
	cout << "counting cross: " << temp_count_cross++ << endl;
	vector<int> result(3, -1);
	int l_sum = -999, sum = 0, l_max, r_max;
	for (int i = mid; i >= low; i--)
	{
		sum += (*a)[i];
		if (sum > l_sum)
		{
			l_sum = sum;
			l_max = i;
		}
	}

	int r_sum = -999;
	sum = 0;
	for (int i = mid + 1; i <= high; i++)
	{
		sum += (*a)[i];
		if (sum > r_sum)
		{
			r_sum = sum;
			r_max = i;
		}
	}
	result[0] = l_max;
	result[1] = r_max;
	result[2] = l_sum + r_sum;
	return result;
}

vector<int> max_sub_arr(vector<int>* a, int low, int high)
{
	cout << "counting max: " << temp_count++ << endl;
	vector<int>l, r, cross(3, -1);
	if (high == low)
	{
		r[0] = low;
		r[1] = high;
		r[2] = (*a)[low];
		return r;
	}
	else
	{
		int mid = (low + high) / 2;

		l = max_sub_arr(a, low, mid + 1);
		r = max_sub_arr(a, mid + 1, high);
		cross = max_cross_sub_arr(a, low, mid, high);

		if (l[2] >= r[2] && l[2] >= cross[2])
			return l;
		else
			if (r[2] >= l[2] && r[2] >= cross[2])
				return r;
			else
				return cross;

	}
}

int main()
{
	vector<int> a = { 13,-3,-25,20, -3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int low = 0, mid = 7, high = 15;
	vector<int> solution = max_sub_arr(&a, low, high);
	cout << solution[0] << " " << solution[1] << " " << solution[2];

	system("pause");
	return 0;
}