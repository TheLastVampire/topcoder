#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include<cmath>

using namespace std;

//$$$$$$$$$$$$$ 2D point or physics vector  $$$$$$$$$$$

class point
{
private:
	int x;
	int y;
	void make_point(int x_cord, int y_cord)
	{
		x = x_cord;
		y = y_cord;
	}
public:
	//************** vector ADDITION -- + operator ****************
	point operator+(point p)
	{
		point temp;
		temp.x = p.x + x;
		temp.y = p.y + y;
		return temp;
	}
	//************** vector SUBTRACTION -- - operator ****************
	point operator-(point p)
	{
		point temp;
		temp.x = x - p.x;
		temp.y = y - p.y;
		return temp;
	}
	//************** vector DOT product -- * operator ****************
	int operator*(point p)
	{
		return x*p.x + y*p.y;
	}
	//************** vector CROSS product -- ^ operator ****************
	int operator^(point p)
	{
		return x*p.y - y*p.x;
	}
	//************** point to point distance --ex: p1.distance(p2)****************
	double distance(point p2)
	{
		return sqrt((x - p2.x)*(x - p2.x) + (y - p2.y)*(y - p2.y));
	}
	
	//******** read point from input --overloaded >> ********
	void get_point()
	{
		cout << "Enter the x and y co-ords of the point separated by whitespace:" << endl;
		cin >> x >> y;
	}
	//******** read point from input --overloaded >> ********
	void print_point()
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
	//************** dot of (A,B,C) find AB.AC eg:dot(A,B,C) ****************
	friend double distance(point p1, point p2);
	friend int dot(point A, point B, point C);
	friend int cross(point A, point B, point C);
	friend double line_point_distance(point C, point A, point B, bool isSegment);

};


