#include "Check.h"

Check::Check()
{
     TotalCellCount=0;
     MaxPossibleCellsCount=0;
     TotalCellsPlayerOneCount=0;
     TotalCellsPlayerTwoCount=0;
    //ctor
}

void Check::TotalCells(int i)
{
    TotalCellCount=TotalCellCount+i;
}

void Check::MaxPossibleCells(int i)
{
    MaxPossibleCellsCount=i;
}


void Check::TotalCellsPlayerOne(int i)
{
    TotalCellsPlayerOneCount=TotalCellsPlayerOneCount+i;
}

void Check::TotalCellsPlayerTwo(int i)
{
    TotalCellsPlayerTwoCount=TotalCellsPlayerTwoCount+i;
}
