#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
	int sqrt_n = ceil(sqrt(n));
	if (n <= 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	if (n % 2 == 0)
		return false;
	else
	{
		for (int i = 3; i <= sqrt_n; i += 2)
		{
			if (n%i == 0)
				return false;
		}
	}
	return true;
}

int main()
{
	unsigned int n = 0;
	cin >> n;
	for (int i = 4; i <= n / 2 ; i++)
	{
		if (is_prime(i))
			continue;
		if (!is_prime(n - i))
		{
			cout << i << " " << n - i;
			break;
		}
	}

	//for(int i=1;i<=n;i++)
	//	if (is_prime(i))
	//	{
	//		cout << i << " ";
	//	}
	system("pause");
	return 0;
}