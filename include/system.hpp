#ifndef SYSTEM_H
#define SYSTEM_H
#include <general_inc.hpp>
#include <particles.hpp>
#include <forces.hpp>
#include <interactions.hpp>

class System
{
private:
    double delta_;
    int n_steps_;
    int n_posit_;
    int n_dcomp_; 

    PS::DomainInfo dinfo_;

    PS::ParticleSystem<Particle> ptcls_;

    PS::TreeForForceLong<LongForce, Particle, Particle>::Monopole em_force_tree_;

    PS::TreeForForceLong<LongForce, Particle, Particle>::Monopole trap_force_tree_;
    
public:
    System();
    virtual ~System() {}

    void Configure(std::string config_file);

    void stepForward(int i_step);

    void calcCoulombAllAndWriteBack();
    
    int getTotalSteps(){ return n_steps_; }
};

#endif /* SYSTEM_H */
