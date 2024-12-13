#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    enum month {jan = 1, feb, mar, apr, may, june, jul, aug, sep, oct, nov, dec};

    cout << jan;
    cout << feb;
    cout << may;

    cout << endl;

    // _kbhit() only checks if a key is pressed
    // _getch() gets the pressed key

    _kbhit();

    // int temp = _getch();

    cout << (char)_getch();

    // cout << temp << endl << (char)_getch();

    // testing codeium

    string flowers[7] = {"Rose", "Tulip", "Lily", "Daisy", "Sunflower", "Daffodil", "Orchid"};

    for (int i = 0; i < 7; i++) {
        cout << flowers[i] << endl;
    }
}