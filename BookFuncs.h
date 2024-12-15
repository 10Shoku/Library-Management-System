#include <iostream>
#include <string.h>
using namespace std;

// real functions
void createBook() {
    Book temp;
    temp.entry();
    
    b.push_back(temp);

    count++;
}

void removeBook(int iD) {
    string name = b[iD].name;
    int i = b[iD].id;

    b.erase(b.begin() + iD);    // ! ded

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

// function extensions
int whichBook() {
    string thisBook;

    cout << "Operate on which book? ";
    cin >> thisBook;

    for (Book temp : b) {
        if (temp.name == thisBook) {
            cout << "ID: " << temp.id << endl;  // test
            return temp.id;
        }
    }

    

    // for (int i = 0; i < b.size(); i++) {    // todo: use ranged for loop, iterative is iterating id's that have been deleted
    //     if (thisBook == b[i].name)
    //         return b[i].id;
    // }

    cout << "Such a book does not exist in the records.\n";
    return -1;
}

void operations(short choice) {
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
            cout << "Invalid Choice\n";
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

        short action;
        if (cin >> action)
            operations((action) - 1);
        
        else {
            cout << "Only Numbers!\n";      // handling char input error
            cin.clear();
            cin.ignore(100, '\n');
        }
}

// gui
void printGUI(string prompts[]) {
    for (int i = 0; i < nPrompts; i++) {
        if (cursor == i)
            cout << ">>> ";

        cout << prompts[i];
    }
}

void pointGUI() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'p':
                if (cursor != 0)
                    cursor--;

                break;

            case 'u':
                if (cursor != nPrompts - 1)
                    cursor++;

                break;

            case 'h':
                cout << "\n\n---> ";
                operations(cursor % nPrompts);
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

        Sleep(150);
    }
}