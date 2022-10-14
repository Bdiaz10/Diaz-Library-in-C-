// book factory implementation
#include "book_factory.h"

//----------------------------------------------------------------------------
// BookFactory()
// defualt constructor build book factory
// book factory holds book pointers to each genre
// genres include: fictional, childrens, and periodical
BookFactory::BookFactory(){
    // initializes bookFacotry to nullptr
    for (int i = 0; i < 26; i++){
        bookFactory[i] = nullptr;
    }

    // fills factory with each genre of book
    bookFactory[2] = new ChildrensBook;
    bookFactory[5] = new FictionBook;
    bookFactory[15] = new PeriodicalBook;

}
//----------------------------------------------------------------------------
// ~BookFactory()
// BookFactory destructor
// deallocate all memory in bookFactory
BookFactory::~BookFactory(){
    for (int i = 0; i < 26; i++){
        // if index contains an object, delete and set to nullptr
        if (bookFactory[i] != nullptr){
           delete bookFactory[i];
           bookFactory[i] = nullptr; 
        }
    }
}

//----------------------------------------------------------------------------
// hash()
// hash function takes in char and returns a 'key' as int
// key maps char to the correct book object
int BookFactory::hash(char ch) const{
    toupper(ch);

    int key = ch - 65;

    // if character is not A-Z
    if (key < 1  || key >= 26) return -1;

    // if that index doesn't contain an object
    if (bookFactory[key] == nullptr) return -1;

    // ch is valid so return key
    return key;
}

//----------------------------------------------------------------------------
// createIt ()
// creates a book object based on parameter passed in
// returns a book pointer 
Book* BookFactory::createIt(char ch) const{
    
    //generate hashkey from ch passed in
    int subscript = hash(ch);

    // hash function returns -1 if given an invalid char
    // if char is invalue return a nullptr
    if (subscript == -1) return nullptr;

    //returns object that corresponds to hashed subscript
    return bookFactory[subscript]->create();
}
