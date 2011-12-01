#include "Cell.h"

Cell::Cell(int x,int y,int x2,int y2)
{
    isFill=false;

    Cell::x=x;
    Cell::y=y;
    Cell::y2=y2;
    Cell::x2=x2;


    Filled=sf::Color(100,100,100);
    Empty=sf::Color(50,20,30);
    EmptyBorder=sf::Color(300,300,300);
    Filler=sf::Shape::Circle(((x+x2)/2),((y+y2)/2),((x2-x)/2)-3,Filled);//xyradcolor
    Square=sf::Shape::Rectangle(x,y,x2,y2,Empty,3,EmptyBorder);//x1y1x2y2

    //ctor
}

void Cell::Fill()
{
    isFill=true;
}

bool Cell::IsFilled()
{
    if (isFill)
    return true;
    else
    return false;
}

bool Cell::IsEmpty()
{
    if (isFill)
    return false;
    else
    return true;
}

sf::Shape Cell::Drawer()
{
    return Filler;
}


sf::Shape Cell::Boxer()
{

    return Square;
}


bool Cell::IsInsideDimensions(int x,int y)
{

    if ((Cell::x<x)&&(Cell::x2>x)&&(Cell::y<y)&&(Cell::y2>y))
    return true;
    else
    return false;
}
