/****************************
[file name]--------------
node.h
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2021-10-26 
[last edit]---
2021-11-01
****************************/ 


#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
    private:
        // Private section
        long *_Node; 
    public:
        // Public Declarations

        Node(); //constructor
        Node(unsigned int _length); //constructor
        ~Node(); //destructor
        
        // Assignment operator
        Node& operator=(const Node&);
        
        void set_Node(long* other);
        long* get_Node(void) const;
        /*
            Allocates for _Node a long array of size _length
            Returns the address of newly allocated _Node
        */
        long* reCreate(unsigned int _length);
        void setElement_Node(unsigned int pos, long val);
        long getElement_Node(unsigned int pos) const;
        
        void delete_Node();
        
    protected:
        // Protected Declarations
};
#endif
