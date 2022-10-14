
#include <iostream>
#include <fstream>
#include <vector>
#include "book.h"

using namespace std;


#ifndef PATRON_H
#define PATRON_H

class Patron{

    private:
        int ID;
        string name;
        vector<string> patronHistory;
        vector<Book*> booksCheckedOut;



    public:

        // constructor
        // takes int and string
        // sets values for patrons id and name
        Patron(const int &, const string &);

        //default constructor
        Patron();

        //destructor
        ~Patron();

        //get id of patron
        int getID() const;  

        // adds to patron history
        void updateHistory(string );

        // adds to books list
        void updateBooksCheckedOut(Book *);

        //returns book
        bool returnBook(Book *);

        //prints the history of patron
        void printHistory() const;

        // get name
        string getName() const;




};

#endif