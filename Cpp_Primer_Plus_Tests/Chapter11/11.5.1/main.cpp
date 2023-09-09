//
//  main.cpp
//  11.5.1
//
//  Created by 史家箫 on 2022/3/9.
//

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include "Drunkard.hpp"


int main() {
    using namespace std;
    double distance;
    double dstep;
    char ans;
    const double Rad = 45.0 / atan(1.0);
    // cout << Rad << endl;
    
    srand((unsigned int)(time(NULL)));
    
    // Open file.
    char fileName[100] = "/Users/shijiaxiao/Desktop/cpp program/review practice/11.5.1/Random Walk.txt";
    ofstream fout;
    fout.open(fileName);
    if (fout.is_open()) cout << "Open file sucsessfully!" << endl;
    else {
        cout << "Wrong path!" << endl;
        return 0;
    }
    
    do {
        fflush(stdin);
        cout << "Please input targeted distance:";
        cin >> distance;
        cout << "Please input the distance of each step:";
        cin >> dstep;
        fout << endl;
        Drunk::Vector drunker(0,0);
        int steps = 1;
        while (drunker.magval() < distance) {
            fout << "Step" << steps << ':' << " From:(" << drunker.xval() << ", " << drunker.yval() << "), ";
            double angle = (rand() % 361);
            // cout << steps << ':' << angle << endl;
            angle /= Rad;
            // cout << steps << ": ";
            Drunk::Vector everyStep(dstep, angle, Drunk::Vector::POL);
            
            // cout << everyStep.magval() << ", " << everyStep.angval() << ", " << everyStep.xval() << ", " << everyStep.yval() <<endl;;
            
            fout << "walk(" << everyStep.xval() << ", " << everyStep.yval() << "), ";
            drunker = drunker + everyStep;
            fout << "to(" << drunker.xval() << ", " << drunker.yval() << "). ";
            fout << "Whole distance travelled:" << drunker.magval() << endl << endl;
            steps++;
        }
        fout << "Finished!" << endl;
        cout << "Want it again(q to quit):";
        cin >> ans;
    } while (ans != 'q') ;
    fout.close();
    return 0;
}
