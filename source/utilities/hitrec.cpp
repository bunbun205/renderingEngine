#include <hitrec.hpp>

HitRecord::HitRecord(const World &wr) :

        hit(false),
        normal(),
        matPtr(NULL),
        hitPoint(),
        rHit(),
        depth(0),
        t(0.0),
        w(wr) { }

HitRecord::HitRecord(const HitRecord &hitrec):

        hit(hitrec.hit),
        matPtr(hitrec.matPtr),
        hitPoint(hitrec.hitPoint),
        normal(hitrec.normal),
        rHit(hitrec.rHit),
        depth(hitrec.depth),
        t(hitrec.t),
        w(hitrec.w) { }