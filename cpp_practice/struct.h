#pragma once
#include "..\cpp_practice\general_functions.h"
#include "..\cpp_practice\functions_using_structs.h"
#include "..\cpp_practice\class.h"

//$$$$$$$$$$$$$$$$$$$$$$ fractions $$$$$$$$$$$$$$$$$$$$$$$$$

struct fraction
{
public:
	void make_fract(int numerator, int denominator);
	void print_fract();
	int num;
	int den;
};

void fraction::make_fract(int numerator, int denominator)
{
	num = numerator;
	den = denominator;
}

void fraction::print_fract()
{
	cout << num << "/" << den << endl;
}