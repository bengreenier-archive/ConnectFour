#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "Check/Check.h"
#include "Piece/Piece.h"

class Board
{
    public:
        Board(int height,int width,int size);
        sf::Vector2i clickToPosition(int foo,int bar);      //Return a click x,y to a Vector of the cell its in
        void Drawer(sf::RenderWindow& Window);
        std::vector < std::vector<Cell*> > Structure;       //This allows the board to ever expand, though, it current'y doesn't need to.
        void FillFromVector(sf::Vector2i in);
        void ExecuteChecks();
        bool IsGameover(sf::Vector2i in);
        bool IsGameover();
        int Winner();
        bool CellIsValid(int x,int y);
        sf::Vector2i DropToBottom(sf::Vector2i in);

    protected:

    private:
        void PushARow();                                    //Pushes a row of new Cells into Structure
        void Click_DropToBottom(sf::Vector2i in);           //If you don't click in the bottom of a row, drop cell to there
        int BoardTopLeft;
        int CellSize;
        int TotalCellsDrawn;
        int TotalRowsDrawn;
        Check   Checker;

        int WinnerCount;



};

#endif // BOARD_H
