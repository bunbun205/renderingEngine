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

// RGBColor inline functions prototypes

RGBcolor operator + (const RGBcolor &c1, const RGBcolor &c2);
RGBcolor operator - (const RGBcolor &c1, const RGBcolor &c2);
RGBcolor operator * (const RGBcolor &c, const double a);
RGBcolor operator * (const double a, const RGBcolor &c);
RGBcolor operator / (const RGBcolor &c, const double a);
bool operator == (const RGBcolor &c1, const RGBcolor &c2);
RGBcolor Pow(const RGBcolor &c, double p);