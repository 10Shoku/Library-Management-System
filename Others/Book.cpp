#include <iostream>
#include <string.h>
#include "../Headers/Book.h"
using namespace std;

int count = 0;          // for book id's
Book::id = count;

Book::Book(int i = 0, string n = "", string a = "", string p = "", string g = "", int aC = 0) : id(i), name(n), author(a), publishDate(p), genre(g), availableCopies(aC) {
    cout << "Book initialized\n";
};

Book::Book(const Book& other)
    : id(other.id), name(other.name), author(other.author), publishDate(other.publishDate), genre(other.genre), availableCopies(other.availableCopies) {}   // * test

Book& Book::operator=(const Book& other) {     // * test
    id = other.id;
    name = other.name;
    author = other.author;
    publishDate = other.publishDate;
    genre = other.genre;
    availableCopies = other.availableCopies;

    return *this;
}

void Book::entry() {
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

void Book::preview() const {
    cout << "ID: " << id
        << "\nBook Name: " << name
        << "\nAuthor: " << author
        << "\nPublish Date: " << publishDate
        << "\nGenre: " << genre
        << "\nAvailable Copies: " << availableCopies
        << endl;
}

void Book::changeDetails() {
    entry();
    cout << "Details updated.\n";
}

void Book::copiesAvailable() {
    if (availableCopies != 0)
        cout << availableCopies << " copies available.\n";

    else
        cout << "No copies available.\n";
}

void Book::borrow() {
    if (availableCopies == 0) {
        cout << "No copies left\n";
    }
    else {
        availableCopies--;
        cout << name << " borrowed\n";
    }
}

void Book::rEturn() {
    availableCopies++;
    cout << name << " returned\n";
}

int noOfBooks() {
    return count;
}