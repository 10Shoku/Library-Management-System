// todo: map arrow keys to ctrl + something with pinky perhaps and remove vim prolly -> No option for this
// todo: sort objects in array using member value -> can do now

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
int k = 0;

class Book {
    int id = k;
    string name;
    string author;
    string publishDate; // split to dd/mm/yyyy
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

        friend void listBooks(Book b[]);
        friend int whichBook();
};

Book *b;

void createBook() {
    b = new Book;
    b[k++].entry();
}

void removeBook(int id) {
    b[id].~Book();
}

void listBooks(Book b[]) {
    cout << "All Recorded Books:\n";

    for (int i = 0; i < k; i++) {
        cout << i+1 << ") " << b[i].name << "\n";
    }
}

void sayIt() {
    cout << "Hocus Pocus Focus Amogus\n>>> ";
}


int whichBook() {
    string thisBook;

    cout << "Operate on which book? ";
    cin >> thisBook;

    for (int i = 0; i < k; i++) {
        if (thisBook == b[i].name)
            return b[i].id;
    }
}

void operations(int choice) {
    int id;

    switch (choice) {
        case 0:
            createBook();
            break;

        case 1:
            id = whichBook();
            b[id].changeDetails();
            break;
        
        case 2:
            whichBook();
            removeBook(id);
            break;

        case 3:
            whichBook();
            b[id].copiesAvailable();
            break;
        
        case 4:
            whichBook();
            b[id].borrow();
            break;
        
        case 5:
            whichBook();
            b[id].rEturn();
            break;
        
        case 6:
            listBooks(b);
            break;
        
        case 7:
            sayIt();
            break;

        default:
            cout << "Something be very wrong.\n";
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
        << "\tList all books [7]\n" // todo: integrate to other interfaces, reorder all operations
        << "\tSay the magic words [8]\n>>> ";

    int action;    
    cin >> action;
    
    operations(action - 1);    // (-1) cause cases start from 0
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
                operations(position % 7);
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

    cout << "\nLibrary Closed";
}