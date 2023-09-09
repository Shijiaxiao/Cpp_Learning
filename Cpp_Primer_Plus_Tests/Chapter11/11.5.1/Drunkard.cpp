//
//  Drunkard.cpp
//  11.5.1
//
//  Created by 史家箫 on 2022/3/9.
//

#include "Drunkard.hpp"
#include <cmath>

using namespace std;
using namespace Drunk;

// private functions.
void Vector::set_mag() {
    magnitude = sqrt(x * x + y * y);
}

void Vector::set_ang() {
    if (x == 0 && y == 0)
        angle = 0;
    else
        angle = atan2(y, x);
}

void Vector::set_x() {
    x = magnitude * cos(angle);
    // cout << cos(angle) << endl;
}

void Vector::set_y() {
    y = magnitude * sin(angle);
    // cout << sin(angle) << endl;
}


// public fuctions.
Vector::Vector() {}

Vector::Vector(double n1, double n2, Mode form) {
    mode = form;
    if (mode == RECT) {
        x = n1;
        y = n2;
        set_mag();
        set_ang();
    }
    else if (mode == POL) {
        magnitude = n1;
        angle = n2;
        set_x();
        set_y();
    }
}

void Vector::reset(double n1, double n2, Mode form) {
    mode = form;
    if (mode == RECT) {
        x = n1;
        y = n2;
        set_mag();
        set_ang();
    }
    else if (mode == POL) {
        magnitude = n1;
        angle = n2;
        set_x();
        set_y();
    }
}

Vector::~Vector() {}

Vector Drunk::operator+(const Vector & a, const Vector & b) {
    return Vector(a.x + b.x, a.y + b.y);
}
