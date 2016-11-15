#pragma once

#include<iostream>

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

