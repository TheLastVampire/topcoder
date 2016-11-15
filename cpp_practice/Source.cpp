#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "..\cpp_practice\general_functions.h"
#include "..\cpp_practice\struct.h"
#include "..\cpp_practice\functions_using_structs.h"
#include "..\cpp_practice\class.h"


using namespace std;

//$$$$$$$$$$$$$$$$$$$ add fractions - uses fraction $$$$$$$$$$$$$$$$

fraction add_fractions(fraction fr1, fraction fr2)
{
	int num1, den1, num2, den2, den_lcm;
	num1 = fr1.num;
	den1 = fr1.den;
	num2 = fr2.num;
	den2 = fr2.den;
	den_lcm = lcm(den1, den2);
	fraction result;
	result.num = num1*(den_lcm / den1) + num2*(den_lcm / den2);
	result.den = den_lcm;
	int hcf_of_temp = gcd(result.num, result.den);
	result.num /= hcf_of_temp;
	result.den /= hcf_of_temp;

	return result;
}

//$$$$$$$$$$$$$$$$$$$$$$$  main  $$$$$$$$$$$$$$$$$$$$$$$$

int main()
{
	point p1, p2,p3;
	p1.get_point();
	p2.get_point();
	p3.get_point();

	cout << "dis: "<<line_point_distance(p3,p1,p2,true)<<endl;



	system("pause");
	return 0;
}

//first change committed to Git ;)
