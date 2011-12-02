#include "Board.h"
#include "../Control/Control.h"

Board::Board(int height,int width,int size)
{
    int rows=7;
    int cols=6;

    int offset = (width/2)-((size*rows)/2);

    WinnerCount=0;
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
    std::cout<<"Incoming Click Call @MousePos: "<<foo<<","<<bar<<"\n";

    for (int x=0;x<Structure.size();x++)
        for (int y=0;y<Structure[x].size();y++)
            if ((Structure[x][y]->IsEmpty())&&(Structure[x][y]->IsInsideDimensions(foo,bar)))
                return sf::Vector2f(y,x);


    return sf::Vector2f(-1,-1);
}


void Board::FillFromVector(sf::Vector2f in)
{
    std::cout<<"Clicked @Cell: "<<in.x<<","<<in.y<<"\n";


    if (in.y==(int)Structure.size()-1)
    {
        Structure[in.y][in.x]->Fill();

    }else if (CellIsValid(in.x,in.y+1))
    {
        if (Structure[in.y+1][in.x]->IsFilled())
            Structure[in.y][in.x]->Fill();
        else
            {
                    if (CellIsValid(in.x,in.y)){
                        for (int i=0;i<=Structure[in.y].size();i++){
                            if (CellIsValid(in.x,in.y+i)){
                                if ((Structure[in.y+i][in.x]->IsFilled())){
                                        Structure[in.y+i-1][in.x]->Fill();
                                }
                            }
                        }
                    }

            }

    }else if ((in.x==-1)&&(in.y==-1)){return;
    }else{
    std::cout<<"SEMATICAL ERROR WITH PROGRAM. CONTACT DEV.\n";
    }


        Control::Get()->SetTurn();

    return;

}

void Board::ExecuteChecks()
{
    //Update Total Cells Variables
    for (int x=0;x<Structure.size();x++)
        for (int y=0;y<Structure[x].size();y++)
        {
            Checker.MaxPossibleCells(Structure[x].size()+Structure[y].size());

            if (Structure[x][y]->IsFilled())
                Checker.TotalCells(1);

        }


    switch(Winner())
            {
                default:{std::cout<<"No Winner. Stalemate.\n";}break;
                case -1:{/*do nothing*/}break;
                case  1:{std::cout<<"Player One Wins.\n";}break;
                case  2:{std::cout<<"Player Two Wins.\n";}break;
            }



}


bool Board::IsGameover()
{
    /*
    int tally[8]={0,0,0,0,0,0,0,0};//used for seeing if a direction is valid
    sf::Vector2i tally_vectors[8];//used for keeping t

    for (int y=0;y<Structure.size();y++)
        for (int x=0;x<Structure[y].size();x++)
        {
            if (Structure[y][x]->IsFilled())
                {
                    for (int i=1;i<=2;i++)
                    {
                        if (CellIsValid(x+i,y))
                        {
                            if ((Structure[y][x+i]->IsFilled())&&(Structure[y][x+i]->Player==Structure[y][x]->Player))
                            {
                                tally[0]++;
                                tally_vectors[0].x=x+i;
                                tally_vectors[0].y=y;
                            }

                        }
                        if (CellIsValid(x,y+i))
                        {
                            if ((Structure[y+i][x]->IsFilled())&&(Structure[y+i][x]->Player==Structure[y][x]->Player))
                            {
                                tally[1]++;
                                tally_vectors[1].x=x;
                                tally_vectors[1].y=y+i;
                            }
                        }
                        if (CellIsValid(x+i,y+i))
                        {
                            if ((Structure[y+i][x+i]->IsFilled())&&(Structure[y+i][x+i]->Player==Structure[y][x]->Player))
                            {
                                tally[2]++;
                                tally_vectors[2].x=x+i;
                                tally_vectors[2].y=y+i;
                            }
                        }
                        if (CellIsValid(x-i,y-i))
                        {
                            if ((Structure[y-i][x-i]->IsFilled())&&(Structure[y-i][x-i]->Player==Structure[y][x]->Player))
                            {
                                tally[3]++;
                                tally_vectors[3].x=x-i;
                                tally_vectors[3].y=y-i;
                            }
                        }
                        if (CellIsValid(x-i,y))
                        {
                            if ((Structure[y][x-i]->IsFilled())&&(Structure[y][x-i]->Player==Structure[y][x]->Player))
                            {
                                tally[4]++;
                                tally_vectors[4].x=x-i;
                                tally_vectors[4].y=y;
                            }
                        }
                        if (CellIsValid(x,y-i))
                        {
                            if ((Structure[y-i][x]->IsFilled())&&(Structure[y-i][x]->Player==Structure[y][x]->Player))
                            {
                                tally[5]++;
                                tally_vectors[5].x=x;
                                tally_vectors[5].y=y-i;
                            }
                        }
                        if (CellIsValid(x-i,y+i))
                        {
                            if ((Structure[y+i][x-i]->IsFilled())&&(Structure[y+i][x-i]->Player==Structure[y][x]->Player))
                            {
                                tally[6]++;
                                tally_vectors[6].x=x-i;
                                tally_vectors[6].y=y+i;
                            }
                        }
                        if (CellIsValid(x+i,y-i))
                        {
                            if ((Structure[y-i][x+i]->IsFilled())&&(Structure[y-i][x+i]->Player==Structure[y][x]->Player))
                            {
                                tally[0]++;
                                tally_vectors[0].x=x+i;
                                tally_vectors[0].y=y-i;
                            }
                        }
                    }

                    //then scan tally to see if a direction contains 4
                    for (int i=0;i<8;i++)
                        if (tally[i]==4){WinnerCount=Structure[tally_vectors[i].y][tally_vectors[i].x]->Player; std::cout<<tally_vectors[i].x<<","<<tally_vectors[i].x<<"\n"; return true;}

                }
        }

    return false;*/


    int tempx,tempy;
    tempx=2;tempy=2;//just for testing
    return false;
}

bool Board::CellIsValid(int x,int y)
{

    if (x<=Structure.size())
    if ((x>=0)&&(y>=0)&&(y<Structure[y].size()))
    {
        //std::cout<<x<<","<<y<<"=True\n";
            return true;
    }
    else
    {
        //std::cout<<x<<","<<y<<"=False\n";
        return false;
    }

}


int Board::Winner()
{
    //IsGameover has issues
    if (IsGameover())
    {
        return WinnerCount;
        //std::cout<<"Game is over..\n";
    }

    return -1;
}


