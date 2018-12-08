#include <particles.hpp>

Particle::Particle() {}

TEST_CASE( "Test MockParticle function", "[mock_particle]"){
    //Arrange
    Particle ptcl;
    //Act
    ptcl.MockParticle(0);
    //Assert
    PS::F64vec3 vec000 = {0,0,0};
    PS::F64vec3 vec100 = {1,0,0};
    CHECK(ptcl.getID() == 0);
    CHECK(ptcl.getMass() == 1.); 
    CHECK(ptcl.getCharge() == 1.);
    CHECK(ptcl.getPos() == vec000);
    CHECK(ptcl.getVel() == vec100);
    CHECK(ptcl.getAcc() == vec000);
}

