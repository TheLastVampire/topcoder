//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//
//using namespace std;
//
//
//#include "..\cpp_practice\general_functions.h"
//#include "..\cpp_practice\struct.h"
//#include "..\cpp_practice\functions_using_structs.h"
//#include "..\cpp_practice\class.h"
//
////$$$$$$$$$$$$$$$$$$$ add fractions - uses fraction $$$$$$$$$$$$$$
//
//fraction add_fractions(fraction fr1, fraction fr2)
//{
//	int num1, den1, num2, den2, den_lcm;
//	num1 = fr1.num;
//	den1 = fr1.den;
//	num2 = fr2.num;
//	den2 = fr2.den;
//	den_lcm = lcm(den1, den2);
//	fraction result;
//	result.num = num1*(den_lcm / den1) + num2*(den_lcm / den2);
//	result.den = den_lcm;
//	int hcf_of_temp = gcd(result.num, result.den);
//	result.num /= hcf_of_temp;
//	result.den /= hcf_of_temp;
//
//	return result;
//}
//
////%%%%%%%%%%%%%%%%%%%% temp functions for topcoder %%%%%%%%%%%
//
//double area_tri(point A, point B, point C)
//{
//	return abs(cross(A, B, C)) / 2;
//}
//
////%%%%%%%%%%%%%%%%%%%% topcoder function %%%%%%%%%%%
//
//double findArea(vector <int> x, vector <int> y)
//{
//	double result = 0;
//	vector<point> vertices;
//	int n = x.size();
//	for (int i = 0; i < n; i++)
//	{
//		point temp;
//		temp.make_point(x[i], y[i]);
//		vertices.push_back(temp);
//	}
//	for (int i = 1; i < n - 1; i++)
//	{
//		result += area_tri(vertices[0], vertices[i], vertices[i + 1]);
//	}
//	return result;
//}
//
////$$$$$$$$$$$$$$$$$$$$$$$  main  $$$$$$$$$$$$$$$$$$$$$$$$
//
////int main()
////{
////	int n = 0;
////	cin >> n;
////	if (n % 4 == 0 || n % 7 == 0)
////		cout << "YES" << endl;
////	else
////		cout << "NO" << endl;
////	
////	system("pause");
////	return 0;
////}
//
////first change committed to Git ;)
