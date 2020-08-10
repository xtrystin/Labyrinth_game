#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;


class Tplayer;
class Tfruit;
class Tlevel;

                        //todo namespace: Tplayer, Tfruit
class Tplayer               
{
public:         // todo private
    unsigned int x;           
    unsigned int y;
    


};



class Tfruit
{
public:             //todo private
    unsigned int x;
    unsigned int y;



   // Tfruit(int id);   // constructor

};




///////////////////// CLASS Tlevel - displaying level map ///////////////////////////////////////////////////////////////////////
class Tlevel
{
private:
    static const int Kwidth;
    static const int Kheight;
               

    Tfruit Fruit;
    


    void lvlFirst(int, int);
    void lvlSec(int, int);
    void StartPosition(Tplayer&, Tfruit&, int);
    void victory(int);


public:

    Tplayer Player;

    void display(int, bool);
                                                                                   
                                                                                                                                                                                                                              
                                                                                            
    //Tlevel() {};
};

//  STATIC   WINDOW SIZE: 50 x 20  //
const int Tlevel::Kheight = 20;
const int Tlevel::Kwidth = 50;
//  end STATIC  //


///////////////FUNC class Tlevel /////////////////////////

void Tlevel::victory(int level)
{
    system("cls");
    cout << "You passed level: " << level;
    Sleep(5000);
}

//////////////MAPS//////////////
// MAP lvl 1
void Tlevel::lvlFirst(int x, int y)
{
    // todo logic                       
    //if ( ( Player.x <= 0 || Player.x > 48 || Player.y < 0 || Player.y > 19 ) ||  )
    //{
      //  Player.x = 1;
        //Player.y = 0;
   // }
   
    
    
    
    
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
                                                                                                  

    // LOGIC                     
    if ( ( Player.x <= 0 || Player.x > 48 || Player.y < 0 || Player.y > 19 ) || ( Player.x != Fruit.x || Player.y != Fruit.y) && Player.y != 19 && Player.x != 48 
        && (Player.y != 3 || Player.x < 2 ) && ( Player.x != 5 || Player.y < 3 || Player.y > 13 ) 
        && ( Player.y != 16  || Player.x < 26) && ( Player.x != 26 || Player.y > 16 || Player.y < 12 ) )
    {
        Player.x = 1;
        Player.y = 19;
    }


    // TODO IF FRUIT HOVER
    if (Player.x == Fruit.x && Player.y == Fruit.y)
    {
        victory(2);

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
        p.x = 1;
        p.y = 0;

        f.x = 6;
        f.y = 13;
        break;
    case 2:
        p.x = 26;            // 1 19
        p.y = 16;

        f.x = 25;
        f.y = 12;
        break;
    default:
        cout << "ERROR class Tfruit > constructor > switch";

        getchar(); getchar();
        exit(3);

    }
}
/////END StartPosition//////////////


///////////////END FUNCs class Tlevel //////////////////////

///////////////////// END CLASS Tlevel ////////////////////////////////////////////////////////////////


class Tmovement
{
private:

    void moveRIGHT();
    void moveLEFT();
    void moveUP();
    void moveDOWN();

    
                                               //     void (*mov[4]) ();                                                    //todo
                                               //     mov = { moveRIGHT, moveLEFT, moveUP, moveDOWN };

    Tlevel *  plvl;

public:
      void Listener();

      Tmovement(Tlevel* p)     //constructor
      {
          plvl = p;
      }

};

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

    switch (_getch())
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





int main()
{
    Tlevel lvl;
    Tmovement Movement(&lvl);
    lvl.display(2, true);                // true - begin (first display)         false - continue (next displays)
    
    while (1)
    {
        while (_kbhit())
        {
            system("cls");
            Movement.Listener();
            lvl.display(2, false);
            Sleep(10);
            cout << endl;
            cout << "x: " << lvl.Player.x <<endl;
            cout << "y: "<< lvl.Player.y;


        }
    }






    return 0;
}

