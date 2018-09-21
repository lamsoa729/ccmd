#ifndef PARTICLES_HPP
#define PARTICLES_HPP
#include <general_inc.hpp>

class Particle
{
private:
    PS::F64 _mass, _charge;
    PS::F64vec _pos, _vel, _acc;

public:
    // Class variables
    Particle();
    virtual ~Particle();

    // Get/Set functions
    PS::F64vec getPos() const {return _pos;}
    PS::F64vec getVel() const {return _vel;}
    PS::F64vec getAcc() const {return _acc;}
    PS::F64 getCharge() const {return _charge;}
    PS::F64 getMass() const {return _mass;}
    void setPos(PS::F64vec &in) { _pos = in;}
    void setVel(PS::F64vec &in) { _vel = in;}
    void setAcc(PS::F64vec &in) { _acc = in;}

    void copyFromPtcl(const Particle &in){
        _mass = in.getMass();
        _charge = in.getCharge();
        _pos = in.getPos();
    }
};

#endif /* PARTICLES_H */
