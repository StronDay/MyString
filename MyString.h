#pragma once
#include <iostream>

using namespace std;
typedef unsigned int uint;

class MyString
{
private:

    char* _data;
    uint _size;

public:

    MyString(const char* arr);
    ~MyString();

    uint GetSize() const;

    void Insert(const uint pos, const char symbol);
    void Swap(const uint pos, const char symbol);
    void Push_Back(const MyString& otherMyString);
    void Pop(const uint pos);

    void operator+(const MyString& otherMyString);
    void operator+(const char* arr);

    MyString& operator=(const MyString& otherMyString);

    friend ostream& operator<<(ostream& os, const MyString& MyString);
};

 uint MyStrlen(const char* arr);
 uint MyStrlen(const MyString& myString);