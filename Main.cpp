#include <iostream>
#include <SFML/Graphics.hpp>

#include "Board/Board.h"
#include "Control/Control.h"

int main()
{



    std::cout<<"This is ConnectFour\n";
    //new Board()->Structure[0][0]->Fill();  This is an example of how to fill a cell in a structure.
    //Board()->Drawer(Window);  This is how to draw the board


    // Create the main rendering window
    sf::RenderWindow Window(sf::VideoMode(800, 600, 32), "ConnectFour");
    Board Game(Window.GetHeight(),Window.GetWidth(),30);

    const sf::Input& InputStream = Window.GetInput();

    Control Controller();

    // Start game loop
    while (Window.IsOpened())
    {
        // Process events
        sf::Event Event;
        while (Window.GetEvent(Event))
        {
            // Close window : exit
            if ((Event.Type == sf::Event::Closed)||((Event.Type == sf::Event::KeyReleased)&&(Event.Key.Code == sf::Key::Escape)))
                Window.Close();



            if (Event.Type==sf::Event::MouseButtonPressed)
            {
                    Game.FillFromVector(Game.clickToPosition(InputStream.GetMouseX(),InputStream.GetMouseY()));
            }

        }

        // Clear the screen (fill it with black color)
        Window.Clear();

        //Draw
        Game.Drawer(Window);


        // Display window contents on screen
        Window.Display();
    }






}
