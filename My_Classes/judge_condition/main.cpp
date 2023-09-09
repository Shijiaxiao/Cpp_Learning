//
//  main.cpp
//  Object as the judgment condition
//
//  Created by 史家箫 on 2022/3/14.
//

#include <iostream>
#include "overload.hpp"

int main() {
    overload TRY = 'G';
    if (TRY)
        std::cout << "Typecast to bool(explicit) has been implicitly employed!\n" ;
    return 0;
}
