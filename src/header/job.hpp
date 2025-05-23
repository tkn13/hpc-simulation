#ifndef JOB_HPP 
#define JOB_HPP


class Job
{
    public:
    double flops;
    int workerNeed;
    int coreNeed;

    explicit Job(double f, int w, int c) : flops(f), workerNeed(w), coreNeed(c){};
};

#endif