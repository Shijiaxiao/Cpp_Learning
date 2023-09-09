//
//  golf.hpp
//  9.5.1
//
//  Created by 史家箫 on 2022/2/22.
//

#ifndef golf_hpp
#define golf_hpp

#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

const int LEN = 40;
struct golf {
    char fullname[LEN];
    int handicap;
} ;

void setgolf(golf & g, const char * name, int hc);
int setgolf(golf & g);
void handicap(golf & g, int hc);
void showgolf(const golf & g);

#endif /* golf_hpp */
