/****************************
[file name]--------------
main.cpp
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-10-26 
[last edit]---
2021-11-02
****************************/ 


#include <iostream>
#include <fstream>
#include <iomanip>
#include "Node.h"
#include "List.h"

using namespace std;

struct my_out
{
    my_out(std::ostream& out1,
           std::ostream& out2) : out1_(out1), 
                                 out2_(out2) {}

    std::ostream& out1_;
    std::ostream& out2_;

};

// operator<<() function for most data types.
template <typename T>
my_out& operator<<(my_out& mo, T const& t)
{
    mo.out1_ << t;
    mo.out2_ << t;
    return mo;
}

// Allow for std::endl to be used with a my_out
my_out& operator<<(my_out& mo, std::ostream&(*f)(std::ostream&))
{
    mo.out1_ << f;
    mo.out2_ << f;
    return mo;
}

int main(int argc, char** argv)
{
    
    
    ofstream output_file;
    output_file.open("RESULT");
    my_out myout(cout, output_file);
    if(!output_file.is_open())
    {
        myout << "Failed to open the file: " 
              << "RESULT." 
              << endl;
        return 0;
    }
    
    ifstream input_file;
    input_file.open(argv[1]);
    if(!input_file.is_open())
    {
        myout << "Failed to open the file: " 
              << argv[1] 
              << "." 
              << endl;
        return 0;
    }
    List list1; 
    input_file >> list1;
    myout << "list1.getLength() = "
          << list1.getLength()
          << "\n"
          << "list1's content: "
          << list1
          << endl << endl;
    
    // Copy the List to other 3 Lists using 3 different ways.
    myout << ">> Now copy the List to other 3 Lists using 3 different ways."
          << endl << endl;
    
    myout << ">> do List list2(list1);"
          << endl;   
    List list2(list1);
    myout << "list2.getLength() = "
          << list2.getLength()
          << "\n"
          << "list2's content: "
          << list2
          << endl << endl;
    
    myout << ">> do List list3 = list1;"
          << endl;
    List list3 = list1;
    myout << "list3.getLength() = "
          << list3.getLength()
          << "\n"
          << "list3's content: "
          << list3
          << endl << endl;
         
    myout << ">> Now use simple way to copy list1 to list4"
          << endl; 
         
    List list4(list1.getLength());
    for(unsigned int i = 0; i < list4.getLength(); i++)
    {
        list4.setElement(i,list1.getElement(i));
    }
    myout << "list4.getLength() = "
          << list4.getLength()
          << "\n"
          << "list4's content: "
          << list4
          << endl << endl;
    
    // Add two of the Lists using operator+
    myout << ">> Now add two of the Lists using operator+ \n"
          << "list5 will be the result of (list1 + list2) \n"
          << endl;
    List list5;
    list5 = list1 + list2;
    myout << "list5.getLength() = "
          << list5.getLength()
          << "\n"
          << "list5's content: "
          << list5
          << endl << endl;
    
    // Use operator++ to add 1 to another List
    myout << ">> Now use operator++ to add 1 to another List \n"
          << "list5 will be the result of (list1++) \n"
          << "list5 = list1++;"
          << endl << endl;
    list5 = list1++;
    myout << "list5.getLength() = "
          << list5.getLength()
          << "\n"
          << "list5's content: "
          << list5
          << endl << endl;
    myout << "list1.getLength() = "
          << list1.getLength()
          << "\n"
          << "list1's content: "
          << list1
          << endl << endl;
    
    // Use operator++(long) to add 1 to another List
    myout << ">> Now use operator++(long) to add 1 to another List \n"
          << "list4 will be the result of (++list2) \n"
          << "list4 = ++list2;"
          << endl << endl;
    list4 = ++list2;
    myout << "list4.getLength() = "
          << list4.getLength()
          << "\n"
          << "list4's content: "
          << list4
          << endl << endl;
    myout << "list2.getLength() = "
          << list2.getLength()
          << "\n"
          << "list2's content: "
          << list2
          << endl << endl;
    
    // Use operator+= to add another List to a List
    myout << ">> Now use operator+= to add another List to a List \n"
          << "list5 will be the result of (list5 + list1) \n"
          << "list5 += list1;"
          << endl << endl;
    list5 += list1;
    myout << "list5.getLength() = "
          << list5.getLength()
          << "\n"
          << "list5's content: "
          << list5
          << endl << endl;

    // Use operator-- to subtract 1 from all elements in a List 
    myout << ">> Now use operator-- " 
          << "to subtract 1 from all elements in a List \n"
          << "list5 will be the result of (list5 + list1) \n"
          << "list5 = list2--;"
          << endl << endl;
    list5 = list2--;
    myout << "list5.getLength() = "
          << list5.getLength()
          << "\n"
          << "list5's content: "
          << list5
          << endl << endl;
    myout << "list2.getLength() = "
          << list2.getLength()
          << "\n"
          << "list2's content: "
          << list2
          << endl << endl;
    
    // Use operator--(long) to subtract 1 from all elements in another List
    myout << ">> Now use operator-- "
          << "to subtract 1 from all elements in a List \n"
          << "list3 will be the result of (--list2) \n"
          << "list3 = --list2;"
          << endl << endl;
    list3 = --list2;
    myout << "list3.getLength() = "
          << list3.getLength()
          << "\n"
          << "list3's content: "
          << list3
          << endl << endl;
    myout << "list2.getLength() = "
          << list2.getLength()
          << "\n"
          << "list2's content: "
          << list2
          << endl << endl;
         
    
    return 0;
}



