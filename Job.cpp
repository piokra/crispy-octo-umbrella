#include "Job.h"

#include <chrono>
#include <thread>

Job::Job(unsigned int time) : mTime(time)
{
}

void Job::run()
{
    std::this_thread::sleep_for(std::chrono::milliseconds());
}

unsigned Job::GetTime()
{
    return mTime;
}
