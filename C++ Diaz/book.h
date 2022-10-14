/* Book Interface, abstract base class */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

#ifndef BOOK_H
#define BOOK_H

class Book{

protected:
    string title;
    int year;
    int booksAvailable;
    int maxBooks;


public:
    // constructor
    Book();

    // setters should take in stream file
    virtual void setData(ifstream &) = 0;

    //Create functions returns pointer to object
    virtual Book* create() const = 0;
    
    // getters
    string getTitle() const;
    int getYear() const;
    int getBooksAvailable() const;

    //decrements books available
    virtual void decrementBooksAvailable();

    //increments books available
    virtual void incrementBooksAvailable();

    // pure virtual comparison operators
    // each child class must implement
    virtual bool operator==(const Book &) const = 0;
    virtual bool operator!=(const Book &) const = 0;
    virtual bool operator<(const Book &) const = 0;
    virtual bool operator>(const Book &) const = 0;

    virtual Book& operator=(const Book &) = 0;
    

    //display the book
    virtual void displayBook() const = 0;

    // virtual destructor
    virtual ~Book();

};



#endif