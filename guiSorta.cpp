#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

unsigned int here = 0;  // negative nums be affecting this lil program dude
int frameCount = 0;
bool quit = false;

/* string* message() {
    string msg[] = {
        "a",
        "b",
        "c",
        "d",
        "e"
    };
    return msg;
} */

void print(string msg[]) {
    for (int i = 0; i < 5; i++) {
        if (here % 5 == i)
            cout << ">>> ";
        cout << msg[i];
    }
}

void choose() {
    switch (here % 5) {
        case 0:
            cout << "You so\n";
            break;
        
        case 1:
            cout << "Fukn'\n";
            break;
        
        case 2:
            cout << "Precious\n";
            break;
        
        case 3:
            cout << "When you\n";
            break;
        
        case 4:
            cout << "Smile\n";
            break;
        
        default:
            cout << "UWU\n";
    }
    
    getch();
}

void point() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'p':
                here--;
                break;
            
            case 'u':
                here++;
                break;
            
            case 'h':
                choose();
                break;

            default:
                quit = true;
        }
    }

    /* //u and h acting too slowly with if-else, why?
    if (_kbhit() && _getch() == 'u')
            here++;
        
    else if (_kbhit() && _getch() == 'p')
            here--;

    else if (_kbhit() && _getch() == 'h')
        quit = true; */

    cout << "\n\n\nPosition: " << here % 5
        << "\nFrames: " << frameCount++
        << "\nHere: " << here << "\n";
}

int main() {
    string msg[] = {
        "a\n",
        "b\n",
        "c\n",
        "d\n",
        "e\n"
    };

    while (true) {
        cout << "Press <s> to START";
        Sleep(500);
        
        system("cls");
        Sleep(500);

        if (_kbhit() && _getch() == 's') {
            Sleep(1000);
            break;
        }
        
    /* every button pressed before s is taken one by one and processed by kbhit() so it looks like it no function
    eg input: "abcsdef". here 3 chars, abc come before s so they processed first making it seems slow
    then, after s, there be 3 chars def. d remains in input stream making point() run default case ie quit

    real sadge bruv */

    /*      buffer = _getch();
            
            if (buffer == 's') {
                cout << buffer;
                Sleep(1000);
                break;
            }
        } */
    }

    string start;

    cout << "Start?\n>>> ";
    cin >> start;

    if (start == "start") {

        /* clear input stream in cpp, how?
        cin.ignore(); */ 

        while (!quit) {
            system("cls");

            print(msg);
            point();

            Sleep(100);
        }
    }

    else
        cout << "Noob, should have said \"start\".";

}