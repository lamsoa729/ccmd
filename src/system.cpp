#include <system.hpp>
#include <omp.h>
#include <mpi.h>
#include "yaml-cpp/yaml.h"

System::System(){}

/*! \brief Initialize System object using yaml file config_file
 *
 * \param configFile string of path to configuration yaml file
 * \return void
 */
void System::Configure(std::string config_file) {
    YAML::Node config_node = YAML::LoadFile(config_file);
    // Get simulation parameters from configure file
    delta_ = config_node["delta"].as<double>();
    n_steps_ = config_node["n_steps"].as<int>();
    n_posit_ = config_node["n_posit"].as<int>();
    n_ptcl_ = config_node["n_ptcl"].as<int>();
    PS::F64 mass = config_node["mass"].as<PS::F64>();
    PS::F64 charge = config_node["charge"].as<PS::F64>();
    PS::F64 Vo = config_node["Vo"].as<PS::F64>();
    PS::F64 Vec = config_node["Vec"].as<PS::F64>();
    PS::F64 ro_ = config_node["ro"].as<PS::F64>();
    PS::F64 zo_ = config_node["zo"].as<PS::F64>();
    PS::F64 Omega = config_node["Omega"].as<PS::F64>();
    PS::F64 kappa = config_node["kappa"].as<PS::F64>();
    
    GenerateInitialState(mass, charge);

    // Initialize constants for CalcOulombTrapForce objects
    CalcCoulombTrapForce cctp(Vo, Vec, ro_, zo_, Omega, kappa);
    // Initialize FDPS structures
    dinfo_.initialize();
    ptcls_.initialize();
    em_force_tree_.initialize(100);
    // Set up particle system

    /* TODO: Setup particles in random configuration. <05-10-18, ARL> */
    calcCoulombAllAndWriteBack();
}

/*! \brief Randomly place particles in simulation
 *
 *  Detailed description
 *  \param mass Mass of particles
 *  \param charge Charge of particles
 *
 * \return Return parameter description
 */
void System::GenerateInitialState(PS::F64 mass, PS::F64 charge) {
    // Initialize particle system with correct number of particles
    ptcls_.setNumberOfParticleLocal(n_ptcl_);
    for (int i = 0; i < n_ptcl_; ++i) {
        ptcls_[i] = MakeRandomParticle(i, mass, charge);
    }
    
}

/*! \brief Make a particle with random position and velocity
 *
 *  Detailed description
 *
 * \param id ID number of particle
 * \return Initialized Particle object
 */
Particle System::MakeRandomParticle(int id, PS::F64 mass, PS::F64 charge) {
   Particle ptcl(id, mass, charge); 
   const int threadID = 0;
   //const int threadID = omp_get_thread_num();
   // Find a random position inside rectangular cube
   PS::F64vec3 randPos((RngPoolPtr_->getN01(threadID) - .5)*2.*ro_, 
                       (RngPoolPtr_->getN01(threadID) - .5)*2.*ro_,
                       (RngPoolPtr_->getN01(threadID) - .5)*2.*zo_);
   ptcl.setPos(randPos);
   
   return ptcl;
}


/*! \brief Step the simulation forward one delta
 *
 *  Calculate all interactions and integrate equations of motion for one 
 *  delta of simulation time.
 *
 * \return void
 */
void System::stepForward(int i_step) {
    std::cout << "Step " << std::endl;
    // Integration algorithm
    calcCoulombAllAndWriteBack();
    
}

/*! \brief Applies the fast multipole method of the coloumb for to particles
 * in the system
 *
 *  Detailed description
 *
 * \return void
 */
void System::calcCoulombAllAndWriteBack() {
    dinfo_.decomposeDomainAll(ptcls_);
    ptcls_.exchangeParticle(dinfo_);
    em_force_tree_.calcForceAllAndWriteBack(CalcCoulombForce<Particle>(), 
                                  CalcCoulombForce<PS::SPJMonopole>(),
                                  ptcls_,
                                  dinfo_);
    trap_force_tree_.calcForceAllAndWriteBack(CalcCoulombTrapForce(),
                                              ptcls_,
                                              dinfo_);
}

