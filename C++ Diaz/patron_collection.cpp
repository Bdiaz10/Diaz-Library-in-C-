#include "patron_collection.h"

//---------------------------------------------------------------------------
// PatronCollection()
// default constructor
// itializes patron pointer array
PatronCollection::PatronCollection(){
    // loops over patron array
    // sets all values to nullptr
    for (int i = 0; i < 10000; i++){
        patrons[i] = nullptr;
    }

    
}

//---------------------------------------------------------------------------
// ~PatronCollection()
// destroys entire patron collection
PatronCollection::~PatronCollection(){
    // loops over patrons array
    // if the value has an object, delete it and set to nullptr
    for(int i = 0; i < 10000; i++){
        if (patrons[i] != nullptr){
            delete patrons[i];
            patrons[i] = nullptr;
        }
    }

}
//---------------------------------------------------------------------------
// buildCollection(ifstream)
// builds collection of patrons
void PatronCollection::buildCollection(ifstream &infile) {

    // store the first item in the file the patron id
    int id;

    for (;;){
        // read first int in file as patron id
        infile >> id;

        // Check if at the end of data file
        if (infile.eof()) break;

        // string to hold the name of patron
        string name;
        getline(infile, name); // read the rest of the line after ID

        // creates a new Patron object
        // at the index corresponding to their ID
        patrons[id] = new Patron(id, name);

    }


}

//---------------------------------------------------------------------------
// displayCollection()
// displays all patrons and their ID in the collection
void PatronCollection::displayCollection() const {

    //prints title for patron display
    cout << "Patrons" << endl << "ID    " << "Name" << endl;
    //loops through patron array
    for (int i = 0; i < 10000; i++){

        // if patrons[i] has an object, display the name ann ID
        if (patrons[i] != nullptr){

            cout << i << " " << patrons[i]->getName() << endl;
        }
    }
}

//---------------------------------------------------------------------------
// getPatron
// takes in a patron ID as an int
// returns a pointer to that patron
Patron* PatronCollection::getPatron(const int &ID) const{


    return patrons[ID];


}
