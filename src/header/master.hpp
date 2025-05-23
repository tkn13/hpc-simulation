#ifndef MASTER_HPP
#define MASTER_HPP

#include <simgrid/s4u.hpp>
#include <vector>
#include <string>

#include "scheduler.hpp"

class Master
{
    public:

    explicit Master();
    explicit Master(std::vector<simgrid::s4u::Host*> hosts, Scheduler* scheduler);

    void operator()();

    private:
        Scheduler* scheduler;
        std::vector<simgrid::s4u::Host*> hostList;
        simgrid::s4u::Mailbox* inBox;
        simgrid::s4u::Mailbox* outBox;
        void ping();


};

#endif