//
//  main.cpp
//  9.5.1
//
//  Created by 史家箫 on 2022/2/22.
//

#include "golf.hpp"

int main() {
    // cout << LEN << endl;
    
    golf andy;
    setgolf(andy, "shijiaxiao", 55);
    
    golf ann;
    setgolf(ann);
    
    showgolf(andy);
    showgolf(ann);
    
    return 0;
}
