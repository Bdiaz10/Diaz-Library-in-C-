#include "childrens_book.h"


//---------------------------------------------------------------------------
// constructor for childrens book
// initializes books available to 1
// can hold a maximum of 5 of each childrens book
ChildrensBook::ChildrensBook(){
    booksAvailable = 5;
    maxBooks = 5;
}

//----------------------------------------------------------------------------
// parameter constructor

ChildrensBook::ChildrensBook(const string &title, const string &author){
    this->title = title;
    this->author = author;

}


//---------------------------------------------------------------------------
// get author
// returns author of childrens book
string ChildrensBook::getAuthor() const{
    return this->author;
}

//----------------------------------------------------------------------------
// create
// creates and returns a pointer to a new Childrens Book object
Book* ChildrensBook::create() const{
    return new ChildrensBook;
}

//---------------------------------------------------------------------------
// dipslays childrens book
void ChildrensBook::displayBook() const{
    cout << left << setw(7) << booksAvailable << setw(27) << author << setw(37) << title << setw(4) << year << endl;
}

//---------------------------------------------------------------------------
// setData()
// set data for childrens book
// takes in line from book file
// childrens book holds: title, author, year
void ChildrensBook::setData(ifstream &infile){
    infile.get(); // get (and ignore) blank before author

    getline(infile, author, ',');

    infile.get(); // get (and ignore) blank before title

    getline(infile, title, ',');

    infile >> year;
}

//---------------------------------------------------------------------------
// operator ==
// equality operator for ChildrensBooks
// compares titles, authors, year
bool ChildrensBook::operator==(const Book &rightSide) const{
    // casts Book to derived class childrens Book
    const ChildrensBook &right = static_cast<const ChildrensBook&> (rightSide);

    return ((title == right.title) && (author == right.author));
}

//---------------------------------------------------------------------------
// operator !=
// inequality operator for childrens books
bool ChildrensBook::operator!=(const Book &rightSide) const{

    // casts Book to derived class childrens Book
    const ChildrensBook &right = static_cast<const ChildrensBook&> (rightSide);

    return (!((title == right.title) && (author == right.author)));

}

//---------------------------------------------------------------------------
// operator <
// childrens books are compared by title, then author, alphabetically
bool ChildrensBook::operator<(const Book &rightSide) const{

    // casts Book to derived class childrens Book
    const ChildrensBook &right = static_cast<const ChildrensBook&> (rightSide);

    // compared by title first
    if (title < right.title){
        return true;
    //if titles are equal, compare by author
    }else if (title == right.title){
       if (author < right.author){
           return true;
       }else{
           return false;
       }
    // title is more than righside title
    // return false
    }else{
        return false;
    }
}

//---------------------------------------------------------------------------
// operator >
// childrens books are comparde by title, then author, alphabetically
bool ChildrensBook::operator>(const Book &rightSide) const{
    // casts Book to derived class childrens Book
    const ChildrensBook &right = static_cast<const ChildrensBook&> (rightSide);

    // compared by title first
    if (title > right.title){
        return true;
    //if titles are equal, compare by author
    }else if (title == right.title){
       if (author > right.author){
           return true;
       }else{
           return false;
       }
    // title is less than righside title
    // return false
    }else{
        return false;
    }
}
//---------------------------------------------------------------------------
// operator=()
// overloads assignmenr operator for childrens books
Book& ChildrensBook::operator=(const Book &rightSide){
    // casts Book to derived class childrens Book
    const ChildrensBook &right = static_cast<const ChildrensBook&> (rightSide);

    author = right.author;
    title = right.title;
    year = right.year;
    
    return  *this;
}
