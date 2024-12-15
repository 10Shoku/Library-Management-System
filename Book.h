#include <iostream>
#include <string.h>
using namespace std;

int count = 0;

class Book {
    protected:
        int id = count;
        string name;
        string author;
        string publishDate;     // todo: split to dd/mm/yyyy
        string genre;
        int availableCopies;

    public:
        Book(int i = 0, string n = "", string a = "", string p = "", string g = "", int aC = 0) : id(i), name(n), author(a), publishDate(p), genre(g), availableCopies(aC) {
            cout << "Book initialized\n";
        };

        Book(const Book& other) : id(other.id), name(other.name), author(other.author), publishDate(other.publishDate), genre(other.genre), availableCopies(other.availableCopies) {}   // * test

        Book operator=(const Book& other) {     // * test
            id = other.id;
            name = other.name;
            author = other.author;
            publishDate = other.publishDate;
            genre = other.genre;
            availableCopies = other.availableCopies;

            return *this;
        }

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

        void preview() const {
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

        friend void listBooks();
        friend int whichBook();
        friend void removeBook(int id);
};