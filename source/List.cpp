/****************************
[file name]--------------
List.cpp
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-10-28
[last edit]---
2021-11-02
****************************/ 


#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "List.h"
using namespace std;

/*
Operator>> overloading
2021-11-01
*/
ifstream& operator>>(ifstream &in, List &list)
{
    long temp;
    in >> temp;
    list.setLength(temp);
    for(unsigned int i = 0; i < list.getLength(); i++)
    {
        in >> temp;
        list.setElement(i,temp);
    }
    
    return in;
}

/*
Operator<< overloading
2021-11-01
*/
ofstream& operator<<(ofstream &out, List list)
{
    if(list.getLength() == 0)
    {
        cout << "in ofstream& operator<<(ofstream &out, List list),"
             << " list.getLength() == 0" 
             << endl;
    }
    else if (list.getLength() < 0)
    {
        cout << "in ofstream& operator<<(ofstream &out, List list)," 
             << " list.getLength() < 0" 
             << endl;
    }
    else
    {
        for(unsigned int i = 0; i < list.getLength(); i++)
        {
            // must be written like this
            static_cast<ostream&>(out) << list.getElement(i) << " "; 
            //out << list.getElement(j) << " "; << this will get error 
        }
        out << endl;
    }
    return out;
}

istream& operator>>(istream &in, List &list)
{
    long temp;
    if(list.getLength() == 0)
    {
        cout << "in istream& operator>>(istream &in," 
             << " List list), list.getLength() == 0" 
             << endl;
    }
    else if (list.getLength() < 0)
    {
        cout << "in istream& operator>>(istream &in, List list)," 
             << " list.getLength() < 0" 
             << endl;
    }
    else
    {
        for(unsigned int i = 0; i < list.getLength(); i++)
        {
            in >> temp;
            list.setElement(i,temp);
        }
    }
    
    return in;
}

/*
Operator<< overloading
2021-10-31
*/
ostream& operator<<(ostream &out, List list)
{
    if(list.getLength() == 0)
    {
        cout << "in ostream& operator<<(ostream &out, List list),"
             << " list.getLength() == 0" 
             << endl;
    }
    else if (list.getLength() < 0)
    {
        cout << "in ostream& operator<<(ostream &out, List list)," 
             << " list.getLength() < 0" 
             << endl;
    }
    else
    {
        for(unsigned int i = 0; i < list.getLength(); i++)
        {
            out << list.getElement(i) << " ";
        }
        out << endl;
    }
    return out;
}

/*
Operator-- overloading
postfix
2021-10-31
*/
List List::operator--(int)
{
    List tmp(*this);
    long tmp_value;
    for(unsigned int i = 0;i < this->length;i++)
    {
        tmp_value = this->getElement(i);
        tmp_value--;
        this->setElement(i, tmp_value);
    }
    return tmp;
}

/*
Operator-- overloading
prefix
2021-10-31
*/
List List::operator--()
{
    long tmp_value;
    for(unsigned int i = 0;i < this->length;i++)
    {
        tmp_value = this->getElement(i);
        this->setElement(i, --tmp_value);
    }
    return *this;
}


/*
Operator++ overloading
postfix
2021-10-31
*/
List List::operator++(int)
{
    List tmp(*this);
    long tmp_value;
    for(unsigned int i = 0;i < this->length;i++)
    {
        tmp_value = this->getElement(i);
        tmp_value++;
        this->setElement(i, tmp_value);
    }
    return tmp;
}

/*
Operator++ overloading
prefix
2021-10-31
*/
List List::operator++()
{
    long tmp_value;
    for(unsigned int i = 0;i < this->length;i++)
    {
        tmp_value = this->getElement(i);
        this->setElement(i, ++tmp_value);
    }
    return *this;
}


/*
Operator+= overloading
2021-10-31
*/
List& List::operator+=(const List& other)
{
    unsigned loop = this->length < other.length ? this->length : other.length;
    for(unsigned int i = 0;i < loop;i++)
    {
        this->setElement(i, this->getElement(i)+other.getElement(i));
    }
    return *this;
}

