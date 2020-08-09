#include <iostream>
#include <Windows.h>

using namespace std;

/*
class Tplayer               //todo
{

};
*/



///////////////////// CLASS Tdisplay ////////////////////////////////////////////////////////////////
class Tdisplay
{
private:
    static const int Kwidth;
    static const int Kheight;
    int index;

   


public:

   // Tplayer Player;
                  
    int playerX = 1;            // class Tplayer
    int playerY = 0;            

    int FruitX = 6;               // todo: class Fruit
    int FruitY = 13;

    void lvlFirst(int, int);

    void display();
    Tdisplay(char k)    // constructor
    {
        index = k;
    }

};

//  STATIC  //
const int Tdisplay::Kheight = 20;
const int Tdisplay::Kwidth = 50;
//  end STATIC  //

///////////////FUNC class Tdisplay ////////////////////

// MAP lvl 1
void Tdisplay::lvlFirst(int x, int y)
{
    if (x == 2 || ( x == playerX && y == playerY ) || ( y == 19 && x != 1 ) || x == Kwidth-2 || ( y == 3 && x != 1 && x != 3 && x != 4 ) || ( x == 5 && y > 3 && y < 14 ) )
        cout << " ";
    else if (x == FruitX && y == FruitY)
    {
        cout << '+';
    }
    else
        cout << "&";
}


// DISPLAY MAP
void Tdisplay::display()
{
    for (int i = 0; i < Kwidth; i++)
        cout << "*";                

    cout << endl;
     
    for (int y = 0; y < Kheight; y++)
    {
        for (int x = 0; x < Kwidth; x++)
        {
            if (x == 0 || x == Kwidth - 1)
                cout << '*';
            else
            {
                switch (index)
                {
                    case 1:
                        lvlFirst(x, y);
                        break;
                    case 2:
                        cout << " ";
                        break;
                    default:
                        cout << "ERROR: Tdisplay > display() > switch ";
                        getchar();
                        getchar();
                        exit(0);
                }
                //cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < Kwidth; i++)
        cout << "*";
}
///////////////END FUNC class Tdisplay ////////////////////

///////////////////// END CLASS Tdisplay ////////////////////////////////////////////////////////////////








int main()
{
    Tdisplay lvl(1);

    while (1)
    {
        lvl.display();
        Sleep(1000);
        system("cls");
       
    }


    //do keyboard input




    return 0;
}

