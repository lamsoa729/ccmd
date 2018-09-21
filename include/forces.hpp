#ifndef FORCES_H
#define FORCES_H
#include <general_inc.hpp>

class LongForce // Long range force class such as coloumb or grav forces
{
public:
    PS::F64vec3 _force;
    PS::F64 sepmin; // Minimum seperation

    void clear() { 
        _force = 0;
        sepmin = std::numeric_limits<double>::max();
    }
    LongForce();
    virtual ~LongForce();
};

#endif /* FORCES_H */