#include "fiction_book.h"

//---------------------------------------------------------------------------
// Fiction Book default constructor
// holds 5 fiction books
FictionBook::FictionBook(){
    booksAvailable = 5;
    maxBooks = 5;
}
//---------------------------------------------------------------------------
// paramter constructor
FictionBook::FictionBook(const string &author, const string &title){
    this->author = author;
    this->title = title;
}
//---------------------------------------------------------------------------
// getAuthor
// returns author of fictional book
string FictionBook::getAuthor() const{
    return this->author;
}

//----------------------------------------------------------------------------
// create
// creates and returns a pointer to a new Fiction Book object
Book* FictionBook::create() const{
    return new FictionBook;
}

//---------------------------------------------------------------------------
// display Fiction Book
// <author> <title> <year>
void FictionBook::displayBook() const{
    cout << left << setw(7) << booksAvailable << setw(27) << author << setw(37) << title << setw(4) << year << endl;
}

//---------------------------------------------------------------------------
// set data for Fiction Book
// fiction book holds: author, title, date (year)
void FictionBook::setData(ifstream &infile){
    infile.get(); // get (and ignore) blank before author

    getline(infile, author, ',');

    infile.get(); // get (and ignore) blank before title

    getline(infile, title, ',');

    infile >> year;
}

//---------------------------------------------------------------------------
// operator ==
// equality operator for Fictions
// compares titles, authors, and years
bool FictionBook::operator==(const Book &rightSide) const{
    // casts Book to derived class Fiction Book
    const FictionBook &right = static_cast<const FictionBook&> (rightSide);

    return ((title == right.title) && (author == right.author));
}

//---------------------------------------------------------------------------
// operator !=
// inequality operator for Fiction books
bool FictionBook::operator!=(const Book &rightSide) const{
    // casts Book to derived class Fiction Book
    const FictionBook &right = static_cast<const FictionBook&> (rightSide);

    return (!((title == right.title) && (author == right.author)));

}

//---------------------------------------------------------------------------
// operator <
// Fiction books are compared by author, then title, alphabetically
bool FictionBook::operator<(const Book &rightSide) const{
    // casts Book to derived class Fiction Book
    const FictionBook &right = static_cast<const FictionBook&> (rightSide);

    // compared by author first
    if (author < right.author){
        return true;
    //if authors are equal, compare by title
    }else if (author == right.author){
       if (title < right.title){
           return true;
       }else{
           return false;
       }
    // author is more than righside title
    // return false
    }else{
        return false;
    }
}

//---------------------------------------------------------------------------
// operator >
// Fiction books are comparde by author, then title, alphabetically
bool FictionBook::operator>(const Book &rightSide) const{
    // casts Book to derived class Fiction Book
    const FictionBook &right = static_cast<const FictionBook&> (rightSide);

    // compared by author first
    if (author > right.author){
        return true;
    //if authors are equal, compare by title
    }else if (author == right.author){
       if (title > right.title){
           return true;
       }else{
           return false;
       }
    // author is less than righside title
    // return false
    }else{
        return false;
    }
}
//---------------------------------------------------------------------------
//operator=()
// assigns fiction book to right side
Book& FictionBook::operator=(const Book &rightSide){
    // casts Book to derived class Fiction Book
    const FictionBook &right = static_cast<const FictionBook&> (rightSide);

    author = right.author;
    title = right.title;
    year = right.year;

    return *this;
}