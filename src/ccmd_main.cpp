// Test function
//#include <general_inc.hpp>
#include <particles.hpp>
#include <system.hpp>

int main(int argc, char *argv[])
{
    // Setup
    System sim_system;
    sim_system.Configure("ccmd.config.yaml");
    // Main loop
    int i_step = 0;
    while (i_step < sim_system.getTotalSteps()) {
        sim_system.stepForward(i_step);
        i_step++;
    }
    return 0;

}
