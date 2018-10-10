#ifndef INTERACTIONS_HPP
#define INTERACTIONS_HPP
#include <general_inc.hpp>
#include <particles.hpp>
#include <forces.hpp>


template <class TPJ> // Template Particle j
class CalcCoulombForce {
    private:
        /* TODO: Actually calculate what K is in dimensionless units <09-10-18, ARL> */
        const PS::F64 k_ = 1.0;

    public:
    void operator () ( const Particle * ep_i, // Array of essential particles i
                       const PS::S32 n_ip, // Number of i particles
                       const TPJ * ep_j, // Array of essential particles j, 
                                       //may be an FDPS super particle
                       const PS::S32 n_jp, // Number of j particles
                       LongForce * em_force){ 
        //PS::F64 k = 1; // Coloumbs constant in dimensionless units
        for (PS::S32 i = 0; i < n_ip; ++i) {
            PS::F64vec xi = ep_i[i].getPos(); // Position of ip
            PS::F64vec ei = 0.0; // Electric field experienced by ip
            PS::F64 poti = 0.0; // Potential energy of ip
            for(PS::S32 j = 0; j < n_jp; j++){
                PS::F64vec rij = xi - ep_j[j].getPos(); // Distance vector between i and j
                PS::F64 r3_inv = rij * rij; // Dot product of distance vector
                PS::F64 r_inv = 1.0/sqrt(r3_inv); // Inverse of separation between i and j
                r3_inv = r_inv * r_inv; // Particle separartion inverse squared
                r_inv *= ep_j[j].getCharge(); // Multiply by charge
                r3_inv *= r_inv;
                ei -= r3_inv * rij; 
                poti -= r_inv; 
            }
            PS::F64 factor = k_*ep_i[i].getCharge(); // Force and potential coefficient
            em_force[i].force += ei*factor; 
            em_force[i].pot += poti*factor;
        }
    }
};

class CalcCoulombTrapForce {
    /* Initialized data memebers */
    private:
        inline static PS::F64 Vo_;
        inline static PS::F64 Vec_;
        inline static PS::F64 ro_;
        inline static PS::F64 zo_;
        inline static PS::F64 Omega_;
        inline static PS::F64 kappa_;
        inline static PS::F64 alpha_; 
        inline static PS::F64 beta_;
        /* TODO: Assert these are reasonable numbers <09-10-18, ARL> */

    public:
    CalcCoulombTrapForce(double Vo, double Vec, double ro, double zo, 
                      double Omega, double kappa);
    CalcCoulombTrapForce() {}
    void CCTFPrint();

    void operator () ( const Particle * ep_i, // Array of essential particles i
                       const PS::S32 n_ip, // Number of i particles
                       const Particle * ep_j, // Array of essential particles j, 
                                       //may be an FDPS super particle
                       const PS::S32 n_jp, // Number of j particles
                       LongForce * trap_force){ 
        for (PS::S32 i = 0; i < n_ip; ++i) {
            PS::F64vec xi = ep_i[i].getPos(); // Position of ip
            PS::F64 m = ep_i[i].getMass(); // Mass of ip
            PS::F64 e = ep_i[i].getMass(); // Charge of ip
            PS::F64vec ei = 0.0; // Electric field experienced by ip
            PS::F64 poti = 0.0; // Potential energy of ip
            ei[0] = (beta_ - (2.*alpha_*e/m))*xi[0]; // Force in the x direction
            ei[1] = (beta_ - (2.*alpha_*e/m))*xi[1]; // Force in the y direction
            ei[2] = -2.0 * beta_* xi[2]; // Force in the z direction
            poti = (alpha_*e/m)*(xi[0]*xi[0] + xi[1]*xi[1]) + 
                beta_*.5*((2.*xi[2]*xi[2]) - (xi[0]*xi[0]) - (xi[1]*xi[1]));

            trap_force[i].force += ei*e; 
            trap_force[i].pot += poti*e;
        }
    }
};

#endif /* end of include guard: INTERACTIONS_HPP*/
