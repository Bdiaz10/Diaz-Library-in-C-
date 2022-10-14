/* childrens book class, derived from book inter face */



#ifndef CHILDRENS_BOOK_H
#define CHILDRENS_BOOK_H
#include "book.h"

class ChildrensBook: public Book{

private:
    string author;
    

public:
    // constructor
    ChildrensBook();

    //paramete constructor
    ChildrensBook(const string &, const string &);

    // returns author of childrens book
    string getAuthor() const;

    // returns pointer to childrens book
    virtual Book* create() const;

    //inherited from book parent class
    virtual void setData(ifstream &);
    virtual void displayBook() const;

    // comparison operators for children book
    // Childrens books sorted by Title, then Author
    
    virtual bool operator==(const Book &) const;
    virtual bool operator!=(const Book &) const;
    virtual bool operator<(const Book &) const;
    virtual bool operator>(const Book &) const;
    
    //assignment operator
    virtual Book& operator=(const Book &);
    


};

#endif