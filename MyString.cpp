#include "MyString.h"

uint MyStrlen(const char* arr)
{
    uint size = 0;
    uint i = 0;
    while (arr[i] != '\0') {

        size++;
        i++;
    }

    return size;
}

uint MyStrlen(const MyString& myString) { return myString.GetSize(); }

MyString::MyString(const char* arr) 
    : _size(MyStrlen(arr))
{
    _data = new char[_size];
    memcpy(_data, arr, _size);
}

MyString::~MyString()
{
    delete[] _data;
}

uint MyString::GetSize() const { return _size; }

void MyString::Insert(const uint pos, const char symbol)
{
    _size++;
    char* buff = new char[_size];

    memcpy(buff, _data, (pos - 1) * sizeof(char));
    memcpy(&buff[pos - 1], &symbol, sizeof(char));
    memcpy(&buff[pos], &_data[pos - 1], (_size - pos) * sizeof(char));

    delete[] _data;
    _data = buff;
}

void MyString::Swap(const uint pos, const char symbol)
{
    _data[pos - 1] = symbol;
}

void MyString::Push_Back(const MyString& otherMyString)
{
    char* buff = new char[_size + MyStrlen(otherMyString)];

    memcpy(buff, _data, _size * sizeof(char));
    memcpy(&buff[_size], otherMyString._data, MyStrlen(otherMyString) * sizeof(char));
    
    delete[] _data;
    _data = buff;
    _size += MyStrlen(otherMyString);
}

void MyString::Pop(const uint pos)
{
    char* buff = new char[_size - 1];

    memcpy(buff, _data, (pos) * sizeof(char));
    memcpy(&buff[pos - 1], &_data[pos], (_size - pos) * sizeof(char));

    delete[] _data;
    _data = buff;
    _size--;
}

MyString& MyString::operator=(const MyString& otherMyString)
{
    if(_size != otherMyString._size) {

        exit(0);
    }

    memcpy(_data, otherMyString._data, _size * sizeof(char));
    return *this;
}

void MyString::operator+(const MyString& otherMyString)
{
    char* buff = new char[_size + MyStrlen(otherMyString)];

    memcpy(buff, _data, _size * sizeof(char));
    memcpy(&buff[_size], otherMyString._data, MyStrlen(otherMyString) * sizeof(char));
    
    delete[] _data;
    _data = buff;
    _size += MyStrlen(otherMyString);
}

void MyString::operator+(const char* arr)
{
    char* buff = new char[_size + MyStrlen(arr)];

    memcpy(buff, _data, _size * sizeof(char));
    memcpy(&buff[_size], arr, MyStrlen(arr) * sizeof(char));
    
    delete[] _data;
    _data = buff;
    _size += MyStrlen(arr);
}

ostream& operator<<(ostream& os, const MyString& MyString)
{
    for (uint i = 0; i < MyString._size; i++) {

        os << MyString._data[i];
    }

    return os;
}