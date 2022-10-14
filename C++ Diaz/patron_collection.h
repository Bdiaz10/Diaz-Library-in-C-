
#include "patron.h"

#ifndef PATRON_COLLECTION_H
#define PATRON_COLLECTION_H

class PatronCollection{

    private:

        // patron array of 10,000 patron pointers
        // maps patron ID to index
        Patron* patrons[10000];

    public:
        PatronCollection();

        ~PatronCollection();

        // returns pointer to patron given ID
        Patron* getPatron(const int &) const;

        void buildCollection(ifstream &);

        void displayCollection() const;
};

#endif