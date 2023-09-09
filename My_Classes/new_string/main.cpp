//
//  main.cpp
//  newString
//
//  Created by 史家箫 on 2022/3/13.
//

#include <iostream>
#include <cstring>
#include "newString.hpp"

void typecast(void);
void con_or_oper(void);
void str_lit_ref(void);
void initPtr(void);

int main() {
    // typecast();
    // con_or_oper();
    // str_lit_ref();
    initPtr();
    return 0;
}


void typecast(void) {
    newString input = "Fuck" ;
    char * a = new char [5];
    std::strcpy(a, (char*)input); // In-depth copy.
    a[2] = 'a';
    std::cout << a << std::endl;
}
void con_or_oper(void) {
    newString a = "Fuck you man!" ;
    newString b = a;
    b = a;
}

void str_lit_ref(void) {
    using std::cout;
    using std::endl;
    
    /*
    newString as = "Blank" ;
    char ac[] = " space." ;
    
    newString bs = " morning!" ;
    char bc[] = "Good" ;
    // const char * bc = bct;
    
    newString cs = "Galway" ;
    newString ds = " girl." ;
   
    char cc [] = "Let" ;
    char dc [] = " it be." ;
    
    // newString rsa = as + newString(ac);
    newString rsa = as + ac; // Exact the same with the former one. Typecast(using constructor) first and class '+'.
    newString rsb = bc + bs;
    newString rsc = cs + ds;
    newString rsd = newString(cc) + dc;
    newString rse = as + " space." ;
    newString rsf = newString("Easy") + " on me." ;
    
    cout << rsa << endl << rsb << endl << rsc << endl << rsd << endl << rse << endl << rsf << endl;
     */
    
    newString a = newString("Fuck") ;
    newString b = a + " you!" ;
    cout << b << endl;
    
    // newString a = "Fuck" + " you!";
    // cout << a << endl;
}

void initPtr(void) {
    newString * ptr = new newString("Fuck you!");
    delete ptr;
}
