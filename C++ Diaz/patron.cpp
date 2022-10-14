
#include "patron.h"

//---------------------------------------------------------------------------
// Patron (ID , Name)
// default constructor
Patron::Patron(const int &patronID, const string &patronName){
    this->ID = patronID;
    this->name = patronName;
}
//---------------------------------------------------------------------------
// Patron
//default Constructor
Patron::Patron() { }

//---------------------------------------------------------------------------
// ~Patron()
// destroys patron object
Patron::~Patron(){

}
//---------------------------------------------------------------------------
// getID()
// returns patrons ID number as int
int Patron::getID() const{
    return this->ID;
}
//---------------------------------------------------------------------------
// getName()
// returns patrons name as a string
string Patron::getName() const{
    return this->name;
}

//---------------------------------------------------------------------------
// printHistory()
// prints the history of a patron
void Patron::printHistory() const{
    // prints the name of the patron
    cout << ID << name << " History: " << endl;

    if (patronHistory.size() == 0){
        cout << "   " << "No History " << endl;
    }
    
    //loops through vector and prints histroy
    for (int i = 0; i < patronHistory.size(); i++){
        cout << "   " << patronHistory[i] << endl;

    }

}
//---------------------------------------------------------------------------
// updateHistory()
// updates the patron history with string passed in
void Patron::updateHistory(string history){
    // adds string to vector
    patronHistory.push_back(history);
}
//---------------------------------------------------------------------------
// update books checked out
void Patron::updateBooksCheckedOut(Book* b){
    booksCheckedOut.push_back(b);
}
//---------------------------------------------------------------------------
bool Patron::returnBook(Book *book){

    // go through books currently checkout 
    for (int i = 0; i < booksCheckedOut.size(); i++){
        if (book == booksCheckedOut[i]){ // if the patron has the book
            booksCheckedOut.erase(booksCheckedOut.begin() + i);
            return true;
        }
    }

    return false;
}