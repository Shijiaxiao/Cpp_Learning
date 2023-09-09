//
//  newString.hpp
//  newString
//
//  Created by 史家箫 on 2022/3/13.
//

#ifndef newString_hpp
#define newString_hpp

#include <iostream>

class newString {
private:
    constexpr static const char welcome [22] = "Welcome to newString!" ;
    char * str;
    int len;
    int serialNumber;
    static const int CILIM = 100;
    static int num_strings;
public:
    // (1)constructors:
    newString();
    newString(const char * s);
    // copy constructor.
    newString(const newString & s);
    // deconstructor:
    ~newString();
    
    // (2)class functions:
    int length () const { return len ; }  // inline function(short type).
    static int HowMany() { return num_strings; } // define in calss.
    
    // (3)overload operators:
    newString & operator = (const char * s);
    newString & operator = (const newString & s);
    const newString operator + (const newString & s) const;
    char & operator [] (int i);
    const char & operator [] (int i) const;
    
    // (4)tpyeCast class to char*
    explicit operator char * () const;
    
    // (5)friend fuctions(overload operators):
    friend std::ostream & operator << (std::ostream & os, const newString & st);
    friend std::istream & operator >> (std::istream & is, newString & st);
    // compare 2 strings:
    friend bool operator < (const newString & st1, const newString & st2);
    friend bool operator > (const newString & st1, const newString & st2);
    friend bool operator == (const newString & st1, const newString & st2);
    // concatenate strings:
    friend const newString operator + (const newString & s1, const char * s2); // no &, type is not sure!
    friend const newString operator + (const char * s1, const newString & s2); // no &, type is not sure!
    // friend const newString operator + (const char * s1, const char * s2); // illegal!!!
} ;

#endif /* newString_hpp */
