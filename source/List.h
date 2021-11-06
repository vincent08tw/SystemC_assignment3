/****************************
[file name]--------------
List.h
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-10-28
[last edit]---
2021-11-02
****************************/ 


#ifndef LIST_H
#define LIST_H

#include "Node.h"
using namespace std;

class List : public Node
{
    private:
        // Private section
        unsigned int length;
    public:
        // Public Declarations
        
        List(); //constructor 
        List(unsigned int _length); //constructor
        List(const List &other); 
        ~List(); //destructor
        
        // Assignment operator that assigns other to *this.
        List& operator=(const List& other);
        
        // The function returns the value of length.
        unsigned int getLength() const;
        
        int setLength(unsigned int);

        int setElement(unsigned int pos, long val);
        
        // If legal, return _Node[pos]; If illegal, return -99999
        long getElement(unsigned int pos) const;
        
        List operator+(const List& other);
        List& operator+=(const List& other);
        List operator++(); // prefix
        List operator++(int); // postfix
        List operator--(); // prefix
        List operator--(int); // postfix
        
        friend ostream& operator<<(ostream&, List);
        friend istream& operator>>(istream&, List&);
        friend ofstream& operator<<(ofstream&, List);
        friend ifstream& operator>>(ifstream&, List&);
        
    protected:
        // Protected Declarations
};

#endif
