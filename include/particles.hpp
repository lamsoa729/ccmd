#ifndef PARTICLES_HPP
#define PARTICLES_HPP
#include <general_inc.hpp>
#include <forces.hpp>

class Particle
{
private:
    PS::F64 mass_, charge_;
    PS::F64vec pos_, vel_, acc_;

public:
    // Class variables
    Particle();
    Particle(PS::F64 mass, PS::F64 charge){
        mass_ = mass;
        charge_ = charge;
    }
    virtual ~Particle() {}


    /* TODO: Add in read binary functionality for restart <02-10-18, ARL> */
    //void readBinary();
    // Get/Set functions
    PS::F64vec getPos() const {return pos_;}
    PS::F64vec getVel() const {return vel_;}
    PS::F64vec getAcc() const {return acc_;}
    PS::F64 getCharge() const {return charge_;}
    PS::F64 getMass() const {return mass_;}
    void setPos(PS::F64vec &in) { pos_ = in;}
    void setVel(PS::F64vec &in) { vel_ = in;}
    void setAcc(PS::F64vec &in) { acc_ = in;}

    void copyFromPtcl(const Particle &in){
        mass_ = in.getMass();
        charge_ = in.getCharge();
        pos_ = in.getPos();
    }

    void copyFromForce(const LongForce &frc){
        acc_ = frc.force / mass_;
    }

    void clear() { acc_ = 0.0; }


};

#endif /* PARTICLES_H */
