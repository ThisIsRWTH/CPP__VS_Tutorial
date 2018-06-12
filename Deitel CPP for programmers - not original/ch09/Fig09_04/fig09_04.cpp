// Fig. 9.4: fig09_04.cpp
// Demonstrating the class member access operators . and ->
#include <iostream>
using std::cout;
using std::endl;

// class Count definition
class Count 
{
public: // public data is dangerous
   // sets the value of private data member x
   void setX( int value )
   {
      x = value;
   } // end function setX

   // prints the value of private data member x
   void print() 
   { 
      cout << x << endl; 
   } // end function print

private:
   int x;  
}; // end class Count

int main()
{
   Count counter; // create counter object 
   Count *counterPtr = &counter; // create pointer to counter
   Count &counterRef = counter; // create reference to counter
   
   Count *counterPtr2 = &counterRef; // ME: farghi ba line 30 nemikone!

   cout << "Before Doing Anything: ";
   counter.print(); // ME: meghdare tasadofi tooye x gharar dare!



   cout << "Set x to 1 and print using the object's name: ";
   counter.setX( 1 ); // set data member x to 1
   counter.print(); // call member function print

   cout << "Set x to 2 and print using a reference to an object: ";
   counterRef.setX( 2 ); // set data member x to 2
   counterRef.print(); // call member function print

   cout << "Set x to 3 and print using a pointer to an object: ";
   counterPtr->setX( 3 ); // set data member x to 3
   counterPtr->print(); // call member function print



   (*counterPtr).print(); // ME: in khat ba khate 50 yeksane!

   counterPtr2->print(); // ME: natije in khat ba khate 50 yeksane!



   return 0;  
} // end main

/**************************************************************************
 * (C) Copyright 1992-2009 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
