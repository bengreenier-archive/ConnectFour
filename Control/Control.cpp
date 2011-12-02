#include "Control.h"

Control* Control::ControlPtr=NULL;

Control::Control()
{
    //ctor
    Turn=1;

}

void Control::Execute(const sf::Input& IS)
{

//



}


void Control::SetTurn()
{
    if (Turn==1)
        Turn=2;
    else if (Turn==2)
        Turn=1;

        std::cout<<"Turn set to "<<Turn<<"\n";
}


Control* Control::Get()
{
    if (ControlPtr==NULL)
        ControlPtr=new Control();

    return ControlPtr;

}
