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
        this->scheduler->checkJob();
        sg4::this_actor::sleep_for(1);
    }
}

Scheduler::Scheduler(std::vector<Worker* > hosts)
{
    for(Worker* w : hosts)
    {
        workers.push_back(w);
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
    XBT_INFO("[job was checked remaining: %ld]", this->jobQueue.size());
    if(jobQueue.size() > 0)
    {
        bool isCanAssign = false;
        Job* job = jobQueue[0];

        for(Worker* h : workers)
        {
            if(h->freeProcessor >= job->coreNeed)
            {
                h->exec(job->flops, job->coreNeed);
                isCanAssign = true;
                break;
            }
        }

        if(isCanAssign)
        {
            jobQueue.pop_back();
            XBT_INFO("job wass assigned remaining %ld", this->jobQueue.size());
        }
    }
}
