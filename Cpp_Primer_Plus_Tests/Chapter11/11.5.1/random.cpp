//
//  main.cpp
//  random
//
//  Created by 史家箫 on 2022/3/9.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

int main() {
    srand((unsigned int)(time(NULL)));
    double a;
    double rad = 45.0 / std::atan(1.0);
    for (int i = 0; i < 10; i++) {
        a = (rand() % 361) / rad;
        std::cout << a << std::endl;
    }
    std::cout << 360/rad << std::endl;
    return 0;
}
