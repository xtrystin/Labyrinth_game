#include <iostream>
#include <windows.h>
using namespace std;






void menu()
{
   
    cout << "*************************************************" << endl;
    cout << "*                    MENU                       *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*        1. Play                                *" << endl;
    cout << "*        2. Select level                        *" << endl;
    cout << "*        3. Settings                            *" << endl;
    cout << "*        4. Credits                             *" << endl;
    cout << "*        5. Exit                                *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*************************************************" << endl;
    //cout << endl;
    cout << "Select option: ";
    
        
    
        
}
void SelectLvl()
{
    cout << "*************************************************" << endl;
    cout << "*               SELECT LEVEL                    *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*        1. Easy                                *" << endl;
    cout << "*        2. Medium                              *" << endl;
    cout << "*        3. Hard                                *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*************************************************" << endl;
    //cout << endl;
    cout << "Select option: ";
}

void Settings()
{
    cout << "*************************************************" << endl;
    cout << "*              SELECT OPTION                    *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*        1. Color                               *" << endl;
    cout << "*        2. Speed                               *" << endl;
    cout << "*        3. xxxx                                *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*************************************************" << endl;
    //cout << endl;
    cout << "Select option: ";
}

void Credits()
{
    cout << "*************************************************" << endl;
    cout << "*               CREDITS                         *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*             GAME MADE BY                      *" << endl;
    cout << "*               TRYSTIN                         *" << endl;
    cout << "*                                               *" << endl;
    cout << "*          All rights reserved                  *" << endl;
    cout << "*                2020                           *" << endl;
    cout << "*                                               *" << endl;
    cout << "*                                               *" << endl;
    cout << "*************************************************" << endl;
}

void ExitGame()
{
    cout << "Leaving..." << endl;
    Sleep(1000);
    exit(0);
}


int main()
{
    int choice;
    menu();
    cin >> choice;          //todo   if error input 
    system("cls");



    switch (choice)
    {
    case 1: 
        //Play();
        cout << "todo";
        break;
    case 2:
        SelectLvl();
        cin >> choice;
        break;
    case 3:
        Settings();
        cin >> choice;
        break;
    case 4:
        Credits();
        break;
    case 5:
        ExitGame();
        break;
    default:
        cerr << "ERROR main > switch";
        break;
    }




    return 0;
}

