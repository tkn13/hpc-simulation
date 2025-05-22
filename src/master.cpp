#include "master.hpp"

namespace s4u = simgrid::s4u;
XBT_LOG_NEW_DEFAULT_CATEGORY(master, "log for master");

Master::Master() = default;

Master::Master(std::vector<s4u::Host*> args)
{
    for(s4u::Host* h : args)
    {
        hostList.push_back(h);
    }
}

void Master::operator()()
{
    ping();
}

void Master::ping()
{
    
    int size = hostList.size();
    for (int i = 0; i < size; i++) {
        int* payload = new int(1);
        outBox = simgrid::s4u::Engine::get_instance()->mailbox_by_name_or_create(hostList[i]->get_cname());
        XBT_INFO("[sending...]send data message to mailbox: %s", hostList[i]->get_cname());
        outBox->put(payload, sizeof(int));
        XBT_INFO("[sent]send data message to mailbox: %s", hostList[i]->get_cname());

    }
}
