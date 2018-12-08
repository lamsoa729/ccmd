#include "interactions.hpp"
#include "catch.hpp"

CalcCoulombTrapForce::CalcCoulombTrapForce(PS::F64 Vo, PS::F64 Vec, 
                                           PS::F64 ro, PS::F64 zo, 
                                           PS::F64 Omega, PS::F64 kappa){
    Vo_ = Vo;
    Vec_ = Vec;
    ro_ = ro;
    zo_ = zo;
    Omega_ = Omega;
    kappa_ = kappa;
    alpha_ = Vo_*Vo_/(Omega_*Omega_*ro_*ro_*ro_*ro_);
    beta_ = Vec_*kappa_/(zo_*zo_);
}

void CalcCoulombTrapForce::CCTFPrint(){
    std::cout << "Vo "<< Vo_ << std::endl;
    std::cout << "Vec "<< Vec_ << std::endl;
    std::cout << "ro "<< ro_ << std::endl;
    std::cout << "zo "<< zo_ << std::endl;
    std::cout << "Omega " << Omega_ <<std::endl;
    std::cout << "kappa " << kappa_ <<std::endl;
}

TEST_CASE( "Trap forces are computed", "[trap]" ) {
    CalcCoulombTrapForce trap(1, 1, 1, 1, 1, 1);
    Particle ptcl;
    ptcl.MockParticle(0);
    LongForce frc;
    frc.clear();
    CHECK( trap.getOmega() == 1);
    CHECK( trap.getAlpha() == 1);
    CHECK( trap.getBeta() == 1);

    SECTION( "Particle in the center of trap at time 0" ){
        trap = CalcCoulombTrapForce(2,1,1,1,1,1);
        CHECK( trap.getAlpha() == 4);
        PS::F64 pot = trap.ptclPot(ptcl, frc.force);
        CHECK(pot == 0);
    }
    SECTION( "Particle displaced in z direction of trap at time 0" ){
        auto trap1 = CalcCoulombTrapForce(2,1,1,1,1,1);
        PS::F64vec3 pos = {0, 0, .1};
        ptcl.setPos(pos);
        CHECK( trap.getAlpha() == 4);
        PS::F64 pot = trap.ptclPot(ptcl, frc.force);
        CHECK(ABS(pot - 0.01) < SMALL);
    }
    SECTION( "Particle displaced in x direction of trap at time 0" ){
        auto trap1 = CalcCoulombTrapForce(2,1,1,1,1,1);
        PS::F64vec3 pos = {0.1, 0, 0};
        ptcl.setPos(pos);
        CHECK( trap.getAlpha() == 4);
        PS::F64 pot = trap.ptclPot(ptcl, frc.force);
        CHECK(ABS(pot - 0.035) < SMALL);
    }
}

 /*! \brief Applies the fast multipole method of the coloumb force to particles
  * in the system ptcls
  *
  *  Detailed description
  *
  * \param dinfo templated domain info (TDI) object
  * \param ptcls templated particle system (PDS) object
  * \param tree templated tree for force (TTFF) object
  * \return void
  */
//template<class TDI, class TPS, class TTFF>
//void calcCoulombAllAndWriteBack(TDI &dinfo, TPS &ptcls, TTFF &tree) {
//    [> TODO: Set how often domain will be decomposed <05-10-18, ARL> <]
//    dinfo.decomposeDomainAll(ptcls);
//    ptcls.exchangeParticle(dinfo);
//    tree.calcForceAllAndWriteBack(CalcCoulombForce<Particle>(), 
//                                  CalcCoulombForce<PS::SPJMonopole>(),
//                                  ptcls,
//                                  dinfo);
//}


