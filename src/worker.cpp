#include "header/worker.hpp"

namespace s4u = simgrid::s4u;
XBT_LOG_NEW_DEFAULT_CATEGORY(worker, "log for worker");

Worker::Worker() = default;

void Worker::operator()()
{   
    // std::string hostname = s4u::this_actor::get_host()->get_name();
    // inBox = s4u::Engine::get_instance()->mailbox_by_name_or_create(hostname);
    // XBT_INFO("%s ready for recive message", hostname.c_str());
    // auto message = inBox->get_unique<int>();
    // XBT_INFO("Received message: %d", *message);
}