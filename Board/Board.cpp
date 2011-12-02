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
            return;

    }else if ((in.x==-1)&&(in.y==-1)){return;
    }else{
    std::cout<<"SEMATICAL ERROR WITH PROGRAM. CONTACT DEV.\n";
    }

    std::cout<<"IsGameover for this cell returned: "<<IsGameover(in.x,in.y)<<"\n";
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


bool Board::IsGameover(int incomingX,int incomingY)
{
    int INIT_X=incomingX,INIT_Y=incomingY,AMOUNTTOWIN=4;
    int checkX =    INIT_X;//
    int checkY =    INIT_Y;//
    int orientX =   0;//
    int orientY =   0;//
    int counter =   1;//to count intself as a slot

    std::cout<<"Incoming Coords are "<<INIT_X<<","<<INIT_Y<<"\n";

    if (!CellIsValid(INIT_X,INIT_Y))
    {
        std::cout<<"\tCell is Reading as invalid\n";
        return false;
    }

    for (int dir=0; dir<8; dir++){

            std::cout<<"\t\tDirection is "<<dir<<"\n";

        switch(dir){
            case 0:
                orientX = -1;
                orientY = -1;
                break;
            case 1:
                orientX = 0;
                orientY = -1;
                break;
            case 2:
                orientX = 1;
                orientY = -1;
                break;
            case 3:
                orientX = 1;
                orientY = 0;
                break;
            case 4:
                orientX = 1;
                orientY = 1;
                break;
            case 5:
                orientX = 0;
                orientY = 1;
                break;
            case 6:
                orientX = -1;
                orientY = 1;
                break;
            case 7:
                orientX = -1;
                orientY = 0;
                break;
            }

            checkX =    INIT_X;
            checkY =    INIT_Y;
            counter=    1;

            for (int i=0;i<AMOUNTTOWIN;i++)
            {
                checkX+=orientX;
                checkY+=orientY;
                if (CellIsValid(checkX,checkY))
                {
                    std::cout<<"\t\t  Checking Cell is valid, @ "<<checkX<<","<<checkY<<"\n";
                    if (Structure[checkY][checkX]->IsFilled())
                    {
                        std::cout<<"\t\t\tCell is Filled\n";
                        std::cout<<"\t\t\t  Is "<<Structure[INIT_Y][INIT_X]->Player<<" == "<<Structure[checkY][checkX]->Player<<" ?\n";
                        if (Structure[INIT_Y][INIT_X]->Player==Structure[checkY][checkX]->Player)
                        {
                                counter++;
                                std::cout<<"\t\t\t\tCell is Of Same Color,Counter="<<counter<<"\n";

                                if (counter == AMOUNTTOWIN)
                                {
                                        WinnerCount = Structure[INIT_Y][INIT_X]->Player;//set who won war winners color
                                        std::cout<<"innerds";
                                        break;

                                }else{break;}

                        }
                    }else{std::cout<<"\t\t\tNo. Empty Cell.\n";}

                }
            }


        }



return false;
}


bool Board::CellIsValid(int x,int y)
{

    if (y<Structure.size())
    if ((x>=0)&&(y>=0)&&(x<Structure[y].size()))
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
    //if (IsGameover(0,0))
    {
        //return WinnerCount;
        //std::cout<<"Game is over..\n";
    }

    return -1;
}


