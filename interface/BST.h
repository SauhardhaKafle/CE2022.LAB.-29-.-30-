
#ifndef BST_H
#define BST_H
 
class BST{

public:

//Default constructor
BST(){};

virtual bool isEmpty()= 0;
virtual void addBST(int data)=0;
virtual bool remove(int key) = 0;
virtual bool search(int key) = 0;

~BST(){};
};


#endif