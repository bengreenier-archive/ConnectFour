#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <SFML/Graphics.hpp>


class Cell : sf::Shape
{
    public:
        Cell(int x,int y,int x2,int y2);
        void        Fill();
        bool        IsFilled();
        bool        IsEmpty();
        sf::Shape   Drawer();
        sf::Shape   Boxer();
        bool        IsInsideDimensions(int x,int y);
    protected:
    private:
        bool            isFill;
        sf::Color       Filled;
        sf::Color       Empty;
        sf::Color       EmptyBorder;
        sf::Shape       Filler;
        sf::Shape       Square;
        int x,y,x2,y2;
};

#endif // CELL_H
