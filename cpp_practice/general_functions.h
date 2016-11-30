#pragma once

#include<iostream>
#include<algorithm>


using namespace std;

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

int lcm(int a, int b)
{
	return (a*b) / gcd(a, b);
}

int to_decimal(int n, int base)
{
	int result = 0;
	int multiplier = 1;
	while (n > 0)
	{
		result += n % 10 * multiplier;
		n /= 10;
		multiplier *= base;
	}
	return result;
}

int from_decimal(int n, int base)
{
	int result = 0;
	int multiplier = 1;
	while (n > 0)
	{
		result += n % base * multiplier;
		n /= base;
		multiplier *= 10;
	}
	return result;
}

vector<int> factors(int n)
{
	vector <int> result;
	int sqrt_n = sqrt(n);
	for (int i = 1; i <= ceil(sqrt_n); i++)
	{
		if (n%i == 0)
		{
			result.push_back(i);
			result.push_back(n / i);
		}
	}
	sort(result.begin(), result.end());
	return result;
}

bool is_prime(unsigned int n)
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
		for (int i = 3; i <= sqrt_n; i+=2)
		{
			if (n%i == 0)
				return false;
		}
	}
	return true;
}

bool are_coprimes(unsigned a, unsigned b)
{
	if ((a | b) & 1 == 0)
		return false;
	while ((a&1)==0)
		a >>= 1;
	if (a == 1)
		return true;
	do
	{
		while ((b&1)==0)
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
	} while (b!=0);
	return false;
}

//sieve - find all primes in [0,n] 
//params - p: pointer to vector<bool>a(n+1,true) -- after exec, this vector holds a[i]=true for all primes i in [0,n]
void sieve(unsigned n, vector<bool>* p)
{
	vector<bool>&a = *p;
	a[0] = false;
	a[1] = false;
	for (unsigned i = 2; i * 2 <= n; i++)
		a[i * 2] = false;
	for (unsigned i = 3; i <= n; i += 2)
	{
		if (a[i])
		{
			for (unsigned j = 2; j*i <= n; j++)
				a[j*i] = false;
		}
	}
}