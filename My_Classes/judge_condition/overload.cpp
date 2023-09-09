//
//  overload.cpp
//  Object as the judgment condition
//
//  Created by 史家箫 on 2022/3/14.
//

#include "overload.hpp"
#include <cctype>

overload::overload() { state = fail; }

overload::overload(char sign) {
    if (toupper(sign) == 'G')
        state = good;
    else if (toupper(sign) == 'B')
        state = bad;
    else
        state = fail;
}

overload::~overload() {}

bool overload::operator ! () {
    return state;
}

overload::operator bool() const {
    return state;
}
