#include "interactions.hpp"

CalcCoulombTrapForce::CalcCoulombTrapForce(PS::F64 Vo, PS::F64 Vec, 
                                           PS::F64 ro, PS::F64 zo, 
                                           PS::F64 Omega, PS::F64 kappa){
    Vo_ = Vo;
    Vec_ = Vec;
    ro_ = ro;
    zo_ = zo;
    Omega_ = Omega;
    kappa_ = kappa;
}

void CalcCoulombTrapForce::CCTFPrint(){
    std::cout << "Vo "<< Vo_ << std::endl;
    std::cout << "Vec "<< Vec_ << std::endl;
    std::cout << "ro "<< ro_ << std::endl;
    std::cout << "zo "<< zo_ << std::endl;
    std::cout << "Omega " << Omega_ <<std::endl;
    std::cout << "kappa " << kappa_ <<std::endl;
}

//template <class TPJ>
//void CalcCoulombForce<TPJ>::operator () ( 
//                       const Particle * ep_i, // Array of essential particles i
//                       const PS::S32 n_ip, // Number of i particles
//                       const TPJ * ep_j, // Array of essential particles j, 
//                                       //may be an FDPS super particle
//                       const PS::S32 n_jp, // Number of j particles
//                       LongForce * em_force) {
//    PS::F64 k = 1; // Coloumbs constant in dimensionless units
//    for (PS::S32 i = 0; i < n_ip; ++i) {
//        PS::F64vec xi = ep_i[i].getPos(); // Position of ip
//        PS::F64vec ei = 0.0; // Electric field experienced by ip
//        PS::F64 poti = 0.0; // Potential energy of ip
//        for(PS::S32 j = 0; j < n_jp; j++){
//            PS::F64vec rij = xi - ep_j[j].getPos(); // Distance vector between i and j
//            PS::F64 r3_inv = rij * rij; // Dot product of distance vector
//            PS::F64 r_inv = 1.0/sqrt(r3_inv); // Inverse of separation between i and j
//            r3_inv = r_inv * r_inv; // Particle separartion inverse squared
//            r_inv *= ep_j[j].getCharge(); // Multiply by charge
//            r3_inv *= r_inv;
//            ei -= r3_inv * rij; 
//            poti -= r_inv; 
//        }
//        PS::F64 factor = k*ep_i[i].getCharge(); // Force and potential coefficient
//        em_force[i].force += ei*factor; 
//        em_force[i].pot += poti*factor;
//    }
//}

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


