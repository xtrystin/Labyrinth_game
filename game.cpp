#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Game.h"
#include "Menu.h"   //GameLogo()
using namespace std;


bool gotoMenu = false;




///////////////////// CLASS Tlevel - displaying level map ///////////////////////////////////////////////////////////////////////


//  STATIC   WINDOW SIZE: 50 x 20  //
const int Tlevel::Kheight = 20;
const int Tlevel::Kwidth = 50;
//  end STATIC  //


///////////////FUNC class Tlevel /////////////////////////

void Tlevel::victory(int level)
{
    system("cls");
    cout << "You passed level: " << level;
    Sleep(1000);
    system("cls");


    cout << "Level " << level << endl;          // essential
    for (int i = 0; i < Kwidth; i++)
        cout << "*";
    cout << endl;
}

//////////////MAPS//////////////
// MAP lvl 1
void Tlevel::lvlFirst(int x, int y)
{
    
  
    




    
    // IF FRUIT EATEN
    if (Player.x == Fruit.x && Player.y == Fruit.y)
    {
        victory(1);

       // gotoMenu = 1;
       // return;


        Player.x = 1;
        Player.y = 0;
        cout << "*";
    }


    
    // Logic                       
    if ( ( Player.x <= 0 || Player.x > 48 || Player.y < 0 || Player.y > 19 ) ||   ((Player.x != Fruit.x || Player.y != Fruit.y)) &&  Player.x != 2  
        && ( Player.y != 19 || Player.x == 1 ) && Player.x != 48 && ( Player.y != 3 || Player.x <= 5 ) && ( Player.x != 5 || Player.y > 13 ) )
    {
        Player.x = 1;
        Player.y = 0;
    }

    


    ////////PRINTING//////////
    if (x == Player.x && y == Player.y)
    {
        cout << 'p';
    }
    else if ( ( x == 1 && y == 0 ) || x == 2 || ( y == 19 && x != 1 ) || x == Kwidth-2 || ( y == 3 && x != 1 && x != 3 && x != 4 ) || ( x == 5 && y > 3 && y < 14 ) )
        cout << " ";
    else if (x == Fruit.x && y == Fruit.y)
    {
        cout << '+';
    }
    
    else
        cout << "&";

// MAP lvl 2
}void Tlevel::lvlSec(int x, int y)
{
              


    // TODO IF FRUIT HOVER  //did?
    if (Player.x == Fruit.x && Player.y == Fruit.y)
    {
        victory(2);

        //gotoMenu = 1;
       // return;


        Player.x = 1;
        Player.y = 19;
        cout << "*";
    }


    // LOGIC                    
    if ( ( Player.x <= 0 || Player.x > 48 || Player.y < 0 || Player.y > 19 ) ||   ( Player.x != Fruit.x || Player.y != Fruit.y) && Player.y != 19 && Player.x != 48 
        && (Player.y != 3 || Player.x < 2 ) && ( Player.x != 5 || Player.y < 3 || Player.y > 13 ) 
        && ( Player.y != 16  || Player.x < 26) && ( Player.x != 26 || Player.y > 16 || Player.y < 12 ) )
    {
        Player.x = 1;
        Player.y = 19;
    }


   



    if (x == Player.x && y == Player.y)
    {
        cout << 'p';
    }
    else if (y == 19 || ( y == 16 && x > 25 ) || ( x == 26 && y < 17 && y > 11 ) || ( x == Kwidth-2 ) || ( y == 3 && x != 1 ) || ( x == 5 && y > 3 && y < 14 ) )
        cout << " ";
    else if (x == Fruit.x && y == Fruit.y)
    {
        cout << '+';
    }
    
    else
        cout << "&";

}
///////////END MAPS////////////////





////////// DISPLAY MAP //////////////
void Tlevel::display(int index, bool first)
{
    cout << "Level " << index << endl;

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
                        if (first == true)
                            StartPosition(Player, Fruit, 1);     // Fruit and Player start position

                        lvlFirst(x, y);
                        break;
                    case 2:
                        if (first == true)
                            StartPosition(Player, Fruit, 2);

                        lvlSec(x, y);
                        break;
                    default:
                        cout << "ERROR: Tlevel > display() > switch ";
                        getchar();
                        getchar();
                        exit(3);
                }
                //cout << " ";
                
            }
        }
        cout << endl;
    }

    for (int i = 0; i < Kwidth; i++)
        cout << "*";
}
/////////END func display map//////////


