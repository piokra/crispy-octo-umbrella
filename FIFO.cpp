#include "FIFO.h"
#include "FIFONode.h"
FIFO::FIFO() : mRoot(0), mLast(0)
{
    //ctor
}

FIFO::~FIFO()
{
    //dtor
}
void FIFO::enqueue(Job element)
{
    FIFONode* node = new FIFONode(element,mLast);
    if(mLast)
    {
        mLast->SetNext(node);
        mLast = node;
    }
    else
    {
        mRoot = node;
        mLast = node;

    }
}

FIFONode* FIFO::dequeue()
{
    FIFONode* ret = mRoot;
    if(ret)
    {
        if(mLast==ret)
        {
            mLast = 0;
            mRoot = 0;
        }
        else
        {
            mRoot = ret->GetNext();
        }
    }
    return ret;
}
void FIFO::ForEach(ForFunction f)
{
    int i = 0;
    FIFONode* el = mRoot;
    while(el)
    {
        f(el,i);
        i++;
        el = el->GetNext();
    }
}
