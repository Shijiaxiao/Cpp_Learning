//
//  newString.cpp
//  newString
//
//  Created by 史家箫 on 2022/3/13.
//

#include "newString.hpp"
#include <cstring>

int newString::num_strings = 0;

// (1)constructors:

newString::newString() {
    len = 0;
    str = new char [len + 1];
    str[0] = '\0';
    num_strings++;
    serialNumber = num_strings;
    std::cout << "My newString " << serialNumber << ": Calling constructor with no parameter. Default object created.\n" ;
}

newString::newString(const char * s) {
    len = int(std::strlen(s));
    str = new char [len + 1];
    std::strcpy(str, s);
    num_strings++;
    serialNumber = num_strings;
    std::cout << "My newString " << serialNumber << ": Calling constructor with a parameter of const char*. Object \"" << str << "\" created.\n" ;
}

newString::newString(const newString & s) {
    len = s.len;
    str = new char [len + 1];
    std::strcpy(str, s.str);
    num_strings++;
    serialNumber = num_strings;
    std::cout << "My newString " << serialNumber << ": Calling copy constructor. Object \"" << str << "\" created.\n" ;
}

// deconstructor:
newString::~newString() {
    if (str[0] != '\0')
        std::cout << "My newString " << serialNumber << ": Object \"" << str << "\" deleted, " << --num_strings << " left.\n";
    else
        std::cout << "My newString " << serialNumber << ": Default object deleted, " << --num_strings << " left.\n" ;
    delete [] str;
}

// (2)class functions:



// (3)overload operators:
newString & newString::operator = (const char * s) {
    delete [] str;
    len = int(std::strlen(s));
    str = new char [len + 1];
    std::strcmp(str, s);
    std::cout << "My newString " << serialNumber << ": Calling overloaded '=' with const char*. Assigned \"" << str << "\" successfully.\n" ;
    return * this;
}

// return const, pass unconst parameter is illegal! You can chage sth in the function.
newString & newString::operator = (const newString & st) {
    if (this == &st)
        return * this ; // all work done.
    len = st.len;
    delete [] str; // free old allocated storage. otherwise it will cost the waste of storage.
    str = new char [len + 1];
    std::strcpy(str, st.str);
    std::cout << "My newString " << serialNumber << ": Calling overloaded '=' with const newString&. Assigned \"" << str << "\" successfully.\n" ;
    return * this ;
}

const newString newString::operator + (const newString & s) const {
    char * tempChar = new char [len + s.len - 1];
    std::strcpy(tempChar, str);
    std::strcat(tempChar, s.str);
    newString temp = tempChar;
    std::cout << "Calling newString + newString.\n" ;
    return temp;
}

char & newString::operator [] (int i) {
    return str[i];
}

// only for use of const string objects:
const char & newString::operator [] (int i) const {
    return str[i];
}


// (4)typecast to char* (C style):

newString::operator char * () const {
    return str;
}


// (5)definations of friend fuctions.

std::ostream & operator << (std::ostream & os, const newString & st) {
    os << st.str;
    return os;
}

std::istream & operator >> (std::istream & is, newString & st) {
    char temp[newString::CILIM];
    std::cin.get(temp, newString::CILIM);
    if (is) st = temp; // qualified input!
    while (is && is.get() != '\n') continue; // clean the buffer(get first, judge later).
    return is;
}

bool operator < (const newString & st1, const newString & st2) {
    // if (std::strcmp(st1.str, st2.str) < 0) return true;
    // else return false;
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator > (const newString & st1, const newString & st2) {
    return st2 < st1;
}

bool operator == (const newString & st1, const newString & st2) {
    return (std::strcmp(st1.str, st2.str) == 0);
}

const newString operator + (const newString & s1, const char * s2) {
    char * tempChar = new char [s1.len + std::strlen(s2) - 1];
    std::strcpy(tempChar, (char*)s1);
    std::strcat(tempChar, s2);
    newString temp = tempChar;
    std::cout << "Calling newString + const char * .\n" ;
    return temp;
}

const newString operator + (const char * s1, const newString & s2) {
    char * tempChar = new char [std::strlen(s1) + s2.len - 1];
    std::strcpy(tempChar, s1);
    std::strcat(tempChar, (char*)s2);
    newString temp = tempChar;
    std::cout << "Calling char * const + newString.\n" ;
    return temp;
}


























/*
const newString operator + (const char * s1, const char * s2) {
    char * tempChar = new char [std::strlen(s1) + std::strlen(s1) - 1];
    std::strcpy(tempChar, s1);
    std::strcat(tempChar, s2);
    newString temp = tempChar;
    return temp;
}

 int a;
 char b[10];
 while (cin >> a);
 if (cin);
 */



