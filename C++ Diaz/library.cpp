// Implements Library class

#include "library.h"

//---------------------------------------------------------------------------
// Library()
// default constructor initializes library
Library::Library(){ }

//---------------------------------------------------------------------------
// ~Library()
// destructor deallocates memory for library
Library::~Library(){ }

//---------------------------------------------------------------------------
// buildLibrary()
// builds library by taking in two files
// first file contains books
// second file contains patrons
void Library::buildLibrary(ifstream &bookFile, ifstream &patronFile){
    // passes bookfile into books to initialize collection
    books.buildCollection(bookFile);

    //passes patronfile in to patrons to initialize collection
    patrons.buildCollection(patronFile);
    
}

//---------------------------------------------------------------------------
// processComands(comand file)
// takes in a file containing comands and executes them
void Library::processComands(ifstream &comandFile){
    // executing comands title
    cout << "--------------------------- Executing Comands ------------------------------" << endl;
    // will hld the first char in each line of file
    char comand;

    // will hold patron ID
    int patronID;

    //will hold a pointer to the patron that executes the comand
    Patron* patron;

    for(;;){
        // read the first character as the command
        comandFile >> comand;
        comand = toupper(comand);

        

        if (comandFile.eof()) break;

        // check comands and execute them
        if (comand == 'D'){//-------------------Display Comand---------------
            this->displayLibrary();
            string s;
            getline(comandFile, s);
        }else if(comand == 'R'){//--------------Return Comand----------------

            // read patorn ID from File
            comandFile >> patronID;

            patron = patrons.getPatron(patronID);
            if (patron == nullptr){
                cout << left << setw(22) << "Invalid Patron ID: " << "PatronID: " << patronID << " Return Unsuccessful" << endl;
                string s;
                getline(comandFile, s);
            }else{

                Book* b = books.bookToReturn(comandFile);
                if (b == nullptr){
                    cout << "PatronID: " << patronID << " Return Unsuccessful" << endl;
                
                }else{
                    bool success = patron->returnBook(b);
                    if (!success){
                        cout << "PatronID: " << patronID << " Return Unsuccessful" << endl;
                    }else{
                        b->incrementBooksAvailable();
                        patron->updateHistory("R " + b->getTitle());
                    }
                    
                }

            } 

        }else if (comand == 'C'){//------------Checkout Comand---------------
            // read patron ID from file
            comandFile >> patronID;

            // pass in patron id and set patron
            patron = patrons.getPatron(patronID);
            if (patron == nullptr){
                cout << left << setw(22) << "Invalid Patron ID: " << "PatronID: " << patronID << " Checkout Unsuccessful" << endl;
                string s;
                getline(comandFile, s);
            }else{
                Book* b = books.checkOutBook(comandFile);
            
            
                if (b == nullptr){
                    cout << "PatronID: " << patronID << " Checkout Unsuccessful" << endl;
                
                }else{
                    patron->updateBooksCheckedOut(b);
                    patron->updateHistory("C " + b->getTitle());
                }
            }
            

        }else if (comand == 'H'){//---------------History Comand--------------
            
            // reads the patron ID from file
            comandFile >> patronID;
            
            // pass in patron ID and set patron 
            
            patron = patrons.getPatron(patronID);
            // if it return nullptr then there is no patron
            if (patron == nullptr){
                cout << left << setw(22) << "Invalid Patron ID: " <<  "PatronID: " <<  patronID << " Check History Unsuccessful" << endl;
                break;
            }

            // print the patrons history
            patron->printHistory();
            
        }else{//-----------Invalid Comand---------------
            // invalid input of comand
            cout << left << setw(22) <<  "Invalid Comand: " << "Command: " <<  comand << " is an invalid Command" << endl;
            // prints the error and ignores the rest of thel ine
            string s;
            getline(comandFile, s);
        }

    }
}


//---------------------------------------------------------------------------
// display Library()
void Library::displayLibrary() const{
    books.displayCollection();

    cout << endl;

    //patrons.displayCollection();
}
