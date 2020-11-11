

#include <vector>
#include <iostream>


void DrawRectangle(); 
void DrawCircle();
void DrawTriangle();
void DrawStar();
void DrawFlippedStar();
void DrawShuriken();

//"User Interface" if you can call it that way.
void UserDraw(string shape)
{
    if (shape == "Rectangle")
    {
        DrawRectangle();
    }
    if (shape == "Circle")
    {
        DrawCircle();
    }
    if (shape == "Triangle")
    {
        DrawTriangle();
    }
    if (shape == "Star")
    {
        DrawStar();
    }
    if (shape == "Flipped" || shape == "FlippedStar")
    {
        DrawFlippedStar();
    }
    if (shape == "Shuriken")
    {
        DrawShuriken();
    }
}



//Asks for the parameters of the rectangle and draws it.
void DrawRectangle()
{
    int a, b;
    vector<int> position{ 0, 0 };
    cout << "Enter the position (recommended: 500, 500) and sizes of the rectangle. (format: x, y, a, b)" << endl;
    cin >> position[0] >> position[1] >> a >> b;
    int R, G, B;
    cout << "What color? (format: R, G, B)" << endl;
    cin >> R >> G >> B;
    COLORREF color = RGB(R, G, B);
    DrawShape<Rect>(position, a, b, color);
}

//Asks for the parameters of the circle and draws it.
void DrawCircle()
{
    int r;
    vector<int> position{ 0, 0 };
    cout << "Enter the position (recommended: 500, 500) and radius of the circle. (format: x, y, r)" << endl;
    cin >> position[0] >> position[1] >> r;
    int R, G, B;
    cout << "What color? (format: R, G, B)" << endl;
    cin >> R >> G >> B;
    COLORREF color = RGB(R, G, B);
    DrawShape<Circle>(position, r, color);
}

//Asks for the parameters of the triangle and draws it.
void DrawTriangle()
{
    vector<int> pos{ 0, 0, 0, 0, 0, 0 };
    cout << "Enter the positions of all vertices of the triangle. (format: x1, y1, x2, y2, x3, y3)" << endl;
    cin >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5];
    //for (int i : position)
    //    cin >> i;
    int R, G, B;
    cout << "What color? (format: R, G, B)" << endl;
    cin >> R >> G >> B;
    COLORREF color = RGB(R, G, B);
    DrawShape<ConnectPoints>(pos, color);
}

//Asks for the parameters of the star and draws it.
void DrawStar()
{
    int innerR, outerR;
    vector<int> position{ 0, 0 };
    cout << "Enter the position (recommended: 500, 500) and inner and outer radii of the star. (format: x, y, innerR, outerR)" << endl;
    cin >> position[0] >> position[1] >> innerR >> outerR;
    int R, G, B;
    cout << "What color? (format: R, G, B)" << endl;
    cin >> R >> G >> B;
    COLORREF color = RGB(R, G, B);
    DrawShape<Star>(position, innerR, outerR, color);
}

//Asks for the parameters of the flippedstar and draws it.
void DrawFlippedStar()
{
    int innerR, outerR;
    vector<int> position{ 0, 0 };
    cout << "Enter the position (recommended: 500, 500) and inner and outer radii of the flipped star. (format: x, y, innerR, outerR)" << endl;
    cin >> position[0] >> position[1] >> innerR >> outerR;
    int R, G, B;
    cout << "What color? (format: R, G, B)" << endl;
    cin >> R >> G >> B;
    COLORREF color = RGB(R, G, B);
    DrawShape<FlippedStar>(position, innerR, outerR, color);
}

//Asks for the parameters of the shuriken and draws it.
void DrawShuriken()
{
    int innerR, outerR;
    vector<int> position{ 0, 0 };
    cout << "Enter the position (recommended: 500, 500) and inner and outer radii of the shuriken. (format: x, y, innerR, outerR)" << endl;
    cin >> position[0] >> position[1] >> innerR >> outerR;
    int R, G, B;
    cout << "What color? (format: R, G, B)" << endl;
    cin >> R >> G >> B;
    COLORREF color = RGB(R, G, B);
    DrawShape<Shuriken>(position, innerR, outerR, color);
}