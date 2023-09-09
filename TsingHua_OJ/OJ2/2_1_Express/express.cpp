//
//  main.cpp
//  Express
//
//  Created by 史家箫 on 2022/3/25.
//

#include <iostream>

typedef long long DIST;
typedef long long COST;

struct Node {
    DIST dist;
    COST cost;
    bool whether;
    int previous;
} ;
