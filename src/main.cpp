#include <simgrid/s4u.hpp>

#include "header/job.hpp"
#include "header/master.hpp"
#include "header/worker.hpp"
#include "header/scheduler.hpp"

namespace sg4 = simgrid::s4u;

XBT_LOG_NEW_DEFAULT_CATEGORY(main, "log for main");

int main(int argc, char* argv[])
{
    sg4::Engine e(&argc, argv);
    e.load_platform(argv[1]);
    
    std::vector<sg4::Host*> hosts = e.get_all_hosts();
    std::vector<Worker*> workers;
    //delete first elemenst as a master node
    hosts.erase(hosts.begin());
    //delete second elemenst for daemon node
    hosts.erase(hosts.begin());

    for(int i = 0; i < hosts.size(); i++)
    {
        std::string hostname = "node-" + std::to_string(i+1) + ".science.kmitl.ac.th";

        Worker* temp = new Worker();

        sg4::Actor::create("worker", e.host_by_name(hostname), *temp);
        workers.push_back(temp);
    }

    Scheduler* scheduler = new Scheduler(workers);
    SchedulerDaemon* daemon = new SchedulerDaemon(scheduler);
    sg4::Actor::create("daemon", e.host_by_name("node-1.science.kmitl.ac.th"), *daemon);
    sg4::Actor::create("master", e.host_by_name("node-0.science.kmitl.ac.th"), Master(hosts, scheduler));


    e.run();
    return 0;
}
