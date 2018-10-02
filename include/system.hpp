#ifndef SYSTEM_H
#define SYSTEM_H
#include <general_inc.hpp>

class System
{
private:
    // Configurations file
    int delta_;
    int n_steps_;
    int n_posit_;
    

public:
    System();
    virtual ~System() {};

    void Configure(std::string config_file);

    void stepForward();
    
    int getTotalSteps(){ return n_steps_; }
};

#endif /* SYSTEM_H */
