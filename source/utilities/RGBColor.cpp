#include <RGBcolor.hpp>

// RGBColor member methods definition

inline RGBcolor::RGBcolor() { r = g = b = 0.0; }

inline RGBcolor::RGBcolor(double c) { r = g = b = c; }

inline RGBcolor::RGBcolor(double R, double G, double B) { r = R; g = G; b = B; }

inline RGBcolor::RGBcolor(const RGBcolor &c) { r = c.r; g = c.g; b = c.b; }

double inline RGBcolor::R() { return r; }

double inline RGBcolor::G() { return g; }

double inline RGBcolor::B() { return b; }

RGBcolor inline &RGBcolor::operator += (const RGBcolor &c) {

        r += c.r; g += c.g; b += c.b;
        return *this;
}

RGBcolor inline &RGBcolor::operator -= (const RGBcolor &c) {

        r -= c.r; g -= c.g; b -= c.b;
        return *this;
}

RGBcolor inline &RGBcolor::operator *= (const double a) {

        r *= a; g *= a; b *= a;
        return *this;
}

RGBcolor inline &RGBcolor::operator /= (const double a) {

        return *this *= (1 / a);
}