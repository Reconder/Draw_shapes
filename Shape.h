#include <windows.h>
#include <vector>
#include <cmath>
using namespace std;



template <typename T>
void DrawShape(vector<int>& pos, COLORREF color)
{
	T shape(pos);
	shape.Draw(color);
}


template <typename T>
void DrawShape(vector<int>& pos, int a, COLORREF color)
{
	T shape(pos, a);
	shape.Draw(color);
}

template <typename T>
void DrawShape(vector<int>& pos, int a, int b, COLORREF color)
{
	T shape(pos, a, b);
	shape.Draw(color);
}


class Shape
{
public:
	vector<int> pointsX;
	vector<int> pointsY;
	vector<int> position;
	
	virtual void Draw(COLORREF color)
	{
		HWND console_handle = GetConsoleWindow();
		HDC device_context = GetDC(console_handle);
		HPEN pen = CreatePen(PS_SOLID, 5, color);
		SelectObject(device_context, pen);
		MoveToEx(device_context, pointsX[0], pointsY[0], NULL);
		for (int i = 1; i < pointsX.size(); i++)
		{
			LineTo(device_context, pointsX[i], pointsY[i]);
		}
		LineTo(device_context, pointsX[0], pointsY[0]);
		ReleaseDC(console_handle, device_context);
	};
};
//position - position of the center of the shape
class Rect : public Shape
{
public:
	Rect(vector<int>& pos, int a, int b)
	{
		position = pos;

		pointsX.push_back(position[0] - a / 2);
		pointsY.push_back(position[1] - b / 2);

		pointsX.push_back(position[0] + a / 2);
		pointsY.push_back(position[1] - b / 2);

		pointsX.push_back(position[0] + a / 2);
		pointsY.push_back(position[1] + b / 2);

		pointsX.push_back(position[0] - a / 2);
		pointsY.push_back(position[1] + b / 2);
	}
};


class Triangle : public Shape
{
public:
	//Just three random points
	Triangle(vector<int>& pos)
	{
		for (int i = 0; i < pos.size(); i += 2)
		{
			pointsX.push_back(pos[i]);
			pointsY.push_back(pos[i + 1]);
		}
	}
};

class Circle : public Shape
{
public:
	Circle(vector<int>& pos, int r)
	{
		position = pos;
		const double PI = 3.141592653589793238463;
		double angleIncrement = PI / 180;
		for (double angle = 0; angle < 360 * angleIncrement; angle += angleIncrement)
		{
			
			pointsX.push_back(position[0] + r * sin(angle));
			pointsY.push_back(position[1] + r * cos(angle));
			angle += angleIncrement;
		}
	};
	
};

class Star : public Shape
{
public:
	Star(vector<int>& pos, int innerR, int outerR)
	{
		position = pos;
		const double PI = 3.141592653589793238463;
		double angleIncrement = PI / 5;
		for (double angle = 0; angle < 10 * angleIncrement; angle += angleIncrement)
		{
			pointsX.push_back(position[0] + innerR * sin(angle));
			pointsY.push_back(position[1] + innerR * cos(angle));
			angle += angleIncrement;
			pointsX.push_back(position[0] + outerR * sin(angle));
			pointsY.push_back(position[1] + outerR * cos(angle));
		}
	}
};



class FlippedStar : public Shape
{
public:
	FlippedStar(vector<int>& pos, int innerR, int outerR)
	{
		position = pos;
		const double PI = 3.141592653589793238463;
		double angleIncrement = PI / 5;
		for (double angle = 0; angle < 10 * angleIncrement; angle += angleIncrement)
		{
			pointsX.push_back(position[0] + outerR * sin(angle));
			pointsY.push_back(position[1] + outerR * cos(angle));
			angle += angleIncrement;
			pointsX.push_back(position[0] + innerR * sin(angle));
			pointsY.push_back(position[1] + innerR * cos(angle));
		}
	}
};


class Shuriken : public Shape
{
public:
	Shuriken(vector<int>& pos, int innerR, int outerR)
	{
		position = pos;
		const double PI = 3.141592653589793238463;
		for (int i = 0; i < 5; i++)
		{
			double angle = 72 * i * PI / 180;
			pointsX.push_back(position[0] + outerR * sin(angle));
			pointsY.push_back(position[1] + outerR * cos(angle));
			angle += 72;
			pointsX.push_back(position[0] + innerR * sin(angle));
			pointsY.push_back(position[1] + innerR * cos(angle));

		}
	}
};



