// Book collection Header  file

#include "book_factory.h"
#include "bintree.h"

#ifndef BOOK_COLLECTION_H
#define BOOK_COLLECTION_H

class BookCollection{

    private:
        BookFactory bookFactory;
        // stores the 3 genres held in the library
        // fiction, children, periodical
        BinTree* bookGenres[26]; 

        int hash(char ch) const;

    public:

        //constructor
        BookCollection();

        // destructor
        ~BookCollection();

        // gets book
        Book* checkOutBook(ifstream &) const;

        // gets book to return
        Book* bookToReturn(ifstream &) const;
        
        // builds collection
        void buildCollection(ifstream &); 

        // displays childrens books
        void displayChildrensBooks() const;

        // displays fiction books
        void displayFictionBooks() const;

        // displays periodical books
        void displayPeriodicalBooks() const;

        //displays all books in collection
        void displayCollection() const;
};


#endif