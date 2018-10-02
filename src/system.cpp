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

    //delta_ = config_node["delta"].as<int>();
    //n_steps_ = config_node["n_steps"].as<int>();
    //n_posit_ = config_node["n_posit"].as<int>();
}

/*! \brief Step the simulation forward one delta
 *
 *  Calculate all interactions and integrate equations of motion for one 
 *  delta of simulation time.
 *
 * \return void
 */
void System::stepForward() {
    
}
