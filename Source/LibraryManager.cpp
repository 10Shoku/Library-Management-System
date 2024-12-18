// todo: add user levels ie admins for book control (entry, changeDetails, ...), consumers for basic stuff (borrow, return, preview, ...)
// todo: search method -> changeDeets, borrow, return, checkCopies, preview: search by name, author, id, genre
// todo: in func pointGUI, use arrow keys and enter as inputs
// todo: store and get from files
// todo: format line changes

// ! FIX:
// ! Enter book obj's a, b, c, d, e
// ! Delete c
// ! Member values of d, e move down 1 index but they themselves don't
// ! This causes: d -> values of e, e -> empty values

// ! a b c d e
// ! a b d e
// !
// ! objects are shifting, but values are not

/*
    normal
    * important
    ! alert
    ? queries
    todo tasks
*/

#include <iostream>
#include <conio.h>      // _kbhit() and _getch()
#include <string.h>
#include <vector>
#include <fstream>
#include <windows.h>
#include "../Headers/Book.h"           // todo: try to add a different small header file to the program
using namespace std;


// globals
// int count = 0;          // for book id's
// short cursor = 0;       // for cursor in gui
// short nPrompts = 9;     // number of prompts
// bool closeGUI = false;

// class Book {
//     protected:
//         int id = count;
//         string name;
//         string author;
//         string publishDate;     // todo: split to dd/mm/yyyy
//         string genre;
//         int availableCopies;

//     public:
//         Book(int i = 0, string n = "", string a = "", string p = "", string g = "", int aC = 0) : id(i), name(n), author(a), publishDate(p), genre(g), availableCopies(aC) {
//             cout << "Book initialized\n";
//         };

//         Book(const Book& other) : id(other.id), name(other.name), author(other.author), publishDate(other.publishDate), genre(other.genre), availableCopies(other.availableCopies) {}   // * test

//         Book operator=(const Book& other) {     // * test
//             id = other.id;
//             name = other.name;
//             author = other.author;
//             publishDate = other.publishDate;
//             genre = other.genre;
//             availableCopies = other.availableCopies;

//             return *this;
//         }

//         void entry() {
//             cout << "Book Name: ";
//             cin >> name;
//             cout << "Author: ";
//             cin >> author;
//             cout << "Publish Date: ";
//             cin >> publishDate;
//             cout << "Genre: ";
//             cin >> genre;
//             cout << "Available Copies: ";
//             cin >> availableCopies;
//         }

//         void preview() const {
//             cout << "ID: " << id
//                 << "\nBook Name: " << name
//                 << "\nAuthor: " << author
//                 << "\nPublish Date: " << publishDate
//                 << "\nGenre: " << genre
//                 << "\nAvailable Copies: " << availableCopies
//                 << endl;
//         }

//         void changeDetails() {
//             entry();
//             cout << "Details updated.\n";
//         }

//         void copiesAvailable() {
//             if (availableCopies != 0)
//                 cout << availableCopies << " copies available.\n";

//             else
//                 cout << "No copies available.\n";
//         }

//         void borrow() {
//             if (availableCopies == 0) {
//                 cout << "No copies left\n";
//             }
//             else {
//                 availableCopies--;
//                 cout << name << " borrowed\n";
//             }
//         }

//         void rEturn() {
//             availableCopies++;
//             cout << name << " returned\n";
//         }

//         friend void listBooks();
//         friend int whichBook();
//         friend void removeBook(int id);
// };


class Staff : public Book {
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

        void changeDetails() {
            entry();
            cout << "Details updated.\n";
        }

        friend void removeBook(int id);

};

class User : public Book {
    public:
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
};

// vector<Book> b;


// // real functions
// void createBook() {
//     Book temp;
//     temp.entry();
    
//     b.push_back(temp);

//     count++;
// }

// void removeBook(int iD) {       // ! FIX FIX FIX
//     string name = b[iD].name;
//     int i = b[iD].id;

//     b.erase(b.begin() + iD);    // ! ded

//     count--;

//     cout << name << " removed from records.\n";
// }

// void listBooks() {
//     if (b.empty())
//         cout << "No books exist in the records.\n";

//     else {
//         cout << "All Recorded Books:\n";

//         for (int i = 0; i < b.size(); i++) {
//             cout << i+1 << ") " << b[i].name << "\n";
//         }
//     }
// }


