// Alexander Herder

// Labb2, IntVector.h – klassdefinition
#pragma once

#include <initializer_list>
#include <iosfwd>

class IntVector
{
private:
    int capacity{1}; // initial capacity
    int elements{0}; // initial amount elements
    void expand(); // expand helper function if vector reaches max capacity
    int* data{nullptr}; // initialize pointer to dynamically allocated array to null

public:
    IntVector(); // default constructor
    IntVector(std::initializer_list<int> vector); // constructor with initialized values
    IntVector(const IntVector&); // copy constructor
    IntVector(IntVector&& other); // move constructor
    ~IntVector(); // destructor
    IntVector& operator=(const IntVector&); // assignment operator
    const int& operator[](int index) const; // index operator for const vectors
    int& operator[](int index); // index operator for non-const vectors
    friend std::ostream& operator<<(std::ostream&, const IntVector&); // operator overloading for <<
    void push_back(int value); // push_back method for adding new int to vector
    int size() const; // function to get size of IntVector
};
