#ifndef RAY_H
#define RAY_H

#include "vector.hpp"

class Ray{

    public:
        Ray() {}
        Ray(const point& origin, const vector& direction): orig(origin), dir(direction) {}
        //we should also have the getters:
        point origin() const {return orig;}
        vector direction() const {return dir; }
        //for the traversing of the scene
        point at(double t) const {
            return orig + dir*t;
        }
    private:
        point orig;
        vector dir;

};

#endif