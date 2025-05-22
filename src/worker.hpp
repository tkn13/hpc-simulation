#ifndef WORKER_HPP
#define WORKER_HPP

#include <simgrid/s4u.hpp>

class Worker
{
    public:
    explicit Worker();

    void operator()();

    private:
    simgrid::s4u::Mailbox* inBox;
};

#endif