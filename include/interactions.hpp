#ifndef INTERACTIONS_HPP
#define INTERACTIONS_HPP
#include <general_inc.hpp>
#include <forces.hpp>

template <class TPJ> // Template Particle j
struct CalcColoumbForce {
    void operator () ( const Particle * ip, // Pointer to particle i
                       const PS::S32 ni, // Number of i particles
                       const TPJ * jp, // Pointer to particle j
                       const PS::S32 nj, // Number of j particle
                       LongForce * force) {
        std::cout << "Calculating coloumb force; JK" << std::endl;
    }

};
#endif /* end of include guard: INTERACTIONS_HPP*/
