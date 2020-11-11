
#include "Shape.h"
#include "UserDraw.h"



int main()
{
    string shape;
    cout << "What's the shape are we drawing? (Rectangle / Circle / Triangle / Star / FlippedStar / Shuriken)" << endl;
    cin >> shape;
    UserDraw(shape); 
    /*
    Also, you can just use DrawShape<Shape>(position, {shape_parameters}, color)
    Examples:

    vector<int> position { 100, 230 , 230, 100, 340, 340 };
    DrawShape<Triangle>(position, RGB(255, 0, 0));

    vector<int> pos {500, 500};
    int innerR = 100;
    int outerR = 200;
    DrawShape<Star>(position, innerR, outerR, RGB(R, G, B));
    

    Available shapes and their parameters:
    DrawShape<Rectangle>(vector<int> position, int width, int height, COLORREF color);
    DrawShape<Circle>(vector<int> position, int radius, COLORREF color);
    DrawShape<Triangle>(vector<int> positions, COLORREF color);
    DrawShape<Star>(vector<int> position, int innerRadius, int outerRadius, COLORREF color);
    DrawShape<FlippedStar>(vector<int> position, int innerRadius, int outerRadius, COLORREF color);
    DrawShape<Shuriken>(vector<int> position, int innerRadius, int outerRadius, COLORREF color);

    */
    return 0;
}

