#ifndef SCHEDULER_HPP 
#define SCHEDULER_HPP

#include <simgrid/s4u.hpp>
#include "job.hpp"
#include "worker.hpp"

class Scheduler
{
    public:
    std::vector<Worker* > workers;

    explicit Scheduler(std::vector<Worker*> hosts);

    void submitJob(Job* job);
    void checkJob(); //run every second

    private:
    std::vector<Job*> jobQueue;
};

class SchedulerDaemon
{
    public:
    explicit SchedulerDaemon(Scheduler* scheduler) : scheduler(scheduler){};

    void operator()();

    private:
    Scheduler* scheduler;
    void run();
};

#endif