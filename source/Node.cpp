/****************************
[file name]--------------
node.cpp
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-10-26 
[last edit]---
2021-11-01
****************************/ 

#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Node.h"
using namespace std;

void Node::delete_Node()
{
    delete [] this->_Node;
}

long Node::getElement_Node(unsigned int pos) const
{
    return this->_Node[pos];
}

/*
Assigns val to _Node[pos].
2021-10-31
*/
void Node::setElement_Node(unsigned int pos, long val)
{
    this->_Node[pos] = val;
}
/*
Set and get function
2021-10-31
*/
void Node::set_Node(long* other)
{
    this->_Node = other;
}
long* Node::get_Node(void) const
{
    return this->_Node;
}

/*
Define the assignment operator.
2021-10-31
*/
Node& Node::operator=(const Node &node)
{
    this->set_Node(node.get_Node() );
    return *this;   
}

/*
Define the constructor.
2021-10-26
*/
Node::Node()
{
    //printf("call Node()\n");
    _Node = NULL;
}
Node::Node(unsigned int _length)
{
    //printf("call Node(unsigned int _length)\n");
    if(_length == 0)
    {
        _Node = NULL;
    }
    else
    {
        _Node = new long [_length];
        assert(_Node != NULL);
    }
}
/*
Define the destructor.
2021-10-26
*/
Node::~Node()
{
    //printf("call ~Node()\n");
    if(_Node == NULL)
    {
        delete _Node;
    }
    else
    {
        delete[] _Node;
    }   
}
/*
Allocates for _Node a long array of size _length
Returns the address of newly allocated _Node
2021-10-26
*/
long* Node::reCreate(unsigned int _length)
{
    if(_length == 0)
    {
        _Node = NULL;
    }
    else if(_length > 0)
    {
        _Node = new long [_length];
        assert(_Node != NULL);
    }
    else
    {
        _Node = NULL;
        cout << "in (Node::reCreate(unsigned int _length))," 
             << " you set a negtive value in _length..." 
             << endl;
    }
    return _Node;
}
