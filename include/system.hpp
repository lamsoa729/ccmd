#ifndef SYSTEM_H
#define SYSTEM_H
#include <general_inc.hpp>
#include <particles.hpp>
#include <forces.hpp>
#include <interactions.hpp>

class System
{
private:
    double delta_; // Time step in simulation units
    int n_steps_; // Number of steps in simulation
    int n_posit_; // Number of steps between writing system state
    int n_dcomp_;  // Number of steps between domain decomposition
    int n_ptcl_; // Number of particles

    std::shared_ptr<TRngPool> RngPoolPtr_;

    PS::DomainInfo dinfo_;

    PS::ParticleSystem<Particle> ptcls_;

    PS::TreeForForceLong<LongForce, Particle, Particle>::Monopole em_force_tree_;

    PS::TreeForForceLong<LongForce, Particle, Particle>::Monopole trap_force_tree_;
    
public:
    System();
    virtual ~System() {}

    void Configure(std::string config_file);

    void GenerateInitialState();

    void stepForward(int i_step);

    void calcCoulombAllAndWriteBack();
    
    int getTotalSteps(){ return n_steps_; }
};

#endif /* SYSTEM_H */
