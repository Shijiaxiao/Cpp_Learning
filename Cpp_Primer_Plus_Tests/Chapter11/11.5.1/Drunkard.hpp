//
//  Drunkard.hpp
//  11.5.1
//
//  Created by 史家箫 on 2022/3/9.
//

#ifndef Drunkard_hpp
#define Drunkard_hpp

#include <iostream>

namespace Drunk {
    class Vector {
    public:
        enum Mode {RECT, POL};
    private:
        double x;
        double y;
        double magnitude;
        double angle;
        Mode mode;
        // private methods for setting values.
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1, double n2, Mode form = RECT);
        void reset(double n1, double n2, Mode form = RECT);
        ~Vector();
        double xval() const { return x; }
        double yval() const { return y; }
        double magval() const { return magnitude; }
        double angval() const { return angle; }
        // friend function.
        friend Vector operator+(const Vector & a, const Vector & b);
    } ;
}

#endif /* Drunkard_hpp */
