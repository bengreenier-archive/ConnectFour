#include "Board.h"

Board::Board(int height,int width,int size)
{
    int rows=7;
    int cols=6;

    int offset = (width/2)-((size*rows)/2);

    BoardTopLeft=offset;
    CellSize=size;

    TotalRowsDrawn=0;
    //ctor
    PushARow();
    PushARow();
    PushARow();
    PushARow();
    PushARow();
    PushARow();
    //7 across, 6 down

}

void Board::PushARow()
{
    std::vector <Cell*> row;
    TotalCellsDrawn=0; // PER ROW, NOT PER SCREEN!

       int x=BoardTopLeft+((TotalCellsDrawn%8)*CellSize);
       int x2=x+CellSize;
       int y=BoardTopLeft+((TotalRowsDrawn%7)*CellSize);
       int y2=y+CellSize;



    row.push_back(new Cell(x,y,x2,y2));

    TotalCellsDrawn++;
       x=BoardTopLeft+((TotalCellsDrawn%8)*CellSize);
       x2=x+CellSize;
       y=BoardTopLeft+((TotalRowsDrawn%7)*CellSize);
       y2=y+CellSize;

    row.push_back(new Cell(x,y,x2,y2));

    TotalCellsDrawn++;
       x=BoardTopLeft+((TotalCellsDrawn%8)*CellSize);
       x2=x+CellSize;
       y=BoardTopLeft+((TotalRowsDrawn%7)*CellSize);
       y2=y+CellSize;

    row.push_back(new Cell(x,y,x2,y2));

    TotalCellsDrawn++;
       x=BoardTopLeft+((TotalCellsDrawn%8)*CellSize);
       x2=x+CellSize;
       y=BoardTopLeft+((TotalRowsDrawn%7)*CellSize);
       y2=y+CellSize;

    row.push_back(new Cell(x,y,x2,y2));

    TotalCellsDrawn++;
       x=BoardTopLeft+((TotalCellsDrawn%8)*CellSize);
       x2=x+CellSize;
       y=BoardTopLeft+((TotalRowsDrawn%7)*CellSize);
       y2=y+CellSize;

    row.push_back(new Cell(x,y,x2,y2));

    TotalCellsDrawn++;
       x=BoardTopLeft+((TotalCellsDrawn%8)*CellSize);
       x2=x+CellSize;
       y=BoardTopLeft+((TotalRowsDrawn%7)*CellSize);
       y2=y+CellSize;

    row.push_back(new Cell(x,y,x2,y2));

    TotalCellsDrawn++;
       x=BoardTopLeft+((TotalCellsDrawn%8)*CellSize);
       x2=x+CellSize;
       y=BoardTopLeft+((TotalRowsDrawn%7)*CellSize);
       y2=y+CellSize;

    row.push_back(new Cell(x,y,x2,y2));

    TotalCellsDrawn++;

    Structure.push_back(row);
    TotalRowsDrawn++;
}

void Board::Drawer(sf::RenderWindow& Window)
{

//Draw Boxes

    for (int x=0;x<Structure.size();x++)
        for (int y=0;y<Structure[x].size();y++)
                Window.Draw(Structure[x][y]->Boxer());

//Draw Circles
    for (int x=0;x<Structure.size();x++)
        for (int y=0;y<Structure[x].size();y++)
            if (Structure[x][y]->IsFilled())
                Window.Draw(Structure[x][y]->Drawer());


}


sf::Vector2f Board::clickToPosition(int foo,int bar)
{
    std::cout<<"Incoming Click Call @ "<<foo<<","<<bar<<"\n";

    for (int x=0;x<Structure.size();x++)
        for (int y=0;y<Structure[x].size();y++)
            if ((Structure[x][y]->IsEmpty())&&(Structure[x][y]->IsInsideDimensions(foo,bar)))
                return sf::Vector2f(x,y);


    return sf::Vector2f(-1,-1);
}


void Board::FillFromVector(sf::Vector2f in)
{
    if ((in.x!=-1)&&(in.y!=-1))
    Structure[in.x][in.y]->Fill();
}
