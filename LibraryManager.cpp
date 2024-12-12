// todo: add user levels ie admins for book control (entry, changeDetails, ...), consumers for basic stuff (borrow, return, preview, ...)
// todo: search method -> changeDeets, borrow, return, checkCopies, preview: search by name, author, id, genre
// todo: store and get from files
// todo: format line changes

/*
    normal
    * important
    ! alert
    ? queries
    todo tasks
*/

#include <iostream>
#include <conio.h> // _kbhit() and _getch()
#include <string.h>
#include <vector>
#include <fstream>
#include <windows.h>
using namespace std;


// globals
bool closeGUI = false;
int position = 0;       // for cursor in gui
int count = 0;              // for book id's

class Book {
    int id = count;
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
            cout << "ID: " << id 
                << "\nBook Name: " << name
                << "\nAuthor: " << author
                << "\nPublish Date: " << publishDate
                << "\nGenre: " << genre
                << "\nAvailable Copies: " << availableCopies
                << endl;
        }

        void changeDetails() {
            entry();
            cout << "Details updated.\n";
        }

        void copiesAvailable() {
            if (availableCopies != 0)
                cout << availableCopies << " copies available.\n";

            else
                cout << "No copies available.\n";
        }

        void borrow() {
            if (availableCopies == 0) {
                cout << "No copies left\n";
            }
            else {
                availableCopies--;
                cout << name << " borrowed\n";
            }
        }

        void rEturn() {
            availableCopies++;
            cout << name << " returned\n";
        }

        // ~Book() {                                       // todo: call only when removeBook() or end of program: done i think: no, not done apparently
        //     cout << name << " deleted from records\n";  // ! occurs multiple times, cause -> copying from b to temp to b, deleting b for transfer in func createBook
        // }                                               // * fix: no user defined destructor, delete from memory, delete location / pointer

        friend void listBooks();
        friend int whichBook();
        friend void removeBook(int id);
};


vector<Book> b;

// real functions
void createBook() {    
    Book temp;
    temp.entry();
    
    b.push_back(temp);

    count++;
}

void removeBook(int id) {
    string name = b[id].name;

    b.erase(b.begin() + id);
    count--;

    cout << name << " removed from records.\n";
}

void listBooks() {
    if (b.empty())
        cout << "No books exist in the records.\n";
    
    else {
        cout << "All Recorded Books:\n";

        for (int i = 0; i < b.size(); i++) {
            cout << i+1 << ") " << b[i].name << "\n";
        }
    }
}


// it is what it is
void sayIt() {
    cout << "Hocus Pocus Focus Amogus\n";
}


// function extensions
int whichBook() {
    string thisBook;

    cout << "Operate on which book? ";
    cin >> thisBook;

    for (int i = 0; i < b.size(); i++) {
        if (thisBook == b[i].name)
            return b[i].id;
    }

    cout << "Such a book does not exist in the records.\n";
    return -1;
}

void operations(int choice) {
    int id;

    switch (choice) {
        case 0:
            listBooks();
            break;
        
        case 1:
            id = whichBook();
            if (id == -1)
                break;
            
            b[id].preview();
            break;

        case 2:
            createBook();
            break;

        case 3:
            id = whichBook();
            if (id == -1)
                break;
            
            b[id].changeDetails();
            break;
        
        case 4:
            id = whichBook();
            if (id == -1)
                break;
            
            b[id].copiesAvailable();
            break;
        
        case 5:
            id = whichBook();
            if (id == -1)
                break;
            
            b[id].borrow();
            break;
        
        case 6:
            id = whichBook();
            if (id == -1)
                break;
            
            b[id].rEturn();
            break;
        
        case 7:
            id = whichBook();
            if (id == -1)
                break;
            
            removeBook(id);
            break;
        
        case 8:
            sayIt();
            break;

        default:
            cout << "Something be very wrong.\n";
    }
    
}


// cli
void librarySystemCLI() {
    cout << "Do what?\n"
        << "\tList all books [1]\n"
        << "\tPreview a book [2]\n"
        << "\tEnter a book [3]\n"
        << "\tChange a book's details [4]\n"
        << "\tCheck if copies are available [5]\n"
        << "\tBorrow a book [6]\n"
        << "\tReturn a book [7]\n"
        << "\tRemove a book [8]\n"
        << "\tSay the magic words [9]\n>>> ";
    
    int action;
    cin >> action;
    
    operations(action - 1);    // (-1) cause cases start from 0
}


// gui
void printGUI(string prompts[]) {
    for (int i = 0; i < 9; i++) {
        if (position % 9 == i)
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
                operations(position % 9);
                getch();
                break;

            default:
                closeGUI = true;
        }
    }
}

void librarySystemGUI() {
    string prompts[] = {
        "List all books\n",
        "Preview a book\n",
        "Enter a book\n",
        "Change a book's details\n",
        "Check if copies are available\n",
        "Borrow a book\n",
        "Return a book\n",
        "Remove a book\n",
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


// main.
int main() {

    while (true) {
        char choice;

        cout << "CLI / GUI / Exit?\n(C / G / Any other key)\n>>> ";
        cin >> choice;

        if (choice == 'C' || choice == 'c')
            librarySystemCLI();

        else if (choice == 'G' || choice == 'g')
            librarySystemGUI();

        else
            break;

        cout << endl;
    }

    cout << "----------------\n Library Closed";
}
