#pragma once
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
private:
    unsigned int x;
    unsigned int y;
    friend class Tlevel;



    // Tfruit(int id);   // constructor

};




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

    Tplayer Player;     //public because main()  cout << Player.x

    void display(int, bool);    //display the map



    //Tlevel() {};
};





class Tmovement
{
private:

    void moveRIGHT();
    void moveLEFT();
    void moveUP();
    void moveDOWN();
    void leave();
    void pause();
    void retMenu();



    //     void (*mov[4]) ();                                                    //todo
    //     mov = { moveRIGHT, moveLEFT, moveUP, moveDOWN };

    Tlevel* plvl;

public:
    void Listener();

    Tmovement(Tlevel* p)     //constructor
    {
        plvl = p;
    }

};




void Play(int choice);
