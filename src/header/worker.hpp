#ifndef WORKER_HPP
#define WORKER_HPP

#include <simgrid/s4u.hpp>


enum State
{
    Idle,
    running,
    full,
    suspend,
    shutdown
};
class Worker
{
    public:
    explicit Worker();

    int MAX_PROCESSOR;
    int freeProcessor;
    int runningProcessor;

    void exec(double flops, int processor);
    State getState();

    void operator()();

    private:
    simgrid::s4u::Mailbox* inBox;
    State currentState;

    void run();
};

#endif