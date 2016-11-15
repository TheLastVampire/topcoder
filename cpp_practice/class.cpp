#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "class.h"

using namespace std;


//************** point to point distance --ex: distance(p1,p2)****************
double distance(point p1, point p2)
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}
int dot(point A, point B, point C)
{
	point AB = B - A;
	point AC = C - A;
	return AB*AC;
}
//************** cross of (A,B,C) find ABxAC eg:cross(A,B,C) ****************
int cross(point A, point B, point C)
{
	point AB = B - A;
	point AC = C - A;
	return AB^AC;
}
//************** distance from point C to the line/line segment AB ****************
double line_point_distance(point C, point A, point B, bool isSegment)
{
	double result = abs(cross(A, B, C) / distance(A, B));
	if (isSegment)
	{
		int cos_ext_angle_B = (B - A)*(C - B);
		int cos_ext_angle_A = (A - B)*(C - A);
		if (cos_ext_angle_B > 0)
			return distance(B, C);
		if (cos_ext_angle_A > 0)
			return distance(A, C);
	}
	return result;
}