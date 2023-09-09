//
//  overload.hpp
//  Object as the judgment condition
//
//  Created by 史家箫 on 2022/3/14.
//

#ifndef overload_hpp
#define overload_hpp

#include <iostream>

class overload {
private:
    static const bool bad = false;
    static const bool good = true;
    // static const bool fail = -1;
    bool state;
public:
    // Constructors:
    overload();
    overload(char sign);
    ~overload();
    // Class methods:
    bool status() { return state; }
    // Overload operator for the judgement of class:
    bool operator ! ();
    // Typecast to the type of judgement signs:
    explicit operator bool() const;
} ;

#endif /* overload_hpp */
