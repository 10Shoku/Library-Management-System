#include <iostream>
#include <fstream>
using namespace std;

class Book {
    protected:
        int bookId;
        string title;
        string author;
        int copiesAvailable;

        fstream lib;

    public:
        Book() {
            cout << "Book Id: ";
            cin >> bookId;
            cout << "Title: ";
            cin >> title;
            cout << "Author: ";
            cin >> author;
            cout << "Copies Available: ";
            cin >> copiesAvailable;
        }

        ~Book() {
            cout << title << " removed from database.\n";
        }

        virtual void displayDetails() {
            cout << "Book Id: " << bookId <<
            "\n" << "Title: " << title <<
            "\n" << "Author: " << author <<
            "\n" << "Copies Available: " << copiesAvailable << endl;
        }

        void operator+=(int inc) {
            copiesAvailable += inc;
        }

        void operator-=(int dec) {
            copiesAvailable -= dec;
        }

        void save() {
            lib.open("library.txt", ios::app);
            lib << bookId << "\t" << title << "\t" << author << "\t" << copiesAvailable << "\n";
            lib.close();
        }

        void load() {
            lib.open("library.txt", ios::in);
            string str;

            while (getline(cin, str)) {
                
            }
        }
};

class IssuedBook : public Book {
    string issuedTo;
    int returnDate;

    public:
        IssuedBook() {
            cout << "Issue this book to: ";
            cin >> issuedTo;
            cout << "This book must be returned by: ";
            cin >> returnDate;
        }

        void displayDetails() {
            Book::displayDetails();

            cout << "Issued To: " << issuedTo <<
            "\n" << "Return Date: " << returnDate << endl;
        }
};

int main() {
    IssuedBook b1;

    b1.save();
}