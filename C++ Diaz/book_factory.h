// class BookFactory: creates and returns a new object.

#include "childrens_book.h"
#include "periodical_book.h"
#include "fiction_book.h"

#ifndef BOOK_FACTORY_H
#define BOOK_FACTORY_H

class BookFactory{

    private:
        Book* bookFactory[26];  // array of 3 different book genre objects
        int hash(char ch) const; // hash function maps key to correct object
    
    public:

        // constructor builds book objects
        BookFactory();

        // destructor deletes objects in factory
        ~BookFactory();

        // creates a new object and returns as book pointer
        Book* createIt(char ch) const;


};



#endif