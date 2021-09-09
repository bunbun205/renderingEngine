#pragma once

#include <header.hpp>

class RGBcolor {

public:
        RGBcolor();
        RGBcolor(double c);
        RGBcolor(double R, double G, double B);
        RGBcolor(const RGBcolor &c);

        double R();
        double G();
        double B();

        RGBcolor &operator += (const RGBcolor &c);
        RGBcolor &operator -= (const RGBcolor &c);
        RGBcolor &operator *= (const double a);
        RGBcolor &operator /= (const double a);

public:
        double r, g, b;
};

// Fixed RGBColor definitions

#define Black RGBcolor(0.0)
#define White RGBcolor(1.0)
#define Red   RGBcolor(1.0, 0.0, 0.0)
#define Green RGBcolor(0.0, 1.0, 0.0)
#define Blue  RGBcolor(0.0, 0.0, 1.0)

// RGBColor inline functions definition

inline void writeColor(std::ostream &out, RGBcolor color) {

        out <<  static_cast<int>(255.999 * color.R()) << ' ' <<
                static_cast<int>(255.999 * color.G()) << ' ' <<
                static_cast<int>(255.999 * color.B()) << '\n';
}

inline RGBcolor operator + (const RGBcolor &c1, const RGBcolor &c2) {

        return RGBcolor(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
}

inline RGBcolor operator - (const RGBcolor &c1, const RGBcolor &c2) {

        return RGBcolor(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b);
}

inline RGBcolor operator * (const RGBcolor &c, const double a) {

        return RGBcolor(c.r * a, c.g * a, c.b * a);
}

inline RGBcolor operator * (const double a, const RGBcolor &c) {

        return c * a;
}

inline RGBcolor operator / (const RGBcolor &c, const double a) {

        return c * ( 1  / a);
}

inline bool operator == (const RGBcolor &c1, const RGBcolor &c2) {

        return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b;
}

inline RGBcolor Pow(const RGBcolor &c, double p) {

        return RGBcolor(std::pow(c.r, p), std::pow(c.g, p), std::pow(c.b, p));
}