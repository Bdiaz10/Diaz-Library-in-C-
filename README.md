# Diaz-Library-in-C-
Program to show my favorite aspects of C++ and OOP such as dynamic memory allocation, operator overloading, inheritance, abstraction, and the factory design pattern.

1. To use program:
   
   After creating a Library object, you can simply call 
   buildLibrary() and pass in a file containing book data(bookdata.txt),
   and a file containing the patron data(patrondata.txt). 
   Library::buildLibrary("bookdata.txt", "patrondata.txt");
   
   process library commands by passing a command file into
   Library::processCommands("commmanddata.txt");
   
   

2. Book Factory is a hashtable and uses a hash function
   to map a given value (char that represents genre) to 
   the corresponding book and returns it.

   BookCollection is a hashtable of BinTrees. This implements
   a hashfunction to map the correct genre to the right index
   that holds the corresponding BinTree for that genre.

   PatronCollection is a hashtable of Patron objects. The Patron
   doesn't use a hashfunction, but uses the patrons ID number
   as the corresponding index in the table that will holds that 
   patrons object.

3. Book Data is originally read in the library class in the 
   buildLibrary() Function. This function the passes the file 
   to the BookCollection which has a buildCollection() method.
   The build collection method builds books add inserts them
   into a hashtable of BinTrees where the books are stored in
   Nodes in a BinTree.

4. The commands are read in the Library class, specifically in the
   method Library::processCommands(). After reading the commands,
   commands are primarily performed through the BookCollection in 
   the functions checkOutBook, and bookToReturn.

5. When I was first designing the project, I planned to not violate the
   open-close princible. Everything was going well while I was implementing
   the book collection and the patron collection, but I ran into a lot of
   problems when trying to process comands. I now have
   a better understanding of how I can implement this, but I've decided to
   leave it as it is for now but inlcude this in the second iteration
   of this library project.
