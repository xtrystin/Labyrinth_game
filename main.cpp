#include <iostream>
#include <windows.h>

#include "Game.h"
#include "Menu.h"

using namespace std;



void ExitGame()
{
    GameLogo();
    cout << "Leaving..." << endl;
    Sleep(1000);
    exit(0);
}



int main(int argc, char** argv)
{

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
    GameLogo();
    Sleep(2000);
    system("cls");


    while (1)
    {
        system("cls");
        menu();
        cin >> choice;          //todo   if error input 
        system("cls");


        switch (choice)
        {
        case 1:
            Play(1);

            break;
        case 2:
            SelectLvl();
            cin >> choice;
            switch (choice)
            {
            case 1:
                Play(1);
                break;
            case 2:
                Play(2);
                break;
            case 3:
                //Play(3);
                cout << "Not available";
                Sleep(1000);
                break;
            case 4:
                break;
            default:
                break;
            }
            break;
        case 3:
            Settings();
            cin >> choice;
            switch (choice)
            {
            case 1:
                system("Color 0A");
                //todo
                break;
            case 2:
                cout << "Not available";
                Sleep(1000);
                //todo
                break;
            case 3:
                Beep(523, 5000);
                Beep(1175, 1000);
                //todo
                break;
            default:
                break;
            }
            break;
        case 4:
            Credits();
            getchar(); getchar();
            break;
        case 5:
            ExitGame();
            break;
        default:
            cerr << "ERROR main > switch";
            break;
        }
    }





    return 0;
}
