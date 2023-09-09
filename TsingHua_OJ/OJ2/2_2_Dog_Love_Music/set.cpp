//
//  main.cpp
//  Try_set
//
//  Created by 史家箫 on 2022/4/3.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Node {
    int x;
    char y;
    bool operator<(const Node & temp) const { return x < temp.x; }
} ;

Node temp[5];
set <Node> q;

int main() {
    temp[0].x = 2; temp[0].y = 'b'; q.insert(temp[0]);
    temp[1].x = 3; temp[1].y = 'c'; q.insert(temp[1]);
    temp[2].x = 1; temp[2].y = 'a'; q.insert(temp[2]);
    temp[3].x = 8; temp[3].y = 't'; q.insert(temp[3]);
    temp[4].x = 4; temp[4].y = 'd'; q.insert(temp[4]);
    
    temp[1].y = 'f';
    q.insert(temp[1]);
    
    temp[1].x = 5;
    q.insert(temp[1]);
    getchar();
    return 0;
}
