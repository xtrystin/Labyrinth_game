#include <iostream>
#include <Windows.h>

using namespace std;


class Tplayer;
class Tfruit;
class Tlevel;

                        //todo namespace: Tplayer, Tfruit
class Tplayer               
{
public:         // todo private
    int x;           
    int y;
    


};



class Tfruit
{
public:             //todo private
    int x;
    int y;



   // Tfruit(int id);   // constructor

};




///////////////////// CLASS Tlevel - displaying level map ///////////////////////////////////////////////////////////////////////
class Tlevel
{
private:
    static const int Kwidth;
    static const int Kheight;
               

    Tfruit Fruit;
    Tplayer Player;


    void lvlFirst(int, int);
    void lvlSec(int, int);
    void StartPosition(Tplayer&, Tfruit&, int);


public:
             
    void display(int);
                                                                                   
                                                                                                                                                                                                                              
                                                                                            
    //Tlevel() {};
};

//  STATIC   WINDOW SIZE: 50 x 20  //
const int Tlevel::Kheight = 20;
const int Tlevel::Kwidth = 50;
//  end STATIC  //


///////////////FUNC class Tlevel /////////////////////////



//////////////MAPS//////////////
// MAP lvl 1
void Tlevel::lvlFirst(int x, int y)
{
    if (x == Player.x && y == Player.y)
    {
        cout << 'p';
    }
    else if (x == 2 || ( y == 19 && x != 1 ) || x == Kwidth-2 || ( y == 3 && x != 1 && x != 3 && x != 4 ) || ( x == 5 && y > 3 && y < 14 ) )
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
void Tlevel::display(int index)
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
                        StartPosition(Player, Fruit, 1);     // Fruit and Player start position
                        lvlFirst(x, y);
                        break;
                    case 2:
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
void Tlevel::StartPosition(Tplayer& p, Tfruit& f, int id)
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
        p.x = 1;
        p.y = 19;

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






int main()
{
    Tlevel lvl;

    while (1)
    {
        lvl.display(2);
        Sleep(1000);
        system("cls");
       
    }


    //do keyboard input




    return 0;
}

