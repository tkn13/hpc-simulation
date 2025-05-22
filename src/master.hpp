#ifndef MASTER_HPP
#define MASTER_HPP

#include <simgrid/s4u.hpp>
#include <vector>
#include <string>

class Master
{
    public:

    explicit Master();
    explicit Master(std::vector<simgrid::s4u::Host*> args);

    void operator()();

    private:
        std::vector<simgrid::s4u::Host*> hostList;
        simgrid::s4u::Mailbox* inBox;
        simgrid::s4u::Mailbox* outBox;
        void ping();


};

#endif