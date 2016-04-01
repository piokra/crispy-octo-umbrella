#ifndef JOB_H
#define JOB_H


class Job
{
    public:
        Job(unsigned int time);
        void run();
        unsigned GetTime();
    protected:
    private:
        unsigned int mTime;
};

#endif // JOB_H
