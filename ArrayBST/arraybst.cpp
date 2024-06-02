#include <iostream>
#include "./include/arraybst.h"

ArrayBST::ArrayBST()
{

    int size;
    std::cout << "Enter the Maximum size of Array : ";
    std::cin >> size;

    nodes = new ArrayNode(size);

    // this->nodes->array.resize(this->nodes->maxSize, -1); // This initialize the array with -1 and max size will be maxSize
};

bool ArrayBST::isEmpty()
{
    return this->nodes->array[0] == -1;
};

void ArrayBST::addBST(int data)
{

    if (isEmpty())
    {
        this->nodes->array[0] = data;
        return;
    };

    int index = 0;

    while (index < this->nodes->maxSize)
    {

        if (this->nodes->array[index] == -1)
        {
            this->nodes->array[index] = data;
            return;
        }

        else if (data < this->nodes->array[index])
        {
            index = 2 * index + 1; // Moving to the left child
        }

        else if (data > this->nodes->array[index])
        {
            index = 2 * index + 2; // Moving to the right child
        }
        else
        {
            std::cout << "Add :: Could Not Add : " << data << "\n";
            return;
        }
    }
};

bool ArrayBST::search(int key)
{
    if (isEmpty())
    {
        std::cout << "Search :: Tree is Empty" << "/n";
        return false;
    }

    int index = 0;
    while (index < this->nodes->maxSize && this->nodes->array[index] != -1)
    {

        if (this->nodes->array[index] == key)
        {
            return true;
        }

        else if (this->nodes->array[index] > key)
        {
            index = 2 * index + 1;
        }
        else
        {
            index = 2 * index + 2;
        }
    }

    return false;
};

bool ArrayBST::remove(int key)
{

    if (isEmpty())
    {
        std::cout << "Remove :: Tree is Empty" << "/n";
        return false;
    }

    int index = 0;
    int parent = -1;
    while (index < this->nodes->maxSize && this->nodes->array[index] != -1)
    {

        if (key == this->nodes->array[index])
        {
            this->nodes->array[index] = -1;
            return true;
        }

        else if (this->nodes->array[index] > key)
        {
            index = 2 * index + 1;
        }
        else
        {
            index = 2 * index + 2;
        }
    }

    return false;
};

ArrayBST::~ArrayBST()
{
    delete nodes;
    std::cout << "Destructor called";
};

void ArrayBST::print()
{
    if (isEmpty())
    {
        std::cout << "Print :: Tree is Empty" << "/n";
        return;
    };

    for (int i = 0; i < this->nodes->maxSize; i++)
    {
        std::cout << this->nodes->array[i] << ", ";
    }

    std::cout << "\n";
};

int main()
{

    ArrayBST arbst;

    // bool ifempty = arbst.isEmpty();
    std::cout << "IfEmpty : " << arbst.isEmpty() << "\n";

    arbst.addBST(5);
    arbst.addBST(2);
    arbst.addBST(3);

    std::cout << "IfEmpty : " << arbst.isEmpty() << "\n";
    std::cout << "IfPresent : " << arbst.search(2) << "\n";
    std::cout << "IfRemoved : " << arbst.remove(2) << "\n";
    std::cout << "IfPresent : " << arbst.search(2) << "\n";

    arbst.print();
}