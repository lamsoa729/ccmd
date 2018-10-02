#include <system.hpp>
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
    // Initialize FDPS structures
    dinfo_.initialize();
    ptcls_.initialize();



}

/*! \brief Step the simulation forward one delta
 *
 *  Calculate all interactions and integrate equations of motion for one 
 *  delta of simulation time.
 *
 * \return void
 */
void System::stepForward() {
    std::cout << "Step " << std::endl;
}
