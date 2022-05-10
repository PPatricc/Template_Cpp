#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Book{
public:
    string Author;
    unsigned int NumOfPages;

    Book(){};
    ~Book(){};
    Book(string A, unsigned int N){
        Author=A;
        NumOfPages=N;
    }

    friend ostream& operator << (ostream& o, const Book& s)
    {
        o << "Author: " << s.Author <<", Number of Pages: " << s.NumOfPages <<endl;
        return o;
    }
};