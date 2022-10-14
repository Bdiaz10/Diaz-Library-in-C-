/* fiction book class, derived from book inter face */


#ifndef FICTION_BOOK_H
#define FICTION_BOOK_H
#include "book.h"

class FictionBook: public Book{

private:
    string author;

public:
    // constructor
    FictionBook();

    //parameter constructor
    FictionBook(const string &, const string &);

    // gets author of fiction book
    string getAuthor() const;

    // returns pointer to Fiction book
    virtual Book* create() const;

    //inherited from book parent class
    virtual void setData(ifstream &);
    virtual void displayBook() const;

    // comparison operators for fiction book
    // Fiction books sorted by Author, then Title
    virtual bool operator==(const Book &) const;
    virtual bool operator!=(const Book &) const;
    virtual bool operator<(const Book &) const;
    virtual bool operator>(const Book &) const;

    //assignment operator
    virtual Book& operator=(const Book &);
    
    


};

#endif
