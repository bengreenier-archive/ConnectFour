#include "Cell.h"
#include "../Control/Control.h"

Cell::Cell(int x,int y,int x2,int y2)
{
    isFill=false;
    Player=10;

    Cell::x=x;
    Cell::y=y;
    Cell::y2=y2;
    Cell::x2=x2;


    Filled=sf::Color(100,100,100);
    Empty=sf::Color(50,20,30);
    EmptyBorder=sf::Color(300,300,300);

    //ctor
}

void Cell::Fill()
{
    isFill=true;
    Player=Control::Get()->Turn;

    if (Player==1)
    Filled=sf::Color(246,255,0);

    if (Player==2)
    Filled=sf::Color(0,221,255);

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
    Filler=sf::Shape::Circle(((x+x2-3)/2),((y+y2-3)/2),((x2-x)/2)-3,Filled);//xyradcolor
    return Filler;
}


sf::Shape Cell::Boxer()
{
    Square=sf::Shape::Rectangle(x,y,x2,y2,Empty,3,EmptyBorder);//x1y1x2y2
    return Square;
}


bool Cell::IsInsideDimensions(int x,int y)
{

    if ((Cell::x<x)&&(Cell::x2>x)&&(Cell::y<y)&&(Cell::y2>y))
    return true;
    else
    return false;
}
