/* Library Header file */

#include <fstream>
using namespace std;

#ifndef LIBRARY_H
#define LIBRARY_H
#include "book_collection.h"
#include "patron_collection.h"

class Library{

    private:
        BookCollection books;
        PatronCollection patrons;

    public:
        Library();

        ~Library();

        void buildLibrary(ifstream &, ifstream &);

        void processComands(ifstream &);

        void displayLibrary() const;
        

};

#endif