#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class Employee{
public:
    string Position, Name;
    unsigned int Age;

    Employee(){};
    ~Employee(){};
    Employee(string nam, string pos, unsigned int ag){
        Age=ag;
        Position=pos;
        Name=nam;
    }

    friend ostream& operator << (ostream& o, const Employee& s)
    {
        o << "name: " << s.Name << ", position: " << s.Position <<", age " << s.Age <<endl;
        return o;
    }
};






