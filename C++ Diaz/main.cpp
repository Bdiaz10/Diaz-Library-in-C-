/*
#include "bintree.h"
#include "book_factory.h"
#include "book.h"
#include "childrens_book.h"
#include "periodical_book.h"
#include "fiction_book.h"
#include "book_collection.h"
#include "patron_collection.h"
*/
#include "library.h"
#include <iostream>
using namespace std;

int main(){
    

   Library myLib;
   ifstream bookFile("bookdata.txt");
   ifstream patronFile("patrondata.txt");
   ifstream comandFile("comanddata.txt");

   myLib.buildLibrary(bookFile, patronFile);
   myLib.processComands(comandFile);
   
   

}