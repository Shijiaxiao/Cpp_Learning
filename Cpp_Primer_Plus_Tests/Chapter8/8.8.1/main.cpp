//
//  main.cpp
//  8.8.1
//
//  Created by 史家箫 on 2022/2/13.
//

#include <iostream>

using namespace std;

void print(const char * str, int n = 0);

int main() {
    const char a[] = "Fuck";
    cout << sizeof(a) << endl;
    print(a);
    print(a,2);
    print(a,2);
    return 0;
}

void print(const char * str, int n) {
    static int x = 0;
    x++;
    if (n != 0)
        for (int i = 0; i < x; i++)
            cout << str << endl;
    else
        cout << str << endl;
}
