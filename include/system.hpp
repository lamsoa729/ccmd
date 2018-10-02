#ifndef SYSTEM_H
#define SYSTEM_H
#include <general_inc.hpp>
#include <particles.hpp>

class System
{
private:
    double delta_;
    int n_steps_;
    int n_posit_;

    PS::DomainInfo dinfo_;

    PS::ParticleSystem<Particle> ptcls_;

    PS::TreeForForceLong<LongForce, Particle, Particle>::Quadrupole em_force;
    
public:
    System();
    virtual ~System() {PS::Finalize();}

    void Configure(std::string config_file);

    void stepForward();
    
    int getTotalSteps(){ return n_steps_; }
};

#endif /* SYSTEM_H */
