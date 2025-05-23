#include "header/worker.hpp"

namespace sg4 = simgrid::s4u;
XBT_LOG_NEW_DEFAULT_CATEGORY(worker, "log for worker");

Worker::Worker()
{
    currentState = Idle;
    MAX_PROCESSOR = 16;

};

State Worker::getState()
{
    return currentState;
}

void Worker::run()
{
    while (true)
    {
        sg4::this_actor::sleep_for(0.1);
    }
    
}

void Worker::exec(double flops, int processor)
{

  if(processor > freeProcessor)
  {
    XBT_ERROR("scheuler assign job to worker that limt the processor");
    return;
  }

    freeProcessor -= processor;
    runningProcessor += processor;
    sg4::ExecPtr activity = sg4::this_actor::exec_init(flops);
    activity->start();
    XBT_INFO("exec job");
}

void Worker::operator()()
{   
    sg4::Actor::self()->daemonize();
    XBT_INFO("Woker was daemonize");
    run();
}