#ifndef FIFONODE_H
#define FIFONODE_H

#include "Job.h"
class FIFONode
{
    public:
        FIFONode(Job element, FIFONode* previous);
        virtual ~FIFONode();
        FIFONode* GetNext() { return mNext; }
        void SetNext(FIFONode* val) { mNext = val; }
        Job GetElement() { return mElement; }
        void SetElement(Job val) { mElement = val; }
    protected:
    private:
        FIFONode* mNext;
        Job mElement;
};

#endif // FIFONODE_H
