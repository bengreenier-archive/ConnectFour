#ifndef CHECK_H
#define CHECK_H
//#include "../Board.h"

class Check
{
    public:
        Check();
        void Execute();
        void TotalCells(int i);
        void TotalCellsPlayerOne(int i);
        void TotalCellsPlayerTwo(int i);
        void MaxPossibleCells(int i);

    protected:
    private:
        int TotalCellCount;
        int MaxPossibleCellsCount;
        int TotalCellsPlayerOneCount;
        int TotalCellsPlayerTwoCount;

};

#endif // CHECK_H
