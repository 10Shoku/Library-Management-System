// * shift alt a ---> block comment
// todo: push to github
// todo: map arrow keys to ctrl + something with pinky perhaps and remove vim prolly
// todo: sort objects in array using member value

/*
    normal
    * important
    ! alert
    ? queries
    todo tasks
 */

#include <iostream>
#include <conio.h> // _kbhit() and _getch()
#include <vector>
#include <fstream>
#include <windows.h>
using namespace std;

int position = 0;
bool closeGUI = false;

class Book {
    string name;
    string author;
    string publishDate;
    string genre;
    int availableCopies;

    public:
        void entry() {
            cout << "Book Name: ";
            cin >> name;
            cout << "Author: ";
            cin >> author;
            cout << "Publish Date: ";
            cin >> publishDate;
            cout << "Genre: ";
            cin >> genre;
            cout << "Available Copies: ";
            cin >> availableCopies;
        }

        void preview() {
            cout << "Book Name: " << name
                 << "\nAuthor: " << author
                 << "\nPublish Date: " << publishDate
                 << "\nGenre: " << genre
                 << "\nAvailable Copies: " << availableCopies;
        }

        void changeDetails() {
            entry();
            cout << "deets changed\n";
        }

        void copiesAvailable() {
            if (availableCopies != 0)
                cout << availableCopies << " copies available.\n";

            else
                cout << "No copies available.\n";
        }

        void borrow() {
            availableCopies--;
            cout << name << " borrowed\n";
        }

        void rEturn() {
            availableCopies++;
            cout << name << " returned\n";
        }

        ~Book() {   // todo: call only when removeBook() or end of program
            cout << name << " deleted from records\n";
        }
};

void createBook() {
    static Book b;
    b.entry();
}

void removeBook(Book &b) {
    b.~Book();
}

void sayIt() {
    cout << "Hocus Pocus Amogus\n>>> ";
}


void options(int choice) {
    switch (choice) {
        case 0:
            createBook();
            break;

        case 1:
            changeDetails();
            break;
        
        case 2:
            removeBook();
            break;

        case 3:
            copiesAvailable();
            break;
        
        case 4:
            borrow();
            break;
        
        case 5:
            rEturn();
            break;
        
        case 6:
            sayIt();
            break;

        default:
            cout << "Something very wrong.\n";
    }
    
}

void librarySystemCLI() {
    cout << "Do what?\n"
        << "\tEnter a book [1]\n"
        << "\tChange a book's details [2]\n"
        << "\tRemove a book [3]\n"
        << "\tCheck if copies are available [4]\n"
        << "\tBorrow a book [5]\n"
        << "\tReturn a book [6]\n"
        << "\tSay the magic words [7]\n>>> ";
    
    int action;    
    cin >> action;
    
    options(action - 1);    // * cause cases start from 0
}


void printGUI(string prompts[]) {
    for (int i = 0; i < 7; i++) {
        if (position % 7 == i)
            cout << ">>> ";
            
        cout << prompts[i];
    }
}

void pointGUI() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'p':
                position--;
                break;
            
            case 'u':
                position++;
                break;
            
            case 'h':
                cout << "\n\n---> ";
                options(position % 7);
                getch();
                break;

            default:
                closeGUI = true;
        }
    }
}

void librarySystemGUI() {
    string prompts[] = {
        "Enter a book\n",
        "Change a book's details\n",
        "Remove a book\n",
        "Check if copies are available\n",
        "Borrow a book\n",
        "Return a book\n",
        "Say the magic words\n"
    };
    closeGUI = false;
    
    while (!closeGUI) {
        system("cls");

        cout << "\'p\' for up, \'u\' for down\n"
            << "\'h\' to select, any other key to exit\n\n";

        printGUI(prompts);
        pointGUI();

        Sleep(100);
    }
}


int main() {
    char repeat = 'Y';

    while (repeat == 'Y'){
        char choice;

        cout << "CLI or GUI? (C/G)\n>>> ";
        cin >> choice;

        if (choice == 'C')
            librarySystemCLI();

        else if (choice == 'G')
            librarySystemGUI();
        
        else
            cout << "Well, what do you want then, bruh?\n";

        cout << "\nContinue? (Y/N)\n>>> ";
        cin >> repeat;

        cout << endl;
    }

    cout << "\nLibrary Time Biatch";
}