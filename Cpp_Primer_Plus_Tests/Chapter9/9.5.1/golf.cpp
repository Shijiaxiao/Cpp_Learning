//
//  golf.cpp
//  9.5.1
//
//  Created by 史家箫 on 2022/2/22.
//

#include "golf.hpp"

// extern const int LEN;

void setgolf(golf & g, const char * name, int hc){
    // for (int i = 0; i < strlen(name); i++)
    //     g.fullname[i] = name[i];
    strcpy(g.fullname, name);
    g.handicap = hc;
}

int setgolf(golf & g) {
    char name[LEN];
    int hc;
    cout << "Please enter your name:" ;
    cin.getline(name, LEN);
    // cin.get();
    cout << "Please enter the handicap:" ;
    while(! (cin >> hc)) {
        cin.clear();
        fflush(stdin);
        cout << "Enter again please:" ;
    }
    if (name[0] != '\0') {
        setgolf(g, name, hc);
        return 1;
    } else return 0;
    return 0;
}

void handicap(golf & g, int hc) {
    g.handicap = hc;
}

void showgolf(const golf & g) {
    cout << g.fullname << endl << g.handicap << endl;
}
