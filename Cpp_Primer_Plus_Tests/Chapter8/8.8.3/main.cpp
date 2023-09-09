//
//  main.cpp
//  8.8.3
//
//  Created by 史家箫 on 2022/2/13.
//

#include <iostream>
#include <cctype>
using namespace std;

void upper(string &a);

int main() {
    string a = "fuck!";
    upper(a);
    cout << a << endl;
    return 0;
}

void upper(string &a) {
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++)
        if (isalpha(a[i]))
            a[i] = toupper(a[i]);
}
