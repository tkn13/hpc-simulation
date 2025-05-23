#include "header/scheduler.hpp"

namespace sg4 = simgrid::s4u;

XBT_LOG_NEW_DEFAULT_CATEGORY(Scheduler, "log for scheduler");


void SchedulerDaemon::operator()()
{
    sg4::Actor::self()->daemonize();
    run();
}

void SchedulerDaemon::run()
{
    while(true)
    {
        XBT_INFO("[Daemon] check scheduler");
        this->scheduler->checkJob();
        sg4::this_actor::sleep_for(1.0);
    }
}

Scheduler::Scheduler(std::vector<sg4::Host*> hosts)
{
    for(sg4::Host* h : hosts)
    {
        workers.push_back(h);
    }
}

void Scheduler::submitJob(Job* job)
{

    //this section is for scheduler to prioritize to job for simeple will use FIFO
    jobQueue.push_back(job);
    XBT_INFO("[job was add remaining: %ld]", this->jobQueue.size());
}

void Scheduler::checkJob()
{
    XBT_INFO("[job was cheked remaining: %ld]", this->jobQueue.size());
}
