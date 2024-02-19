#ifndef HIT_H

#include "vector.hpp"
#include "Ray.hpp"


class hit_record {
    public:
        point p;
        vector normal;
        double t;

};


class hittable{
    public:
        virtual ~hittable() = default;
        virtual bool hit(const Ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const =0;

};

double hit_sphere(const point& center, double radius, const Ray& r){
    auto a = dot(r.direction(),r.direction());
    auto b = 2.0*dot(r.direction(), r.origin()-center);
    auto c = dot(r.origin() - center, r.origin()-center) - radius*radius;
    auto discriminant = b*b - 4*a*c;
    if (discriminant< 0) return -1.0;
    else return ( - b - sqrt(discriminant)) / (2.0*a);
    

};

class sphere : public hittable{
    public:
        sphere(point _center, double _radius) : center(_center), radius(_radius) {}
        bool hit(const Ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override{

                auto a = dot(r.direction(),r.direction());
                auto b = 2.0*dot(r.direction(), r.origin()-center);
                auto c = dot(r.origin() - center, r.origin()-center) - radius*radius;
                auto discriminant = b*b - 4*a*c;
                if (discriminant< 0) return false;
                auto sqrd = sqrt(discriminant);

                // find t
                auto root = (-b - sqrd) / (2.0*a);

                if (root <= ray_tmin|| ray_tmax<= root){
                    root = (-b+sqrd) / (2.0*a);
                    if (root <= ray_tmin || ray_tmax<= root) return false;
                }
                rec.t=root;
                rec.p = r.at(rec.t);
                rec.normal =(rec.p - center) / radius;

                return true;
    
        }


    private:
        point center;
        double radius;
};
#endif