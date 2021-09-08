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

// RGBColor inline functions definition

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