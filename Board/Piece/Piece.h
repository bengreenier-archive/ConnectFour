#ifndef PIECE_H
#define PIECE_H
#include <SFML/Graphics.hpp>

class Piece : sf::Shape
{
    public:
        Piece();
        sf::Shape GetPiece();
    protected:
    private:
        sf::Shape PieceR;
};

#endif // PIECE_H
