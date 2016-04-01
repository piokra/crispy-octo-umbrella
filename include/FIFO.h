#ifndef FIFO_H
#define FIFO_H


class FIFONode;
class Job;

using ForFunction = void(*)(FIFONode*,int);

class FIFO
{
    public:

        FIFO();
        ~FIFO();

        void enqueue(Job element);
        FIFONode* dequeue();
        void ForEach(ForFunction f);

    protected:
    private:
        FIFONode* mRoot;
        FIFONode* mLast;
};

#endif // FIFO_H
