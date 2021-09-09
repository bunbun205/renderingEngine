#include <RGBcolor.hpp>

// RGBColor member methods definition

RGBcolor::RGBcolor() { r = g = b = 0.0; }

RGBcolor::RGBcolor(double c) { r = g = b = c; }

RGBcolor::RGBcolor(double R, double G, double B) { r = R; g = G; b = B; }

RGBcolor::RGBcolor(const RGBcolor &c) { r = c.r; g = c.g; b = c.b; }

double RGBcolor::R() { return r; }

double RGBcolor::G() { return g; }

double RGBcolor::B() { return b; }

RGBcolor &RGBcolor::operator += (const RGBcolor &c) {

        r += c.r; g += c.g; b += c.b;
        return *this;
}

RGBcolor &RGBcolor::operator -= (const RGBcolor &c) {

        r -= c.r; g -= c.g; b -= c.b;
        return *this;
}

RGBcolor &RGBcolor::operator *= (const double a) {

        r *= a; g *= a; b *= a;
        return *this;
}

RGBcolor &RGBcolor::operator /= (const double a) {

        return *this *= (1 / a);
}