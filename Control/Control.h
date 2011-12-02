#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Control
{
    public:
        Control();
        void Execute(const sf::Input& IS);
        int Turn;
        void SetTurn();
        static Control* Get();

    protected:
    private:
        static Control* ControlPtr;


};

#endif // CONTROL_H
