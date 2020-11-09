
#include "Shape.h"
#include "UserDraw.h"



int main()
{
    string shape;
    cout << "What's the shape are we drawing? (Rectangle / Circle / Triangle / Star / Flipped Star / Shuriken)" << endl;
    cin >> shape;
    UserDraw(shape); 
    /*
    Also, you can just use DrawShape<Shape>(position, {shape_parameters}, color)
    Examples"

    vector<int> position { 100, 230 , 230, 100, 340, 340 };
    DrawShape<Triangle>(position, RGB(255, 0, 0));

    vector<int> pos {500, 500};
    int innerR = 100;
    int outerR = 200;
    DrawShape<Star>(position, innerR, outerR, RGB(R, G, B));
    
    */
    return 0;
}

