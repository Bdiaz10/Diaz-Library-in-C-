/* periodical book class, derived from book inter face */


#ifndef PERIODICAL_BOOK_H
#define PERIODICAL_BOOK_H
#include "book.h"

class PeriodicalBook: public Book{

private:
    int month;

public:

    // default constructor
    PeriodicalBook();

    // paramerter constructor
    PeriodicalBook(const int &year, const int &month, const string &title);

    // gets month of periodical book
    int getMonth() const;

    // returns pointer to Periodical book
    virtual Book* create() const;


    //inherited from book parent class
    virtual void setData(ifstream &);
    virtual void displayBook() const;

    // comparison operators for periodical book
    // Periodical books sorted by Date(year then month), then Title
    virtual bool operator==(const Book &) const;
    virtual bool operator!=(const Book &) const;
    virtual bool operator<(const Book &) const;
    virtual bool operator>(const Book &) const;
    
    virtual Book& operator=(const Book &);
};

#endif