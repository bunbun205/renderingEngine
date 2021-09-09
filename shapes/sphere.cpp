#include <sphere.hpp>

Sphere::Sphere(const Point3f center, const double radius): c(center), r(radius) {

        auto A     = rec.rHit.direction().lengthSquared();
        auto halfB = dot(rec.rHit.origin() - c, rec.rHit.direction());
        auto C     = distance(rec.rHit.origin(), c);

        auto discriminant = halfB * halfB - A * C;

        if(discriminant < 0) {
                rec.hit = false;
        } else{

                auto sqrtD = std::sqrt(discriminant);

                auto root = (-halfB - sqrtD) / A;

                if(root < kEpsilon || root > HugeValue) {

                        root = (-halfB + sqrtD) / A;

                        if(root < kEpsilon || root > HugeValue) {

                                rec.hit = false;
                        } else {
                                
                                rec.t        = root;
                                rec.hitPoint = rec.rHit.at(rec.t);
                                rec.normal   = faceForward(Normal3f((rec.hitPoint - c) / r), rec.rHit.direction());
                                rec.hit      = true;
                        }
                }                
        }

}