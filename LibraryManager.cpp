// todo: map arrow keys to ctrl + something with pinky perhaps and remove vim prolly -> No option for this
// todo: sort objects in array using member value -> can do now

// todo: add user levels ie admins for book control (entry, changeDetails, ...), consumers for basic stuff (borrow, return, preview, ...)
// todo: implement vectors instead of controlling with pointers -> much cleaner, more readable, just better
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
#include <vector>
#include <fstream>
#include <windows.h>
using namespace std;

// globals
bool closeGUI = false;
int position = 0;       // for cursor in gui
int firstBookIndex = 0; // starting index for loops
int k = 0;              // for book id's

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

        friend void listBooks(Book b[]);
        friend int whichBook();
        friend void removeBook(int id);
};


Book *b;    // global class for unending scope, pointer for object array
int capacity = 0;   // capacity of array of books

// real functions
void createBook() {
    if (k == capacity) {
        capacity = (capacity == 0) ? 1 : k * 2;

        Book *temp = new Book[capacity];

        for (int i = firstBookIndex; i < k; i++) {
            temp[i] = b[i];
        }

        delete[] b;

        b = temp;
    }

    b[k++].entry();
}

void removeBook(int id) {
    Book temp;
    string name = b[id].name;

    temp = b[id];
    b[id] = b[k-1];     // swap index of last element with that of element to be removed
    b[k-1] = temp;

    b[k--].~Book();

    cout << name << " removed from records.\n";
}

void listBooks(Book b[]) {
    if (k == 0)
        cout << "No books exist in the records.\n";
    
    else {
        cout << "All Recorded Books:\n";

        for (int i = firstBookIndex; i < k; i++) {
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

    for (int i = firstBookIndex; i < k; i++) {
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
            listBooks(b);
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
        << "\tList all books [1]\n" // todo: integrate to other interfaces: done, reorder all operations: done, add preview method
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

    delete[] b;

    cout << "\nLibrary Closed";
}