// Fruit & Player start position///////
void Tlevel::StartPosition(Tplayer& p, Tfruit& f, int id)       //execute only once
{
    switch (id)
    {
    case 1:
        p.x = 1;            // 1 0
        p.y = 0;

        f.x = 6;
        f.y = 13;
        break;
    case 2:
        p.x = 1;            // 1 19
        p.y = 19;

        f.x = 25;
        f.y = 12;
        break;
    default:
        cerr << "ERROR class Tfruit > constructor > switch";

        getchar(); getchar();
        exit(3);

    }
}
/////END StartPosition//////////////


///////////////END FUNCs class Tlevel //////////////////////

///////////////////// END CLASS Tlevel ////////////////////////////////////////////////////////////////



///////////////////// CLASS Tmovement ////////////////////////////////////////////////////////////////


void Tmovement::Listener()               // todo check toupper  check if tab is clicked                                 //GetAsyncKeyState(VK_UP)
{
    /*
                                                                        switch (_getch())
                                                                        {
                                                                        case 'd':
                                                                            (*mov[0]) ();
                                                                            break;
                                                                        case 'a':
                                                                            (*mov[1]) ();
                                                                            break;
                                                                        case 'w':
                                                                            (*mov[2]) ();
                                                                            break;
                                                                        case 's':
                                                                            (*mov[3]) ();
                                                                            break;
                                                                        default:
                                                                            break;
                                                                        }
          
                                                                        */

    switch (_getch())       //todo array pointer
    {
    case 'd':
        moveRIGHT();
        break;
    case 'a':
        moveLEFT();                 
        break;
    case 'w':
        moveUP();
        break;
    case 's':
        moveDOWN();
        break;
    case '8':
        pause();
        break;
    case '9':
        retMenu();
        break;
    case '0':
        leave();
    default:
        break;
    }

   
}

void Tmovement::moveRIGHT()
{
    plvl->Player.x++;
   // cout << plvl->Player.x;
}
void Tmovement::moveLEFT()
{
    plvl->Player.x--;
    //cout << plvl->Player.y;
}
void Tmovement::moveUP()
{
    plvl->Player.y--;
   // cout << plvl->Player.y;
}
void Tmovement::moveDOWN()
{
    plvl->Player.y++;
  //  cout << plvl->Player.y;
}
void Tmovement::leave()
{
    system("cls");
    GameLogo();
    cout << "Leaving the game...";
    Sleep(1000);
    exit(0);
}
void Tmovement::pause()
{
    system("cls");
    GameLogo();
    cout << "PAUSED" << endl;
    system("pause");                                          //todo   getchar() doesnt work for first time,  lately works

    system("cls");
}
void Tmovement::retMenu()
{
    GameLogo();
    cout << "Returning to menu...";
    Sleep(1000);
    gotoMenu = 1;       //global
}





void Play(int choice)
{

    gotoMenu = false;
    /*
    if (argc == 2)
    {
        string a = argv[1];
        if (a == "-v")
        {
            cout << "Version: " << __DATE__ << " | " << __TIME__;
            return 0;
        }
            
    }


    int choice;
    cout << "MENU" << endl;
    cout << "1. First level" << endl;
    cout << "2. Second level" << endl;
    cout << "Choose level (1, 2): ";
    cin >> choice;
    if (choice != 1 && choice != 2)
    {
        cerr << "ERROR main > choice";
        exit(3);
    }
    */

    system("cls");
    GameLogo();
    cout << "Loading...";
    Sleep(1000);
    system("cls");
        


    Tlevel lvl;
    Tmovement Movement(&lvl);
    lvl.display(choice, true);                // true - begin (first display)         false - continue (next displays)
    cout << endl;
    cout << "Movement keys: WASD" << endl;
    cout << "Click 8 to pause" << endl;
    cout << "Click 9 to return to menu" << endl;
    cout << "Click 0 to exit" << endl;

    
    while (1)
    {
        while (_kbhit())
        {
            
            system("cls");
            
            Movement.Listener();

            if (gotoMenu == true)       //global
                return;

            lvl.display(choice, false);
            Sleep(10);
            cout << endl;
            cout << "Movement keys: WASD" << endl;
            cout << "Click 8 to pause" << endl;
            cout << "Click 9 to return to menu" << endl;
            cout << "Click 0 to exit" <<endl;
            // debugging:
            cout << "x: " << lvl.Player.x <<endl;
            cout << "y: " << lvl.Player.y << endl;
            //
            
            


        }
    }






    return;         //ret 1
}

