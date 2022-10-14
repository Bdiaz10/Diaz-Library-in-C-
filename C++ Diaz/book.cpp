#include "book.h"

//---------------------------------------------------------------------------
// default constructor
Book::Book(){ }

//---------------------------------------------------------------------------
// virtual destructor
// called on any instance of a book
Book::~Book() { }

//---------------------------------------------------------------------------
// get title of calling book: inhertied by all children
string Book::getTitle() const{
    return this->title;
}

//---------------------------------------------------------------------------
// get year of calling book: inherited by all children
int Book::getYear() const{
    return this->year;
}

//---------------------------------------------------------------------------
// gets the number of books available 
int Book::getBooksAvailable() const{
    return this->booksAvailable;
}

//---------------------------------------------------------------------------
// decrements books available by 1
void Book::decrementBooksAvailable(){
    booksAvailable--;
}
//---------------------------------------------------------------------------
void Book::incrementBooksAvailable(){
    booksAvailable++;
}

