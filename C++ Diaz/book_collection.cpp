// implements book collection

#include "book_collection.h"

//----------------------------------------------------------------------------
// default constructor 
BookCollection::BookCollection(){
    for (int i = 0 ; i < 26; i++){
        bookGenres[i] = nullptr;
    }

    bookGenres[2] = new BinTree;
    bookGenres[5] = new BinTree;
    bookGenres[15] = new BinTree;
}
//----------------------------------------------------------------------------
// destructor
BookCollection::~BookCollection(){
    for (int i = 0; i < 26; i++){
        if (bookGenres[i] != nullptr){
            bookGenres[i]->makeEmpty();
            delete bookGenres[i];
            bookGenres[i] = nullptr;
        }
    }
}
//----------------------------------------------------------------------------
// hash()
// hash function maps char to correct index of genre
int BookCollection::hash(char ch) const{
    int key = ch - 65;

    if (bookGenres[key] == nullptr) return -1;

    return key;
    
}
//----------------------------------------------------------------------------
void BookCollection::buildCollection(ifstream &infile){
    char key; // reads from file what object to make
    Book* b;  // will point at object obtained from factory

    for (;;){

        infile >> key;
        if(infile.eof()) break;

        b = bookFactory.createIt(key);
        if (b == nullptr){
            string s;
            getline(infile, s);
            continue;
        } 


        b->setData(infile);

        int index = hash(key);

        bookGenres[index]->insert(b);


    }

}

//----------------------------------------------------------------------------
// getBook()
// returns pointer to book in collection
Book* BookCollection::checkOutBook(ifstream &infile) const{

    char genre;
    char copyType;
    string title;
    Book* b;
    
    infile >> genre;

    infile >> copyType;
    if (copyType != 'H'){
        string s;
        getline(infile, s);
        cout << left << setw(22) << "Invalid Book Format: ";
        return nullptr;
    } 

    

    if (genre == 'F'){
        int i = hash(genre);
        string author;

        infile.get();
        getline(infile, author, ',');

        infile.get(); // ignore white space

        getline(infile, title, ',');
        
        FictionBook fbook(author, title);

        b =  bookGenres[i]->retrieveFiction(fbook);
        if (b == nullptr){
            cout << left << setw(22) << "Invalid Book: ";
            return nullptr; 
        }
        

        //b->displayBook();

        if (b->getBooksAvailable() > 0){
            b->decrementBooksAvailable();
            return b;
        }else{
            return nullptr;
        }
        

    }else if (genre == 'C'){
        
        int i = hash(genre);
        string author;
        infile.get();
        getline(infile, title, ',');

        infile.get(); // ignore white space

        getline(infile, author, ',');

        ChildrensBook cbook(title, author);
        b =  bookGenres[i]->retrieveChildren(cbook);
        if (b == nullptr){
            cout << left << setw(22) << "Invalid Book: ";
            return nullptr;
        }

        if (b->getBooksAvailable() > 0){
            b->decrementBooksAvailable();
            return b;
        }else{
            return nullptr;
        }

    }else if (genre == 'P'){
        
        int i = hash(genre);
        int year;
        int month;
        infile >> year >> month;

        infile.get();

        
        getline(infile, title, ',');

        PeriodicalBook target(year, month, title);
        
        b = bookGenres[i]->retrievePeriodical(target);
        if (b == nullptr){

            cout << left << setw(22) << "Invalid Book: ";
            return nullptr;
            
        }


        if (b->getBooksAvailable() > 0){
            b->decrementBooksAvailable();
            
            return b;

        }else{
            return nullptr;
        }


    }else{
        string s;
        getline(infile, s);
        cout << left << setw(22) << "Invalid Genre: ";
        return nullptr;
    }
    return nullptr;
}

//----------------------------------------------------------------------------
// bookToReturn
Book* BookCollection::bookToReturn(ifstream &infile) const{
    char genre;
    char copyType;
    string title;
    Book* b;
    
    infile >> genre;

    infile >> copyType;
    if (copyType != 'H'){
        string s;
        getline(infile, s);
        cout << left << setw(22) << "Invalid Book Format: ";
        return nullptr;
    } 

    

    if (genre == 'F'){
        int i = hash(genre);
        string author;

        infile.get();
        getline(infile, author, ',');

        infile.get(); // ignore white space

        getline(infile, title, ',');
        
        FictionBook fbook(author, title);

        b =  bookGenres[i]->retrieveFiction(fbook);
        if (b == nullptr){
            cout << left << setw(22) << "Invalid Book: ";
            return nullptr; 
        }else{
            return b;
        }
        
    }else if (genre == 'C'){
        
        int i = hash(genre);
        string author;
        infile.get();
        getline(infile, title, ',');

        infile.get(); // ignore white space

        getline(infile, author, ',');

        ChildrensBook cbook(title, author);
        b =  bookGenres[i]->retrieveChildren(cbook);
        if (b == nullptr){
            cout << left << setw(22) << "Invalid Book: ";
            return nullptr;
        }else{
            return b;
        }


    }else if (genre == 'P'){
        
        int i = hash(genre);
        int year;
        int month;
        infile >> year >> month;

        infile.get();

        
        getline(infile, title, ',');

        PeriodicalBook target(year, month, title);
        
        b = bookGenres[i]->retrievePeriodical(target);
        if (b == nullptr){

            cout << left << setw(22) << "Invalid Book: ";
            return nullptr;
            
        }else{
            return b;
        }

    }else{
        string s;
        getline(infile, s);
        cout << left << setw(22) << "Invalid Genre: ";
        return nullptr;
    }
    return nullptr;
}


//----------------------------------------------------------------------------
// display Childrens books
void BookCollection::displayChildrensBooks() const{
    int index = hash('C');

    if (bookGenres[index] != nullptr){
        cout << "------------------------------ Childrens Books -----------------------------" << endl;
        cout << left << setw(7)  << "AVAIL" << setw(27) << "AUTHOR" << setw(37) << "TITLE" << setw(4) << "YEAR" << endl;
        bookGenres[index]->displayInOrder();
    }
}
//----------------------------------------------------------------------------
// display Fiction books
void BookCollection::displayFictionBooks() const{
    int index = hash('F');

    if (bookGenres[index] != nullptr){
        cout << "------------------------------- Fiction Books ------------------------------" << endl;
        cout << left << setw(7) << "AVAIL" << setw(27) << "AUTHOR" << setw(37) << "TITLE" << setw(4) << "YEAR" << endl;
        bookGenres[index]->displayInOrder();
    }

}

//----------------------------------------------------------------------------
// display Periodical books
void BookCollection::displayPeriodicalBooks() const{
    int index = hash('P');

    if (bookGenres[index] != nullptr){
        cout << "----------------------------- Periodical Books -----------------------------" << endl;
        cout << left << setw(7) << "AVAIL" << setw(40) << "TITLE" << setw(5) << "DATE" << endl;
        bookGenres[index]->displayInOrder();

    }
}

//----------------------------------------------------------------------------
// displayCollection ()
// displays all books in book collection
void BookCollection::displayCollection() const{
    displayChildrensBooks();
    displayFictionBooks();
    displayPeriodicalBooks();

}
