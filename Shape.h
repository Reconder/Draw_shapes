#include <windows.h>
#include <vector>
#include <cmath>
using namespace std;


//Draw shape with vertices positions
template <typename T>
void DrawShape(vector<int>& pos, COLORREF color)
{
	T shape(pos);
	shape.Draw(color);
}

//Draw shape with one parameter
template <typename T>
void DrawShape(vector<int>& pos, int a, COLORREF color)
{
	T shape(pos, a);
	shape.Draw(color);
}

//Draw shape with two parameters
template <typename T>
void DrawShape(vector<int>& pos, int a, int b, COLORREF color)
{
	T shape(pos, a, b);
	shape.Draw(color);
}

//Base class for all shapes
class Shape
{
public:
	vector<int> pointsX; //X coordinates of the points used to draw shapes
	vector<int> pointsY; //Y coordinates of the points used to draw shapes
	
	//Draw the shape using color "color" and points that are defined in constructor of each shape. We draw lines between all consecutive points to get the shape.
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
//Rectangle class. Constructor (vector<int> pos, int a, int b) requires position (pos) of the center of the rectangle, width (a) and height (b).
class Rect : public Shape
{
public:
	Rect(vector<int>& pos, int a, int b)
	{
		pointsX.reserve(4);
		pointsY.reserve(4);

		pointsX.push_back(pos[0] - a / 2); //Upper left vertice
		pointsY.push_back(pos[1] - b / 2);

		pointsX.push_back(pos[0] + a / 2); //Upper right vertice
		pointsY.push_back(pos[1] - b / 2);

		pointsX.push_back(pos[0] + a / 2); //Lower right vertice
		pointsY.push_back(pos[1] + b / 2);

		pointsX.push_back(pos[0] - a / 2); //Lower left vertice
		pointsY.push_back(pos[1] + b / 2);
	}
};


//Connect class. Typically would be used to draw triangles. Constructor (vector<int> pos) requires coordinates of all vertices in one vector<int> in the following format: x1, y1, x2, y2, x3, y3...
class ConnectPoints : public Shape
{
public:
	//Just three random points
	ConnectPoints(vector<int>& pos)
	{
		pointsX.reserve(pos.size()/2);
		pointsY.reserve(pos.size() / 2);
		for (int i = 0; i < pos.size(); i += 2)
		{
			pointsX.push_back(pos[i]);
			pointsY.push_back(pos[i + 1]);
		}
	}
};

//Circle class. Constructor (vector<int> pos, int r) requires coordinates (pos) of the center of the circle and its radius (r).
class Circle : public Shape
{
public:
	Circle(vector<int>& pos, int r)
	{
		
		const double PI = 3.141592653589793238463;
		double angleIncrement = PI / 180;
		pointsX.reserve(360);
		pointsY.reserve(360);
		for (double angle = 0; angle < 360 * angleIncrement; angle += angleIncrement)
		{
			
			pointsX.push_back(pos[0] + r * sin(angle));
			pointsY.push_back(pos[1] + r * cos(angle));
			angle += angleIncrement;
		}
	};
	
};

//Star class. Constructor (vector<int> pos, int innerR, int outerR) requires coordinates (pos) of the center of the star and its inner (innerR) and outer (outerR) radii.
class Star : public Shape
{
public:
	Star(vector<int>& pos, int innerR, int outerR)
	{
		
		const double PI = 3.141592653589793238463;
		double angleIncrement = PI / 5;
		pointsX.reserve(10);
		pointsY.reserve(10);
		for (double angle = 0; angle < 10 * angleIncrement; angle += angleIncrement)
		{
			pointsX.push_back(pos[0] + innerR * sin(angle));
			pointsY.push_back(pos[1] + innerR * cos(angle));
			angle += angleIncrement;
			pointsX.push_back(pos[0] + outerR * sin(angle));
			pointsY.push_back(pos[1] + outerR * cos(angle));
		}
	}
};


//FlippedStar class. Constructor (vector<int> pos, int innerR, int outerR) requires coordinates (pos) of the center of the flipped star and its inner (innerR) and outer (outerR) radii.
class FlippedStar : public Shape
{
public:
	FlippedStar(vector<int>& pos, int innerR, int outerR)
	{
		
		const double PI = 3.141592653589793238463;
		double angleIncrement = PI / 5;
		pointsX.reserve(10);
		pointsY.reserve(10);
		for (double angle = 0; angle < 10 * angleIncrement; angle += angleIncrement)
		{
			pointsX.push_back(pos[0] + outerR * sin(angle));
			pointsY.push_back(pos[1] + outerR * cos(angle));
			angle += angleIncrement;
			pointsX.push_back(pos[0] + innerR * sin(angle));
			pointsY.push_back(pos[1] + innerR * cos(angle));
		}
	}
};

//Star class. Constructor (vector<int> pos, int innerR, int outerR) requires coordinates (pos) of the center of the shuriken and its inner (innerR) and outer (outerR) radii.
class Shuriken : public Shape
{
public:
	Shuriken(vector<int>& pos, int innerR, int outerR)
	{
		
		const double PI = 3.141592653589793238463;
		pointsX.reserve(10);
		pointsY.reserve(10);
		for (int i = 0; i < 5; i++)
		{
			double angle = 72 * i * PI / 180;
			pointsX.push_back(pos[0] + outerR * sin(angle));
			pointsY.push_back(pos[1] + outerR * cos(angle));
			angle += 72;
			pointsX.push_back(pos[0] + innerR * sin(angle));
			pointsY.push_back(pos[1] + innerR * cos(angle));

		}
	}
};