// // it is what it is
// void sayIt() {
//     cout << "Hocus Pocus Focus Amogus\n";
// }


// // function extensions
// int whichBook() {
//     string thisBook;

//     cout << "Operate on which book? ";
//     cin >> thisBook;

//     for (Book temp : b) {
//         if (temp.name == thisBook) {
//             cout << "ID: " << temp.id << endl;  // test
//             return temp.id;
//         }
//     }

//     cout << "Such a book does not exist in the records.\n";
//     return -1;
// }

// void operations(short choice) {
//     int id;

//     switch (choice) {
//         case 0:
//             listBooks();
//             break;

//         case 1:
//             id = whichBook();
//             if (id == -1)
//                 break;

//             b[id].preview();
//             break;

//         case 2:
//             createBook();
//             break;

//         case 3:
//             id = whichBook();
//             if (id == -1)
//                 break;

//             b[id].changeDetails();
//             break;

//         case 4:
//             id = whichBook();
//             if (id == -1)
//                 break;

//             b[id].copiesAvailable();
//             break;

//         case 5:
//             id = whichBook();
//             if (id == -1)
//                 break;

//             b[id].borrow();
//             break;

//         case 6:
//             id = whichBook();
//             if (id == -1)
//                 break;

//             b[id].rEturn();
//             break;

//         case 7:
//             id = whichBook();
//             if (id == -1)
//                 break;

//             removeBook(id);
//             break;

//         case 8:
//             sayIt();
//             break;

//         default:
//             cout << "Invalid Choice\n";
//     }
// }


// // cli
// void librarySystemCLI() {
//     cout << "Do what?\n"
//         << "\tList all books [1]\n"
//         << "\tPreview a book [2]\n"
//         << "\tEnter a book [3]\n"
//         << "\tChange a book's details [4]\n"
//         << "\tCheck if copies are available [5]\n"
//         << "\tBorrow a book [6]\n"
//         << "\tReturn a book [7]\n"
//         << "\tRemove a book [8]\n"
//         << "\tSay the magic words [9]\n>>> ";

//         short action;
//         if (cin >> action)
//             operations((action) - 1);
        
//         else {
//             cout << "Only Numbers!\n";      // handling char input error
//             cin.clear();
//             cin.ignore(100, '\n');
//         }
// }


// // gui
// void printGUI(string prompts[]) {
//     for (int i = 0; i < nPrompts; i++) {
//         if (cursor == i)
//             cout << ">>> ";

//         cout << prompts[i];
//     }
// }

// void pointGUI() {
//     if (_kbhit()) {
//         switch (_getch()) {
//             case 'p':
//                 if (cursor != 0)
//                     cursor--;

//                 break;

//             case 'u':
//                 if (cursor != nPrompts - 1)
//                     cursor++;

//                 break;

//             case 'h':
//                 cout << "\n\n---> ";
//                 operations(cursor % nPrompts);
//                 getch();
//                 break;

//             default:
//                 closeGUI = true;
//         }
//     }
// }

// void librarySystemGUI() {       // works with codeRunner but not with default compiler
//     string prompts[] = {
//         "List all books\n",
//         "Preview a book\n",
//         "Enter a book\n",
//         "Change a book's details\n",
//         "Check if copies are available\n",
//         "Borrow a book\n",
//         "Return a book\n",
//         "Remove a book\n",
//         "Say the magic words\n"
//     };

//     closeGUI = false;

//     while (!closeGUI) {
//         system("cls");

//         cout << "\'p\' for up, \'u\' for down\n"
//             << "\'h\' to select, any other key to exit\n\n";

//         printGUI(prompts);
//         pointGUI();

//         Sleep(150);
//     }
// }


// main.
int main() {
    Book t1(0, "a", "a", "a", "a", 1);
    Book t2(1, "b", "b", "b", "b", 2);
    Book t3(2, "c", "c", "c", "c", 3);
    Book t4(3, "d", "d", "d", "d", 4);
    Book t5(4, "e", "e", "e", "e", 5);

    b.push_back(t1);
    b.push_back(t2);
    b.push_back(t3);
    b.push_back(t4);
    b.push_back(t5);

    cout << endl;
    

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

    cout << "\n----------------\n Library Closed";
}