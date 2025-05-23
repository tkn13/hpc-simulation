#include "header/master.hpp"

namespace sg4 = simgrid::s4u;
XBT_LOG_NEW_DEFAULT_CATEGORY(master, "log for master");

Master::Master() = default;

Master::Master(std::vector<sg4::Host*> hosts, Scheduler* sche): scheduler(sche)
{
    for(sg4::Host* h : hosts)
    {
        hostList.push_back(h);
    }
}

void Master::operator()()
{
    XBT_INFO("master start");
    for(int i = 0; i < 10; i++)
    {
        sg4::this_actor::sleep_for(1);

        //add job when 2 second has passed
        if(i == 2)
        {   
            XBT_INFO("master sending job");
            Job* j = new Job(10.0, 1, 1);
            scheduler->submitJob(j);
            XBT_INFO("master sent job");
        }
    }
    XBT_INFO("master end");
}