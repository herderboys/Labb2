// Alexander Herder
// Labb2, IntVector.cpp – definitioner av icke-triviala medlemsfunktioner

#include "IntVector.h"
#include <iostream>


// default constructor
IntVector::IntVector()
{
    data = new int[capacity];
}


// constructor with initialized values
IntVector::IntVector(std::initializer_list<int> vector)
{
    data = new int[vector.size() * 2];
    capacity = vector.size() * 2;

    int index = 0;
    for (int value : vector)
    {
        data[index++] = value;
        elements++;
    }
}


// copy constructor
IntVector::IntVector(const IntVector& other)
{
    data = new int[other.capacity];
    capacity = other.capacity;
    elements = other.elements;

    for (int i = 0; i < other.elements; i++)
    {
        data[i] = other[i];
    }
}

// move constructor
IntVector::IntVector(IntVector&& other)
{
    data = other.data;

    capacity = other.capacity;
    elements = other.elements;

    other.data = nullptr;
    other.capacity = 0;
    other.elements = 0;
}


// destructor
IntVector::~IntVector()
{
    delete[] data;
}


// assignment operator
IntVector& IntVector::operator=(const IntVector& other)
{
    if (this != &other)
    {
        delete[] data;
        data = new int[other.capacity];
        capacity = other.capacity;
        elements = other.elements;

        for (int i = 0; i < other.elements; i++)
        {
            data[i] = other[i];
        }
    }
    return *this;
}


// index operator for const vectors
const int& IntVector::operator[](const int index) const
{
    return data[index];
}

// index operator for non-const vectors
int& IntVector::operator[](const int index)
{
    return data[index];
}


// operator overloading for <<
std::ostream& operator<<(std::ostream& os, const IntVector& vector)
{
    if (vector.elements != 0)
    {
        for (int i = 0; i < vector.elements; i++)
        {
            if (i != vector.elements - 1)
            {
                os << vector[i] << " ";
            }
            else
            {
                os << vector[i];
            }
        }
    }
    return os;
}


// expand helper function if vector reaches max capacity
void IntVector::expand()
{
    int newCap = capacity * 2;
    int* dataTmp = new int[newCap];

    for (int i = 0; i < elements; i++)
    {
        dataTmp[i] = data[i];
    }
    delete[] data;
    data = dataTmp;
    capacity = newCap;
}


// push_back method for adding new int to vector
void IntVector::push_back(const int value)
{
    if (elements == capacity)
    {
        expand();
    }
    data[elements] = value;
    elements++;
}


// function to get size of IntVector
int IntVector::size() const
{
    return elements;
}
