#include "periodical_book.h"

//----------------------------------------------------------------------------
// Periodical Book default constructor
// only 1 copy of periodical books is stored
PeriodicalBook::PeriodicalBook(){
    booksAvailable = 1;
    maxBooks = 1;

}
//----------------------------------------------------------------------------
// parameter construct
PeriodicalBook::PeriodicalBook(const int &year, const int &month, const string & title){
    this->year = year;
    this->month = month;
    this->title = title;
}

//----------------------------------------------------------------------------
// gets month of the periodical date
int PeriodicalBook::getMonth() const{
    return this->month;
}

//----------------------------------------------------------------------------
// create
// creates and returns a pointer to a new Periodical Book object
Book* PeriodicalBook::create() const{
    return new PeriodicalBook;
}

//----------------------------------------------------------------------------
// Display Periodical
// Periodicals hold month and year, outputed: <month> <year>
void PeriodicalBook::displayBook() const{
    cout << left << setw(7) << booksAvailable << setw(40) << title << setw(2) << month << " " << year << endl;
}

//----------------------------------------------------------------------------
// set data for periodical book
// periodical book holds: title , month , year
void PeriodicalBook::setData(ifstream &infile){

    infile.get(); // get (and ignore) blank before title

    getline(infile, title, ','); // reade line (comma terminated) as title

    infile >> month; // read month from file

    infile >> year; // read year from file
}

//----------------------------------------------------------------------------
// operator ==
// bool equailty operator for Periodical Books
// comapres title, month, and year
bool PeriodicalBook::operator==(const Book &rightSide) const{
    // casts Book to derived class Periodical Book
    const PeriodicalBook &right = static_cast<const PeriodicalBook&> (rightSide);

    return ((title == right.title) && (month == right.month) && (year == right.year));

}

//----------------------------------------------------------------------------
// operator !=
// bool inequality operator
bool PeriodicalBook::operator!=(const Book &rightSide) const{
    // casts Book to derived class Periodical Book
    const PeriodicalBook &right = static_cast<const PeriodicalBook&> (rightSide);

    return (!((title == right.title) && (month == right.month) && (year == right.year)));
}

//----------------------------------------------------------------------------
// operator <
// bool less that operator
// Periodicals compared by year, then month, then title
bool PeriodicalBook::operator<(const Book &rightSide) const{
    // casts Book to derived class Periodical Book
    const PeriodicalBook &right = static_cast<const PeriodicalBook&> (rightSide);

    // compare by year first
    if (year < right.year){
        return true;
    }else if (year == right.year){

        // if years are equal, compare by monrth
        if (month < right.month){
            return true;
        }else if (month == right.month){

            // if month is equal, compare by title
            if (title < right.title){
                return true;
            }else{
                return false; // title is more
            }
        }else{
            return false; // month is more
        }
    }else{
        return false; // year is more
    }
}

//----------------------------------------------------------------------------
// operator > 
// bool greater than operator
// Periodicals compared by year, then month, then title
bool PeriodicalBook::operator>(const Book &rightSide) const{
    // casts Book to derived class Periodical Book
    const PeriodicalBook &right = static_cast<const PeriodicalBook&> (rightSide);

    // compare by year first
    if (year > right.year){
        return true;
    }else if (year == right.year){

        // if years are equal, compare by monrth
        if (month > right.month){
            return true;
        }else if (month == right.month){

            // if month is equal, compare by title
            if (title > right.title){
                return true;
            }else{
                return false; // title is less
            }
        }else{
            return false; // month is less
        }
    }else{
        return false; // year is less
    } 
}
//----------------------------------------------------------------------------
// operator=()
// assigns periodical book
Book& PeriodicalBook::operator=(const Book &rightSide){
    // casts Book to derived class Periodical Book
    const PeriodicalBook &right = static_cast<const PeriodicalBook&> (rightSide);

    title = right.title;
    month = right.month;
    year = right.year;

    return *this;
}