/*
Operator+ overloading
2021-10-31
*/
List List::operator+(const List& other)
{
    unsigned loop = this->length < other.length ? this->length : other.length;
    List lt(loop);
    for(unsigned i = 0;i < loop;i++)
    {
        lt.setElement(i, this->getElement(i)+other.getElement(i));
    }
    return lt;
}

/*
Returns the value of _Node[pos] if pos is legal.
If pos is illegal, prints an error message and returns -99999.

2021-10-31
*/
long List::getElement(unsigned int pos) const
{
    unsigned int length;
    length = this->getLength();
    if( (pos >= length) || (pos < 0) )
    {
        cout << "(List::getElement Error) pos " 
             << pos 
             << " is illegal " 
             << endl;
        return -99999;
    }
    else
    {
        return this->getElement_Node(pos);
    }
}

/*
Assigns val to _Node[pos].
The function returns 1 if pos is legal; otherwise prints an error
message and returns 0.
Notice that there is a need to add a respective member function
to the base Node class.

2021-10-31
*/
int List::setElement(unsigned int pos, long val)
{
    unsigned int length;
    length = this->getLength();
    if( (pos >= length) || (pos < 0) )
    {   // if pos over the length or pos is negtive
        cout << "(List::setElement Error) pos "
             << val 
             << " is illegal " 
             << endl;
        return 0;
    }
    else
    {
        this->setElement_Node(pos,val);
        return 1;
    }
}

/*
If the original length is 0, the function sets a new length, uses
reCreate() to allocates an array of size length to _Node,
then returns 1.

If the original length is not 0, the function prints an error
message then returns 0.
2021-10-31
*/
int List::setLength(unsigned int newLength)
{
    if(this->length == 0)
    {
        this->set_Node(this->reCreate(newLength));
        this->length = newLength;
        return 1;
    }
    else
    {
        cout << "(List::setLength) original length is not 0" 
             << endl; 
        return 0;
    }
}

 
/*
The function returns the value of length.
2021-10-31
*/
unsigned int List::getLength() const
{
    return this->length;
}
/*
Assignment operator that assigns other to *this.
2021-10-31
*/
List& List::operator=(const List& other)
{
//  this->set_Node(other.get_Node() );
    if(this != &other)  
    {
        this->delete_Node(); //array may not be NULL
        this->length = other.length;
        
        if(length > 0)
        {
            this->reCreate(length); 
            for(unsigned int i = 0; i < this->getLength();i++)
            {
                this->setElement(i, other.getElement(i));
            }
        }
        else
        {
            cout << "List::operator=(const List& other) "
                 << "length is not a positive value" 
                 << endl; 
            this->reCreate(length);
        }
    }// if the same one, do nothing

    return *this;   
}

/*
Define the constructor.
It must inherits and calls Node() to initialze _Node
Initializes length as 0
2021-10-28
*/
List::List()
{
    //printf("call List()\n");
    this->length = 0;
}

/*
It must inherits and calls Node(_length) to initailize _Node
Initializes length as _length
2021-10-28
*/
List::List(unsigned int _length) : Node(_length)
{
    //printf("call List(unsigned int _length)\n");
    if(_length == 0)
    {
        this->length = 0;
    }
    else
    {
        this->length = _length;
    }
}

/*
The copy constructor that copies other to *this

*/
List::List(const List &other)
{
    //printf("call List(const List &other)\n");
    length = other.length;
    if(length > 0)
    {
        this->reCreate(length);
        for(unsigned int i = 0;i < this->getLength();i++)
        {
            this->setElement(i, other.getElement(i));   
        }   
    }
    else
    {
        this->reCreate(length);
        cout << "(List::List(const List &other)) length is <= 0" << endl; 
    } 
} 
/*
Define the destructor.
Implicitly calls ~Node()
Resets length to 0
2021-10-28
*/
List::~List()
{
    //printf("call ~List()\n");
    this->length = 0;
}


