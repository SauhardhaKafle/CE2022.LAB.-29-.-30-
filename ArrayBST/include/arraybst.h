#ifndef ArrayBST_h
#define ArrayBST_h

#include "./../../interface/BST.h"
#include <vector>

struct ArrayNode
{

    std::vector<int> array;
    int maxSize;
    ArrayNode(int size) : maxSize(size), array(size, -1){};
};

class ArrayBST : public BST
{

public:
    ArrayBST();
    ~ArrayBST();

    bool isEmpty();
    void addBST(int data);
    bool remove(int key);
    bool search(int key);
    void print();

private:
    ArrayNode *nodes;
};

#endif